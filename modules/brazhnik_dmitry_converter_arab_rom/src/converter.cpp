  // Copyright 2022 Brazhnik Dmitry

#include "include/converter.h"

#include <gtest/gtest.h>
#include <algorithm>
#include <utility>
#include <string>

arabien Converter::ConvertRomToArab(roman R_) {
    int Sum = 0;
    int sizeText = R_.val.size();
    std::string inText = R_.val;
    int const arab_[] = { 1000, 900, 500, 400, 100, 90,
        50, 40, 10, 9, 5, 4, 1 };
    char const* roman_[] = { "M",  "CM", "D",  "CD", "C",  "XC", "L",
                            "XL", "X",  "IX", "V",  "IV", "I" };
    arabien res;
    res.val = 0;

    for (int i = 0; i < sizeText; i++) {
        for (size_t j = 0; j < countof(roman_); j++) {
            if (inText[i] == roman_[j][0]) {
                if ((inText[i + 1] == roman_[j][1]) && (i != sizeText - 1)) {
                    Sum += arab_[j];
                    i++;
                    break;
                } else {
                    if ((j % 2 == 0) || j == 12) {
                        Sum += arab_[j];
                        break;
                    }
                }
            }
        }
    }
    res.val = Sum;
    return res;
}

roman Converter::ConvertArabToRom(arabien A_) {
    int num = A_.val;
    roman res;
    res.val = "";

    int roman_value_list[] = { 1000, 900, 500, 400, 100, 90, 50,
                              40,   10,  9,   5,   4,   1 };
    std::string roman_char_list[] = { "M",  "CM", "D",  "CD", "C",  "XC", "L",
                                     "XL", "X",  "IX", "V",  "IV", "I" };

    for (size_t i = 0; i < countof(roman_value_list); i++) {
        while (num >= roman_value_list[i]) {
            num -= roman_value_list[i];
            res.val += roman_char_list[i];
        }
    }
    return res;
}

void Converter::printToConsole() {
    std::cout << "Roman - " << R.val << " Arab - " << A.val << "\n";
}

int Converter::CheckInput(std::string inText) {
    int codeOut = -1;

    for (int i = 0; i < static_cast<int>(inText.size()); i++) {
        if (inText[i] >= 48 && inText[i] <= 57) {
            codeOut = 0;
        } else {
            if (inText[i] == 73 || inText[i] == 86 || inText[i] == 88 ||
                inText[i] == 76 || inText[i] == 67 || inText[i] == 68 ||
                inText[i] == 77) {
                codeOut = 1;
            } else {
                return -1;
            }
        }
    }
    return codeOut;
}

std::string Converter::Get_R_Val() {
    return R.val;
}

int Converter::Get_A_Val() {
    return A.val;
}
