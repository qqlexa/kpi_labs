#!/usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8

import os
import sys
import sqlite3

tables_path = os.path.dirname(__file__) + "/tables/"
database_name = "health_risk.db"
source_info_path = ["health_risk1.txt", "health_risk2.txt"]
modified_info = "health.txt"

try:
    os.remove(tables_path + modified_info)
    # os.remove(tables_path + database_name)
except:
    print("It is not able to delete the previous modified/database file")

conn = sqlite3.connect(tables_path + database_name)
cursor = conn.cursor()

sql_request = """CREATE TABLE "{table}" (
        "Речовина"	TEXT,
        "CAS"	TEXT,
        "RfC, мг/куб.м"	REAL,
        "Джерело"	TEXT,
        "Критичні органи/системи"	TEXT
        )"""

table = "inhalation_effects"

cursor.execute(sql_request.format(table=table))
conn.commit()

with open(tables_path + "health_risk1.txt", encoding='utf-8') as f:
    with open(tables_path + modified_info, "at", encoding='utf-8') as f2:
        element_name = ""
        cas_id = ""
        rfc = ""  # г / год
        source_data = ""  # мг / м^3
        critical_systems = ""
        # read table, with ignoring of the first eight lines,
        # which show info about table-columns
        for j in f.readlines()[6::]:

            if "+" in j:
                f2.write(element_name + "\n")
                f2.write(cas_id + "\n")
                f2.write(rfc + "\n")
                f2.write(source_data + "\n")
                f2.write(critical_systems + "\n")

                sql_request = """
                        INSERT INTO "{table}"
                        ("Речовина", "CAS", 
                        "RfC, мг/куб.м", "Джерело", "Критичні органи/системи") 
        
                        VALUES (?, ?, ?, ?, ?)
                        """
                task = (element_name, cas_id,
                        rfc, source_data, critical_systems)

                cursor.execute(sql_request.format(cas_id=cas_id, table=table), task)

                element_name = ""
                cas_id = ""
                rfc = ""     # г / год
                source_data = ""             # мг / м^3
                critical_systems = ""
                continue

            while "  " in j:
                j = j.replace("  ", " ")

            parts_string = j.split("|")
            if len(parts_string) >= 5:
                element_name += " " + parts_string[1]
                cas_id += " " + parts_string[2]
                rfc += " " + parts_string[3]
                source_data += " " + parts_string[4]
                critical_systems += " " + parts_string[5]

                element_name = element_name.replace("  ", " ")
                cas_id = cas_id.replace("  ", " ")
                rfc = rfc.replace("  ", " ")
                source_data = source_data.replace("  ", " ")
                critical_systems = critical_systems.replace("  ", " ")

conn.commit()

sql_request = """CREATE TABLE "{table}" (
        "Речовина"	TEXT,
        "CAS"	TEXT,
        "SFi,(мг/(кг*доба)"	REAL,
        "Джерело"	TEXT,
        "ЕРА"	TEXT,
        "МАВР"	TEXT
        )"""

table = "carcinogenic_potential"

cursor.execute(sql_request.format(table=table))
conn.commit()

with open(tables_path + "health_risk2.txt", encoding='utf-8') as f:
    with open(tables_path + modified_info, "at", encoding='utf-8') as f2:
        element_name = ""
        cas_id = ""
        sfi = ""  # г / год
        source_data = ""  # мг / м^3
        epa = ""
        mabp = ""

        # read table, with ignoring of the first eight lines,
        # which show info about table-columns
        for j in f.readlines()[7::]:

            if "+" in j:
                f2.write(element_name + "\n")
                f2.write(cas_id + "\n")
                f2.write(sfi + "\n")
                f2.write(source_data + "\n")
                f2.write(epa + "\n")
                f2.write(mabp + "\n")

                sql_request = """
                        INSERT INTO "{table}"
                        ("Речовина", "CAS", "SFi,(мг/(кг*доба)", 
                        "Джерело", "ЕРА", "МАВР") 

                        VALUES (?, ?, ?, ?, ?, ?)
                        """
                task = (element_name, cas_id, sfi, source_data, epa, mabp)

                cursor.execute(sql_request.format(cas_id=cas_id, table=table), task)

                element_name = ""
                cas_id = ""
                sfi = ""  # г / год
                source_data = ""  # мг / м^3
                epa = ""
                mabp = ""
                continue

            while "  " in j:
                j = j.replace("  ", " ")

            parts_string = j.split("|")
            if len(parts_string) >= 5:
                element_name += " " + parts_string[1]
                cas_id += " " + parts_string[2]
                sfi += " " + parts_string[3]
                source_data += " " + parts_string[4]
                epa += " " + parts_string[5]
                mabp += " " + parts_string[6]

                element_name = element_name.replace("  ", " ")
                cas_id = cas_id.replace("  ", " ")
                sfi = sfi.replace("  ", " ")
                source_data = source_data.replace("  ", " ")
                epa = epa.replace("  ", " ")
                mabp = mabp.replace("  ", " ")

conn.commit()

cursor.close()
conn.close()
