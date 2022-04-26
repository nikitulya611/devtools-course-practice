// Copyright 2022 Myasnikova Varvara

#include <iostream>
#include <string>

#include "include/myasnikova_pseudographics.h"

Pseudographics::Pseudographics() {
  cout_0[0] = "._.";
  cout_0[1] = "|.|";
  cout_0[2] = "|_|";

  cout_1[0] = "...";
  cout_1[1] = "..|";
  cout_1[2] = "..|";

  cout_2[0] = "._.";
  cout_2[1] = "._|";
  cout_2[2] = "|_.";

  cout_3[0] = "._.";
  cout_3[1] = "._|";
  cout_3[2] = "._|";

  cout_4[0] = "...";
  cout_4[1] = "|_|";
  cout_4[2] = "..|";

  cout_5[0] = "._.";
  cout_5[1] = "|_.";
  cout_5[2] = "._|";

  cout_6[0] = "._.";
  cout_6[1] = "|_.";
  cout_6[2] = "|_|";

  cout_7[0] = "._.";
  cout_7[1] = "..|";
  cout_7[2] = "..|";

  cout_8[0] = "._.";
  cout_8[1] = "|_|";
  cout_8[2] = "|_|";

  cout_9[0] = "._.";
  cout_9[1] = "|_|";
  cout_9[2] = "..|";
}

std::string Pseudographics::PrintPseudographics(int num) {
  try {
    if (num < 0) {
      throw std::string("A negative number!");
    }
  }
  catch (std::string& str) {
    return str;
  }

  std::string result;
  std::string num_in_string = std::to_string(num);
  int len = num_in_string.length();

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < len; j++) {
      switch (num_in_string[j] - '0') {
      case 0:
        result += cout_0[i] + " ";
        break;
      case 1:
        result += cout_1[i] + " ";
        break;
      case 2:
        result += cout_2[i] + " ";
        break;
      case 3:
        result += cout_3[i] + " ";
        break;
      case 4:
        result += cout_4[i] + " ";
        break;
      case 5:
        result += cout_5[i] + " ";
        break;
      case 6:
        result += cout_6[i] + " ";
        break;
      case 7:
        result += cout_7[i] + " ";
        break;
      case 8:
        result += cout_8[i] + " ";
        break;
      case 9:
        result += cout_9[i] + " ";
        break;
      }
    }
    result += "\n";
  }

  return result;
}
