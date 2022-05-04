// Copyright 2022 Olynin Alexander

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/DHeap_application.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
