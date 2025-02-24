// Copyright 2022 Ershov Alexey

#include "include/vigenere_cipher_app.h"

#include <string>

#include "include/vigenere_cipher.h"

VigenereApplication::VigenereApplication() {}

std::string VigenereApplication::operator()(int argc, const char** argv) {
  if (argc < 2 || argc > 3) {
    return this->argument_error();
  }
  if (argc == 2 &&
      (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h")) {
    return this->help();
  }
  if (argc == 2 &&
      (std::string(argv[1]) != "--help" || std::string(argv[1]) != "-h")) {
    return this->argument_error();
  }

  std::string arg1 = std::string(argv[1]);
  std::string arg2 = std::string(argv[2]);

  try {
    VigenereCipher vc;
    vc.setPair(arg1, arg2);
    std::string result = vc.cipher();
    return result;
  } catch (std::invalid_argument& e) {
    return this->cipher_error(e);
  }
}

std::string VigenereApplication::help() {
  std::string help =
      std::string("") + "Welcome to string vigenere cipher app!\n" +
      "Please enter the phrase you want to encrypt (in uppercase)\n" +
      "As well as the encryption key (its length must match the "
      "long phrase)\n" +
      "Example: HELLOWORLD LEMONLEMON";
  return help;
}

std::string VigenereApplication::argument_error() {
  std::string error =
      std::string("") + "Invalid argument amount, try --help or -h command";
  return error;
}

std::string VigenereApplication::cipher_error(const std::invalid_argument& e) {
  std::string error = std::string("") + "Cipher error occurred!\n" + e.what();
  return error;
}
