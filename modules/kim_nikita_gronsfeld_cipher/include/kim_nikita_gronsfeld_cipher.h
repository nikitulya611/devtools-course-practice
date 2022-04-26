// Copyright 2022 Kim Nikita

#ifndef MODULES_KIM_NIKITA_GRONSFELD_CIPHER_INCLUDE_KIM_NIKITA_GRONSFELD_CIPHER_H_
#define MODULES_KIM_NIKITA_GRONSFELD_CIPHER_INCLUDE_KIM_NIKITA_GRONSFELD_CIPHER_H_

#include <string>
#include <map>

class GronsfeldCipher {
 private:
    char table[10][26];
    int mod(int start, int end, int result);
    double transvection(std::map<char, int> frequencies, double probability[],
      int d, int sub_size);
 public:
    GronsfeldCipher();
    std::string getGronsfeldTable();
    std::string encode(std::string source_text, std::string key);
    std::string decode(std::string ciphered_text, std::string key);
    std::string hack(std::string ciphered_text, int key_length);
};

#endif  // MODULES_KIM_NIKITA_GRONSFELD_CIPHER_INCLUDE_KIM_NIKITA_GRONSFELD_CIPHER_H_
