  // Copyright 2022 Brazhnik Dmitry

#ifndef MODULES_BRAZHNIK_DMITRY_CONVERTER_ARAB_ROM_INCLUDE_CONVERTER_H_
#define MODULES_BRAZHNIK_DMITRY_CONVERTER_ARAB_ROM_INCLUDE_CONVERTER_H_

#ifndef countof
#define countof(array) (sizeof(array) / sizeof((array)[0]))
#endif

#include <iostream>
#include <string> // NOLINT

struct roman {
    std::string val;
};

struct arabien {
    int val;
};

class Converter {
 public:
    Converter() {
        R.val = "";
        A.val = 0;
    }
    explicit Converter(std::string R_) {
        int num = 0;
        switch (CheckInput(R_)) {
        case 1:
            R.val = R_;
            A = ConvertRomToArab(R);
            R = ConvertArabToRom(A);
            break;
        case 0:
            num = atoi(R_.c_str());
            if (num < 0 || num > 3999) {
                throw std::out_of_range("Number out of bounds");
            }
            A.val = num;
            R = ConvertArabToRom(A);
            break;
        case -1:
            throw std::logic_error("Logic error: Invalid data.");
            break;
        default:
            throw std::logic_error("Logic error: Invalid data.");
            break;
        }
    }
    explicit Converter(int A_) {
        if (A_ < 0 || A_ > 3999) {
            throw std::out_of_range("Input error: The number is out of bounds");
        }
        A.val = A_;
        R = ConvertArabToRom(A);
    }

    arabien ConvertRomToArab(roman R_);
    roman ConvertArabToRom(arabien A_);
    void printToConsole();
    int CheckInput(std::string inText);
    std::string Get_R_Val();
    int Get_A_Val();

 private:
    roman R;
    arabien A;
};

#endif  // MODULES_BRAZHNIK_DMITRY_CONVERTER_ARAB_ROM_INCLUDE_CONVERTER_H_
