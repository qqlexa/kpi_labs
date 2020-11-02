import os
import sqlite3
from colorama import Fore
import re

tables_path = os.path.dirname(__file__) + "/tables/"
database_name = "elements_limits.db"
objects_file = "objects.txt"

conn = sqlite3.connect(tables_path + database_name)
cursor = conn.cursor()


def get_sql(sql):
    cursor.execute(sql)
    _parameters = cursor.fetchone()
    conn.commit()
    return _parameters


def enter_parameters(_selected_type):
    _emission = input("Введіть кількість викидів (у тонах): ")
    while True:
        try:
            _emission = float(_emission)
            break
        except:
            _emission = input("Спробуйте ввести кількість викидів ще раз: ")
    _coefficient = 1

    if "b" in _selected_type:
        _user_input = input("Викиди йдуть у річку/озеро?(Yes / No): ")
        if "yes" in _user_input.lower():
            _coefficient *= 1.5

    elif "c" in _selected_type:
        _user_input = input("Знаходиться поблизу (до 3 км) населеного пункту?(Yes / No): ")
        if "yes" in _user_input.lower():
            _coefficient *= 3

        _user_input = input("Звалище неізольоване?(Yes / No): ")
        if "yes" in _user_input.lower():
            _coefficient *= 3

    return _emission, _coefficient


def get_danger_class(_element_name=""):
    while True:
        print(f"Введіть клас небезпеки речовини {_element_name} (1-4)")
        _danger_class = input()
        try:
            _danger_class = int(_danger_class)
            if _danger_class == 4:
                _danger_class = "IV"
                break
            elif 0 < _danger_class < 4:
                _danger_class = "I" * _danger_class
                break
            else:
                print("Введіть знову")
        except:
            print("Error")
    return _danger_class


class Tax:
    def __init__(self, _element_name, _tax, _emissions):
        self.element_name = _element_name
        self.tax = _tax
        self.emissions = _emissions

    def count(self, _coefficient=1):
        return round(self.emissions * self.tax * _coefficient, 2)


class Factory:
    def __init__(self, name):
        self.name = name
        self.elements = []
        self.tax = 0

    def add_element(self, element_name, element_value):
        value = float(re.findall(r'[0-9]*[.,]?[0-9]+', element_value)[0])
        value *= (10**6) / (365 * 24)  # transform to gram/hour

        # зробити запит до БД
        parameters = get_sql(""" SELECT * FROM "{table}"
        WHERE "Назва речовини" LIKE "%{name_element}%" """.format(name_element=element_name, table="elements"))

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


