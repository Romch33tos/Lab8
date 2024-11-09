#include <iostream>
#include <string>
using namespace std;

string arabicToRoman(int number) {
    string roman = "";

    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    for (int i = 0; i < 13; i++) {
        while (number >= values[i]) {
            roman += symbols[i];
            number -= values[i];
        }
    }

    return roman;
}

int romanToArabic(string roman) {
    int total = 0;
    int prevValue = 0;

    for (int i = roman.length() - 1; i >= 0; i--) {
        char c = roman[i];
        int value;

        if (c == 'I') value = 1;
        else if (c == 'V') value = 5;
        else if (c == 'X') value = 10;
        else if (c == 'L') value = 50;
        else if (c == 'C') value = 100;
        else if (c == 'D') value = 500;
        else if (c == 'M') value = 1000;
        else return -1; // Если найден недопустимый символ

        if (value < prevValue) {
            total -= value;
        } else {
            total += value;
        }
        prevValue = value;
    }

    return total;
}

int main() {
    setlocale(LC_ALL, "russian");
    cout << "Введите номер команды: " << endl;
    cout << "1. Арабские цифры в римские" << endl;
    cout << "2. Римские цифры в арабские" << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Введите арабское число (от 1 до 3999): ";
        int arabicNumber;
        cin >> arabicNumber;

        if (arabicNumber < 1 || arabicNumber > 3999) {
            cout << "Число должно быть от 1 до 3999!" << endl;
        } else {
            string romanResult = arabicToRoman(arabicNumber);
            cout << "Римское представление: " << romanResult << endl;
        }
    } else if (choice == 2) {
        cout << "Введите римское число: ";
        string romanNumber;
        cin >> romanNumber;

        int arabicResult = romanToArabic(romanNumber);
        if (arabicResult == -1) {
            cout << "Вы ввели недопустимый символ." << endl;
        } else {
            cout << "Арабское представление: " << arabicResult << endl;
        }
    } else {
        cout << "Вы ввели неверный номер команды!" << endl;
    }

    return 0;
}
