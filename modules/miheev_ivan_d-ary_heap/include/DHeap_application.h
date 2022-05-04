// Copyright 2022 Olynin Alexander

#ifndef MODULES_MIHEEV_IVAN_D_ARY_HEAP_INCLUDE_DHEAP_APPLICATION_H_
#define MODULES_MIHEEV_IVAN_D_ARY_HEAP_INCLUDE_DHEAP_APPLICATION_H_

#include <string>
#include <vector>
#include "include/DHeap.h"

class Application {
 private:
    std::string Description();
    std::string getElem(std::vector<std::string>::iterator it,
                        const std::vector<std::string>& args,
                        std::vector<double>* ans);
    std::string getValue(std::vector<std::string> args,
                         std::string value, int* ans);
    std::string Get(std::vector<std::string> args, DHeap Tmp);
    std::string getDec(std::vector<std::string> args,
                       int* pos, double* dec);
 public:
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_MIHEEV_IVAN_D_ARY_HEAP_INCLUDE_DHEAP_APPLICATION_H_
