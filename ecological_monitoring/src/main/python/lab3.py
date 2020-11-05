import os
import sqlite3
from colorama import Fore
import re

tables_path = os.path.dirname(__file__) + "/tables/"
database_name = "health_risk.db"
objects_file = "objects.txt"

conn = sqlite3.connect(tables_path + database_name)
cursor = conn.cursor()


def get_sql(sql):
    cursor.execute(sql)
    _parameters = cursor.fetchone()
    conn.commit()
    return _parameters


def input_positive_float(description):
    user_input = input(description + ": ")
    while True:
        try:
            user_input = float(user_input)
            if user_input < 0:
                user_input = input(description + ": ")
            else:
                break
        except:
            user_input = input(description + ": ")
    return user_input


while True:
    print("""Виберіть тип розрахунку ризику, пов'язаного із \nзабруденням атмосферного повітря шуканою речовиною: 
    a. Канцерогенний
    b. НЕ Канцерогенний
    0. вийти
    """)
    selected_type = input()
    # selected_type = "b"
    if "a" in selected_type or "b" in selected_type:
        pass
    elif "0" in selected_type:
        print("Exit")
        break
    else:
        print("Input again")
        continue

    if "a" in selected_type:
        print("Введіть речовину")
        element_name = input()
        # element_name = "Азоту діоксид"
        # Консоль
        if not element_name:
            continue

        # enter parameters
        print("LADD = [(Ca * Tout * Vout) + (Ch * Tin * Vin)] * EF * ED/(BW * AT * 365) ")
        ca = input_positive_float(f"Введіть концентрацію `{element_name}` в атмосферному повітрі, мг/куб.м")
        # ca = 0.95 * 10 ** -6
        print(f"Для пошуку концентрації `{element_name}` в повітрі приміщення")
        ch = input_positive_float(f"Введіть значення концентрації у відсотках від концетрації\n"
                                  f"`{element_name}` в атмосферному повітрі, [0-100]")
        # ch = 100
        if ch > 100:
            print(f"Введено некоректне число. Значення концентрації `{element_name}` в повітрі приміщення "
                  f"встановлено у відповідність до концентрації")
            ch = ca
        else:
            ch = ca * ch / 100

        ef = input_positive_float("Введіть частоту впливу, днів/рік [1-365]")
        # ef = 350
        if ef > 365:
            print(
                f"Введено некоректне число. Частота впливу встановлена в {Fore.LIGHTCYAN_EX}365 днів / рік{Fore.RESET}")
            ef = 365

        ed = input_positive_float("Введіть тривалість впливу, років")
        # ed = 30

        pop = input_positive_float("Введіть кількість населення в досліджуваному місті")
        # pop = 300_000
        print(f"Період осереднення експозиції вводити не потрібно. "
              f"Для канцерогенів {Fore.LIGHTCYAN_EX}70 років{Fore.RESET}")
        at = 70

        age = input_positive_float("Введіть середній вік населення")
        # age = 30

        vout = input_positive_float("Швидкість дихання поза приміщенням, куб.м/год")
        # vout = 1.4
        vin = input_positive_float("Швидкість дихання в приміщеннях, куб.м/год")
        # vin = 0.63

        user_answer = input("Бажаєте вводити середню масу тіла та час знаходження/відсутності\n"
                            "у приміщенням для вибраної категорії населення? (yes / no): ")
        if "yes" in user_answer.lower():
            tout = input_positive_float("Введіть час, що проводиться поза приміщенням, год/доба")
            if tout > 24:
                print(f"Введено некоректне число. Час, що проводиться поза приміщенням "
                      f"встановлений в {Fore.LIGHTCYAN_EX}24 години/добу{Fore.RESET}")
                ef = 24

            tin = 24 - tout
            bw = input_positive_float("Введіть масу тіла, кг")
        else:
            # no
            parameters = get_sql(""" SELECT * FROM "{table}" """.format(table="exposure_factor_6"))

            arg = list()
            arg.append(parameters)
            arg.append(cursor.fetchone())

            if arg:
                if age > 11:
                    tout = arg[1][2]
                    tin = arg[1][1]
                else:
                    tout = arg[0][2]
                    tin = arg[0][1]
            else:
                print("Виникла помилка з використанням шуканих даних!")
                tout = input_positive_float("Введіть час, що проводиться поза приміщенням, год/доба")
                if tout > 24:
                    print(
                        "Введено некоректне число. Час, що проводиться поза приміщенням встановлений в 24 години/добу")
                    ef = 24

                tin = 24 - tout
                bw = input_positive_float("Введіть масу тіла, кг")

            parameters = get_sql(""" SELECT * FROM "{table}" 
            WHERE "Фактор експозиції" = "середній дорослий" """.format(table="exposure_factor_1"))

            if age > 25:
                bw = parameters[1]
            else:
                bw = parameters[1] - age

        ladd = (ca * tout * vout) + (ch * tin * vin) * ef * ed / (bw * at * 365)
        print(f"{Fore.GREEN}LADD = [( {ca} * {tout} * {vout}) + ({ch} * {tin} * {vin} )] * \n"
              f"* {ef} * {ed} / ({bw} * {at} * 365) = {ladd}{Fore.RESET} мг/кг-доба")

        parameters = get_sql(""" SELECT * FROM "{table}" 
        WHERE "Речовина" LIKE "%{element_name}%" """.format(table="carcinogenic_potential",
                                                              element_name=element_name))

        if not parameters:
            print(f"Не вдалося знайти `{element_name}` в базі")
            sf = input_positive_float("Введіть фактор канцерогенного потенціалу (SF)")
        else:
            if isinstance(parameters[2], str):
                sf = float(parameters[2].replace(",", "."))
            else:
                sf = float(parameters[2])
        cr = ladd * sf
        print(f"Величина  індивідуального ризику буде складати: "
              f"{Fore.GREEN} cr = {ladd} * {sf} = {cr}{Fore.RESET}")

        pcr = cr * pop
        print(f"Враховуючи, що  кількість  населення  в  досліджуваному місті становить:\n"
              f"{Fore.GREEN}{pop}{Fore.RESET}  чоловік,  розраховуємо  величину  популяційного ризику:\n"
              f"{Fore.GREEN}pcr = {cr} * {pop} = {pcr}{Fore.RESET}")

        if cr < 10 ** -6:
            print(f"За класифікацією рівнів ризику ВООЗ, розрахований ризик буде\n"
                  f"{Fore.LIGHTCYAN_EX}МІНІМАЛЬНИМ{Fore.RESET}, тобто бажаним(цільовим) для здоров'я населення.")
        elif cr < 10 ** -4:
            print(f"За класифікацією рівнів ризику ВООЗ,  розрахований ризик буде\n"
                  f"{Fore.LIGHTYELLOW_EX}НИЗЬКИМ{Fore.RESET}, тобто допустимим для здоров'я населення.")
        elif cr < 10 ** -3:
            print(f"За класифікацією рівнів ризику ВООЗ,  розрахований ризик буде\n"
                  f"{Fore.YELLOW}СЕРЕДНІМ{Fore.RESET}, тобто припустимий для виробничих умов; за\n"
                  f"впливу на все населення необхідний динамічний контроль\n"
                  f"і поглиблене вивчення джерел і можливих наслідків шкідливих\n"
                  f" впливів для вирішення питання про заходи з управління ризиком")
        else:
            print(f"За класифікацією рівнів ризику ВООЗ,  розрахований ризик буде\n"
                  f"{Fore.RED}ВИСОКИМ{Fore.RESET}, тобто не прийнятний для виробничих умов і населення;\n"
                  f"Необхідне здійснення заходів з усунення або зниження ризик")
    else:
        # b
        elements_info = list()
        while True:
            print("""
    1. Ввести речовину
    2. Вивести таблицю
    0. Вийти
    """)
            selected_type = input()
            # selected_type = "1"
            if "1" in selected_type:
                print("Введіть речовину")
                element_name = input()
                # element_name = "Азоту діоксид"
                # Консоль
                if not element_name:
                    continue
                is_exist = False
                for i in elements_info:
                    if element_name == i[0]:
                        is_exist = True
                        break
                if is_exist:
                    print("Елемент вже є в таблиці. Спробуйте інший")
                    continue

            elif "2" in selected_type:
                if len(elements_info) == 0:
                    print("Відсутні дані")
                else:
                    hi = dict()
                    hi_all = 0
                    for i in elements_info:
                        for system in i[4]:
                            if system in hi.keys():
                                hi[system.lower()] += i[3]
                            else:
                                hi[system.lower()] = i[3]
                    for i in hi:
                        hi_all += hi[i]

                    print("Речовина           |  Доза  | RfC           | HQ     | Критичні органи")
                    '{:^30}'.format('centered')
                    for element_name, c, rfc, hq, critical_systems in elements_info:
                        systems = ""
                        for system in critical_systems:
                            systems += system + " "
                        print(f"`{element_name:<16}` | {c:<6} | {rfc:<13} | {round(hq, 2):<6} | {systems:<20}")

                    print("Сумарний ризик:")
                    print(f"\t\t\t\t\t\t\t| НІ загальний  | {hi_all:<6} |")
                    for i in hi:
                        print(f"\t\t\t\t\t\t\t| HI {i:<10} | {round(hi[i], 2):<6} | ")

                continue
            elif "0" in selected_type:
                break
            else:
                print("Input again")
                continue

            c = input_positive_float(f"Введіть концентрацію `{element_name}` в атмосферному повітрі, мг/куб.м")
            # c = 1
            parameters = get_sql(""" SELECT * FROM "{table}" 
            WHERE "Речовина" LIKE "%{element_name}%" """.format(table="inhalation_effects", element_name=element_name))

            if not parameters:
                print(f"Не вдалося знайти `{element_name}` в базі")
                rfc = input_positive_float("Введіть референтну концентрацію (RfC)")
                critical_systems = list()
                critical_systems.append("відсутня інформація")
            else:
                if isinstance(parameters[2], str):
                    rfc = float(parameters[2].replace(",", "."))
                else:
                    rfc = float(parameters[2])
                critical_systems = parameters[4].split(",")
            print("- - - " * 12)
            print(f"Характеристику ризику  розвитку  неканцерогенних  ефектів  за\n"
                  f"впливу `{element_name}` концентрації {c} мг/куб.м  в  атмосферному\n"
                  f"повітрі здійснюємо шляхом розрахунку коефіцієнта небезпеки:")
            hq = c / rfc
            print(f"{Fore.GREEN}HQ = {c} / {rfc} = {round(hq, 5)}{Fore.RESET}")

            print(f"Отже, неканцерогенний  ризик для здоров'я населення за впливу\n"
                  f"`{element_name}` в  концентрації  {Fore.LIGHTCYAN_EX}{round(hq, 5)}{Fore.RESET} мг/куб.м")

            if hq < 1:
                print(f"Ризик виникнення шкідливих ефектів розглядають як зневажливо "
                      f"{Fore.LIGHTCYAN_EX}МАЛИЙ{Fore.RESET}")
            elif hq == 1:
                print(f"в атмосферному повітрі можна вважати допустимим,\n"
                      f"існує імовірність виникнення шкідливих ефектів у населення")
            else:
                print(f"в атмосферному повітрі не можна вважати допустимим,\n"
                      f"існує імовірність виникнення шкідливих ефектів у населення")
            print("Критичні органи/системи:")
            correct_critical_systems = list()
            for system in critical_systems:
                if system.startswith(" "):
                    system = system[1::]
                if system.endswith(" "):
                    system = system[::1]
                correct_critical_systems.append(system)
                print(f"{Fore.LIGHTCYAN_EX} - {system}{Fore.RESET}")

            info = list()
            info.append(element_name)
            info.append(c)
            info.append(rfc)
            info.append(hq)
            info.append(correct_critical_systems)
            elements_info.append(info)

    print("\n\n")

cursor.close()
conn.close()









































