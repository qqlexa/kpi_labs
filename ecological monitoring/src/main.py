import os
import sys
import sqlite3
import time

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

