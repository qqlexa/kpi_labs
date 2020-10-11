import os
import sys
import sqlite3

tables_path = os.path.dirname(__file__) + "/tables/"

conn = sqlite3.connect(tables_path + "tables_test.db")
cursor = conn.cursor()

sql_request = """CREATE TABLE IF NOT EXISTS "table{i}" (
        "Клас небезпеки речовини"	TEXT NOT NULL,
        "Назва речовини"	TEXT NOT NULL,
        "Величина масової витрати"	TEXT NOT NULL,
        "Гранично-допустимі викиди"	TEXT
        )"""

for i in range(1, 6):
    cursor.execute(sql_request.format(i=i))
    conn.commit()

for i in os.listdir(tables_path):
    print(i)
    if "table" in i and ".txt" in i and "_" not in i:
        changed_file_path = tables_path + i + "_test.txt"
        try:
            os.remove(changed_file_path)
        except:
            print("It is not able to delete the previous file")

        with open(tables_path + i, encoding='utf-8') as f:
            with open(changed_file_path, "at", encoding='utf-8') as f2:
                warning_class_element = ""
                name_element = ""

                limit_weight_using = ""  # г / год
                limit_drop = ""          # мг / м^3
                for j in f.readlines()[8::]:

                    if "+" in j:
                        f2.write(warning_class_element + "\n" +
                                name_element + "\n" +
                                limit_weight_using + "\n" +
                                limit_drop + "\n")

                        sql_request = """
                        INSERT INTO {table}
                        ("Клас небезпеки речовини", "Назва речовини", 
                        "Величина масової витрати", "Гранично-допустимі викиди") 

                        VALUES (?, ?, ?, ?)
                        """
                        task = (warning_class_element, name_element,
                                limit_weight_using, limit_drop)

                        cursor.execute(sql_request.format(name_element=name_element, table=i.replace(".txt", "")), task)
                        conn.commit()

                        name_element = ""

                        limit_weight_using = ""  # г / год
                        limit_drop = ""  # мг / м^3

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
