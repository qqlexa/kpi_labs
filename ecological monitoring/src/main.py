import os
import sys
import sqlite3
import time
from colorama import Fore
import regex
import re

tables_path = os.path.dirname(__file__) + "/tables/"

conn = sqlite3.connect(tables_path + "tables_test.db")
cursor = conn.cursor()

# зробити запит до БД
sql_request = """ SELECT * FROM table1 WHERE "Назва речовини" LIKE "%суспендованих%" """

cursor.execute(sql_request)
parameters = cursor.fetchone()
conn.commit()

print(parameters)

cursor.close()
conn.close()


class Factory:
    def __init__(self, name):
        self.name = name
        self.elements = []

    def add_element(self, element_name, element_value):
        """
        new_string = re.findall(r'[0-9]*[.,]?[0-9]+', "  від 100 г/год до 2000 г/год   ")
        print(new_string)

        for p in new_string:
            print(p)
        if len(new_string) > 1:
            values = []
            for p in new_string:
                values.append(float(p))
            max_value = max(values)
        else:
            max_value = float(new_string[0])
        print(max_value)
        """
        print(element_value)
        value = float(re.findall(r'[0-9]*[.,]?[0-9]+', element_value)[0])
        print(value)
        value *= (10**6) / (365 * 24)  # transform to gram/hour
        print(value)
        self.elements.append(list([element_name, round(value, 3)]))

    def print_elements(self):
        for p in self.elements:
            print(p)

    def get_name(self):
        return self.name

    def set_name(self, name):
        self.name = name


with open("factory.txt", "rt", encoding="utf-8") as f:
    factory_name = ""
    is_factory_selected = False
    element_info = []

    for i in f.readlines():
        if not is_factory_selected:
            temp_factory = Factory(i.replace("\n", ""))
            is_factory_selected = True

            print(f"\nВибраний об'єкт - {temp_factory.name}")

            continue

        if "$" in i:
            is_factory_selected = False
            temp_factory.print_elements()
            continue

        if len(element_info) < 2:
            element_info.append(i.replace("\n", ""))
        else:
            temp_factory.add_element(element_info[0], element_info[1])
            element_info = list()
            element_info.append(i.replace("\n", ""))
