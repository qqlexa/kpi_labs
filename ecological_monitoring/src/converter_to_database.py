#!/usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8

import os
import sys
import sqlite3

tables_path = os.path.dirname(__file__) + "/tables/"
database_name = "elements_limits.db"
source_info_path = ["table1.txt", "table2.txt", "table3.txt", "table4.txt", "table5.txt"]
modified_info = "modified_info.txt"

try:
    os.remove(tables_path + modified_info)
    os.remove(tables_path + database_name)
except:
    print("It is not able to delete the previous modified/database file")

conn = sqlite3.connect(tables_path + database_name)
cursor = conn.cursor()

sql_request = """CREATE TABLE IF NOT EXISTS "{table}" (
        "Клас небезпеки речовини"	TEXT NOT NULL,
        "Назва речовини"	TEXT NOT NULL,
        "Величина масової витрати"	TEXT NOT NULL,
        "Гранично-допустимі викиди"	TEXT,
        "Тип речовини"	TEXT
        )"""

cursor.execute(sql_request.format(table="table"))
conn.commit()


for type_element, file_name in enumerate(source_info_path, start=1):
    print(file_name)

    with open(tables_path + file_name, encoding='utf-8') as f:
        with open(tables_path + modified_info, "at", encoding='utf-8') as f2:
            warning_class_element = ""
            name_element = ""
            limit_weight_using = ""  # г / год
            limit_drop = ""  # мг / м^3
            # read table, with ignoring of the first eight lines,
            # which show info about table-columns
            for j in f.readlines()[8::]:

                if "+" in j:
                    f2.write(warning_class_element + "\n")
                    f2.write(name_element + "\n")
                    f2.write(limit_weight_using + "\n")
                    f2.write(limit_drop + "\n")

                    sql_request = """
                    INSERT INTO "{table}"
                    ("Клас небезпеки речовини", "Назва речовини", 
                    "Величина масової витрати", "Гранично-допустимі викиди", "Тип речовини") 

                    VALUES (?, ?, ?, ?, ?)
                    """
                    task = (warning_class_element, name_element,
                            limit_weight_using, limit_drop, type_element)

                    cursor.execute(sql_request.format(name_element=name_element, table="table"), task)
                    conn.commit()

                    name_element = ""
                    limit_weight_using = ""     # г / год
                    limit_drop = ""             # мг / м^3

                    continue

                while "  " in j:
                    j = j.replace("  ", " ")

                parts_string = j.split("|")
                if len(parts_string) >= 5:

                    if parts_string[1]:
                        class_element = parts_string[1].split()
                        if len(class_element) == 2:
                            warning_class_element = class_element[-1]
                    name_element += " " + parts_string[2]
                    limit_weight_using += " " + parts_string[3]
                    limit_drop += " " + parts_string[4]

                    name_element = name_element.replace("  ", " ")
                    limit_weight_using = limit_weight_using.replace("  ", " ")
                    limit_drop = limit_drop.replace("  ", " ")

cursor.close()
conn.close()