impost = 0
is_selected_type = False
while True:
    print("""Виберіть тип розрахунку податку за: 
    a. викидами у атмосферне повітря
    b. викидами у водні об'єкти
    c. за розміщенням відходів
    d. утворенням радіоактивних відходів
    e. зберіганням радіоактивних відходів 
    0. вийти
    """)
    selected_type = input()

    if "a" in selected_type or "b" in selected_type or "c" in selected_type\
            or "d" in selected_type or "e" in selected_type:
        is_selected_type = True
    elif "0" in selected_type:
        print("Exit")
        break
    else:
        print("Input again")

    if is_selected_type:
        is_selected_type = False
        # Ввід з файлу
        type_input = input("Виберіть тип вводу:\n1 - з файлу\n0 - з клавіатури?\n>> ")
        if "1" in type_input:
            with open(objects_file, "rt", encoding="utf-8") as f:
                factory_name = ""
                is_factory_selected = False
                element_info = []  # [element_name, element_value]

                for i in f.readlines():
                    if not is_factory_selected:
                        temp_factory = Factory(i.replace("\n", ""))
                        is_factory_selected = True
                        impost = 0
                        continue

                    if "$" in i:
                        is_factory_selected = False
                        # temp_factory.print_elements()
                        print(f"Загальний податок {temp_factory.name}: {impost} грн")
                        print()
                        continue

                    if len(element_info) > 1:
                        temp_factory.add_element(element_info[0], element_info[1])
                        # знайти tax [0] - name, [1] - маса викидів

                        parameters = get_sql(""" SELECT * FROM "{table}"
                        WHERE "Назва речовини" LIKE "%{name_element}%" """.format(name_element=element_info[0],
                                                                                  table="elements"))
                        element_name = element_info[0]
                        emission = float(re.findall(r'[0-9]*[.,]?[0-9]+', element_info[1])[0])
                        if parameters[5]:
                            tax = parameters[5]
                        else:
                            parameters = get_sql(""" SELECT * FROM "{table}" 
                            WHERE "Клас небезпечності" = "{danger_class}" """.format(danger_class=parameters[0],
                                                                                     table="taxes2"))
                            tax = parameters[1]

                        result = Tax(element_name, tax, emission).count()
                        impost += result
                        print(f"Податок речовини {element_name}: {result} грн")

                        element_info = list()

                    element_info.append(i.replace("\n", ""))

            continue

        print("Введіть речовину")
        element_name = input()
        # Консоль
        if not element_name:
            continue

        if "a" in selected_type:
            parameters = get_sql(""" SELECT * FROM "{table}"
            WHERE "Назва речовини" LIKE "%{name_element}%" """.format(name_element=element_name, table="elements"))

            if parameters:
                print(parameters)
                print("Хочете використовувати дані цієї речовини? (Yes / No)")
                user_input = input()
                if "yes" in user_input.lower():
                    print(f"Да, хоче використовувати дані речовини {element_name}")
                    tax = parameters[5]
                    if not tax:
                        parameters = get_sql(""" SELECT * FROM "{table}" 
                        WHERE "Клас небезпечності" = "{danger_class}" """.format(danger_class=parameters[0],
                                                                                 table="taxes2"))
                        print(parameters)
                        tax = parameters[1]
                else:
                    parameters = get_sql(""" SELECT * FROM "{table}" 
                    WHERE "Клас небезпечності" = "{danger_class}" """.format(danger_class=parameters[0],
                                                                             table="taxes2"))
                    print(parameters)
                    tax = parameters[1]
            else:
                danger_class = get_danger_class(element_name)
                parameters = get_sql(""" SELECT * FROM "{table}" 
                WHERE "Клас небезпечності" = "{danger_class}" """.format(danger_class=danger_class,
                                                                         table="taxes2"))
                print(parameters)
                tax = parameters[1]

            print(f"Податок для речовини {element_name} - {tax} гривень за тону")
            emission, coefficient = enter_parameters(selected_type)
            impost = Tax(element_name, tax, emission).count(coefficient)
            print("Загальний податок: {}".format(impost))

        elif "b" in selected_type:
            parameters = get_sql(""" SELECT * FROM "{table}"
            WHERE "Назва речовини" LIKE "%{name_element}%" """.format(name_element=element_name, table="taxes4"))
            tax = 0

            if parameters:
                print(parameters)
                print("Хочете використовувати дані цієї речовини? (Yes / No)")
                user_input = input()
                if "yes" in user_input.lower():
                    print(f"Да, хоче використовувати дані речовини {element_name}")
                    tax = parameters[1]

            if not tax:
                emission_limit = input("Введіть ГДК речовини мг/дм^3: ")
                while True:
                    try:
                        emission_limit = float(emission_limit)
                        break
                    except:
                        emission_limit = input("Спробуйте знову ввести ГДК речовини мг/дм^3: ")

                sql_request = """ SELECT * FROM "{table}" """.format(
                    name_element=element_name, table="taxes3")
                # print(sql_request)
                cursor.execute(sql_request)

                max_emission = 0
                while emission_limit >= float(max_emission):
                    parameters = cursor.fetchone()
                    conn.commit()
                    max_emission_index = parameters[0].index("-")
                    max_emission = ""
                    for i in range(max_emission_index + 2, len(parameters[0])):
                        max_emission += parameters[0][i]
                    max_emission = float(max_emission)
                parameters = get_sql(""" SELECT * FROM "{table}" 
                WHERE "ГДК міліграмів на 1 літр" = "{max_emission}" """.format(
                    max_emission=parameters[0], table="taxes3"))

                print(parameters)
                tax = float(parameters[1])

            print(f"Податок для речовини {element_name} - {tax} гривень за тону")
            emission, coefficient = enter_parameters(selected_type)
            impost = Tax(element_name, tax, emission).count(coefficient)
            print(f"Загальний податок: {impost}")

        elif "c" in selected_type:
            parameters = get_sql(""" SELECT * FROM "{table}"
            WHERE "Назва речовини" LIKE "%{name_element}%" """.format(name_element=element_name, table="elements"))

            if parameters:
                print(parameters)
                danger_class = parameters[0]
            else:
                danger_class = get_danger_class(element_name)
                # відкрити taxes2, перший стовбець

            parameters = get_sql(""" SELECT * FROM "{table}" 
                                WHERE "Клас небезпечності" = "{danger_class}" """.format(danger_class=danger_class,
                                                                                         table="taxes2"))
            print(parameters)
            tax = parameters[2]

            print(f"Податок для речовини {element_name} - {tax} гривень за тону")
            emission, coefficient = enter_parameters(selected_type)
            impost = Tax(element_name, tax, emission).count(coefficient)
            print(f"Загальний податок: {impost}")

        elif "d" in selected_type:
            print("In progress")

        elif "e" in selected_type:
            activity = input(f"{element_name} високоактивний (інакше середньо/низько активне)?(Yes / No): ")
            if "yes" in activity.lower():
                activity = "Високоактивні"
            else:
                activity = "Середньоактивні та низькоактивні"

            parameters = get_sql(""" SELECT * FROM "{table}" 
            WHERE "Категорія відходів" = "{activity}" """.format(activity=activity, table="taxes1"))

            is_source = input(f"{element_name} Включають у себе речовини що є джерелом іонізуючого випромінення? "
                              f"(інакше не включають)?(Yes / No): ")

            if "yes" in is_source.lower():
                tax = parameters[3]
            else:
                tax = parameters[2]

            print(f"Податок для речовини {element_name} - {tax} гривень за см^3")
            emission = input("Введіть кількість зберігання речовини у см^3: ")
            while True:
                try:
                    emission = float(emission)
                    break
                except:
                    emission = input("Спробуйте ввести кількість зберігання ще раз: ")

            impost = Tax(element_name, tax, emission).count(4)
            print(f"Загальний податок: {impost}")

cursor.close()
conn.close()
