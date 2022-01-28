import os

errors = ["Błąd w linii 3: niewłaściwy zakres tablicy b",
          "Błąd w linii 3: druga deklaracja a",
          "Błąd w linii 5: niezadeklarowana zmienna a",
          "Błąd w linii 6: użycie niezainicjowanej zmiennej a",
          "Błąd w linii 3: nierozpoznany napis 1",
          "Błąd w linii 5: użycie niezainicjowanej zmiennej a",
          "Błąd w linii 5: niewłaściwe użycie zmiennej tablicowej b",
          "Błąd w linii 6: niewłaściwe użycie zmiennej a",
          "Błąd w linii 8: niezadeklarowana zmienna i",
          "Błąd w linii 7: zabroniona modyfikacja iteratora i"]

programs1 = ["Binarny zapis liczby", "Sito Eratostenesa", "Rozkład liczby na czynniki pierwsze"]

programs2 = ["Input: 1 0    Output: 1 0 0 0",
             "Input: x      Output: x+15 15 -999 -555555555 7777 -999 11 707 7777",
             "Input: 1      Output: 121393",
             "Input: 20     Output: 2432902008176640000 6765",
             "Input: 20     Output: 2432902008176640000",
             "Output: 0 24 46 66 84 100 114 126 136 144 150 154 156 i z powrotem",
             "Input: 1234567890 1234567890987654321 987654321\nOutput: 674106858",
             "Input: 1 0 2     Output: 31001 40900 2222012",
             "Input: 12 23 34  Output: 507 4379 0",
             "Output: nieposortowana 1234567890 posortowana",
             "Input: 26 7      Output: 3 5 -4 -2 3 -5 -4 2"]


case = input("Które testy odpalić? (1 - błędy, 2 - programy z pdf'a, 3 - pozostałe programy testowe, 4 - wszystkie)\n")
case = int(case)

if case == 1:
    for i in range(0, 10):
        print('\033[93mOczekiwany błąd: ' + errors[i] + '\033[0m')
        cmd = f'./kompilator tests/error{i}.imp ../test.txt'
        os.system(cmd)
        print("\n")

elif case == 2:
    for i in range(0, 3):
        print('\033[93m' + programs1[i] + '\033[0m')
        cmd = f'./kompilator tests/program{i}.imp ../test.txt && ../maszyna_wirtualna/./maszyna-wirtualna ../test.txt'
        os.system(cmd)
        print("\n")

elif case == 3:
    for i in range(0, 11):
        print('\033[93m' + programs2[i] + '\033[0m')
        cmd = f'./kompilator tests/{i}-*.imp ../test.txt && ../maszyna_wirtualna/./maszyna-wirtualna ../test.txt'
        os.system(cmd)
        print("\n")

elif case == 4:
    for i in range(0, 10):
        print('\033[93mOczekiwany błąd: ' + errors[i] + '\033[0m')
        cmd = f'./kompilator tests/error{i}.imp ../test.txt'
        os.system(cmd)
        print("\n")

    for i in range(0, 3):
        print('\033[93m' + programs1[i] + '\033[0m')
        cmd = f'./kompilator tests/program{i}.imp ../test.txt && ../maszyna_wirtualna/./maszyna-wirtualna ../test.txt'
        os.system(cmd)
        print("\n")

    for i in range(0, 11):
        print('\033[93m' + programs2[i] + '\033[0m')
        cmd = f'./kompilator tests/{i}-*.imp ../test.txt && ../maszyna_wirtualna/./maszyna-wirtualna ../test.txt'
        os.system(cmd)
        print("\n")