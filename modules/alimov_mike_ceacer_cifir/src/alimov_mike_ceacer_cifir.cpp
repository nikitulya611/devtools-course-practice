// Copyright 2022 Alimov Mikhail
#include "include/alimov_mike_ceacer_cifir.h"
#include <string>
CaesarCipher::CaesarCipher() {
  vvod = "";
  offset = 0;
}

CaesarCipher::CaesarCipher(string vvod1, int offset1) {
  vvod = vvod1;
  offset = offset1;
}

string CaesarCipher::encrypt(string plain, int offset) {
  if (plain.empty()) throw 1;
  int len = plain.size();
  string result;
  for (int i = 0; i < len; i++) {
    if (isalpha(plain[i])) {
      int num = toupper(plain[i]) - 'A';
      int nxt = (num + offset + 26) % 26;
      result.append(alphabet[nxt]);
    } else {
      string s;
      s = plain[i];
      result.append(s);
    }
  }
  return result;
}
string CaesarCipher::decrypt(string cipher, int offset) {
  if (cipher.empty()) throw 1;
  int len = cipher.size();
  string result;
  for (int i = 0; i < len; i++) {
    if (isalpha(cipher[i])) {
      int num = toupper(cipher[i]) - 'A';
      int nxt = (num - offset + 26) % 26;
      result.append(alphabet[nxt]);
    } else {
      string s;
      s = cipher[i];
      result.append(s);
    }
  }
  return result;
}
