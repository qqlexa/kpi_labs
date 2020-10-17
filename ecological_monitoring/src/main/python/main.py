import os
import sqlite3
from colorama import Fore
import re

tables_path = os.path.dirname(__file__) + "/tables/"
database_name = "elements_limits.db"
objects_file = "objects.txt"

conn = sqlite3.connect(tables_path + database_name)
cursor = conn.cursor()


class Factory:
    def __init__(self, name):
        self.name = name
        self.elements = []

    def add_element(self, element_name, element_value):
        value = float(re.findall(r'[0-9]*[.,]?[0-9]+', element_value)[0])
        value *= (10**6) / (365 * 24)  # transform to gram/hour

        # зробити запит до БД
        sql_request = """ SELECT * FROM "{table}"
        WHERE "Назва речовини" LIKE "%{name_element}%" """.format(name_element=element_name, table="table")
        # print(sql_request)
        cursor.execute(sql_request)
        parameters = cursor.fetchone()
        conn.commit()

        # parameters is tuple from 4 elements: "Клас речовини", "Назва речовини", "ВМВ", "ГДК"
        if len(parameters) > 0:
            available_line = re.findall(r'[0-9]*[.,]?[0-9]+', parameters[2])

            if len(available_line) > 1:
                values = []
                for p in available_line:
                    values.append(float(p))
                max_value = max(values)
            else:
                max_value = float(available_line[0])

            self.elements.append(list([element_name, round(value, 3), max_value]))
        else:
            print("There is not the value {name} in database".format(name=element_name))

    def print_elements(self):
        print(Fore.MAGENTA + self.name + Fore.RESET)
        for p in self.elements:
            print(p[0], end=" ")
            color = Fore.GREEN if p[1] < p[2] else Fore.RED
            print(color + str(p[1]) + "г\\год " + Fore.RESET, end=" ")
            print(str(p[2]) + "г\\год ", end=" ")
            if p[1] > p[2]:
                print(str(p[1] - p[2]))
            else:
                print()
        print()


with open(objects_file, "rt", encoding="utf-8") as f:
    factory_name = ""
    is_factory_selected = False
    element_info = []  # [element_name, element_value]

    for i in f.readlines():
        if not is_factory_selected:
            temp_factory = Factory(i.replace("\n", ""))
            is_factory_selected = True
            continue

        if "$" in i:
            is_factory_selected = False
            temp_factory.print_elements()
            continue

        if len(element_info) > 1:
            temp_factory.add_element(element_info[0], element_info[1])
            element_info = list()

        element_info.append(i.replace("\n", ""))

cursor.close()
conn.close()
