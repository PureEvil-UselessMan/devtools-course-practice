// Copyright 2022 Olynin Alexander

#include <sstream>
#include <iterator>
#include <string>
#include <vector>

#include "include/DHeap_application.h"
#include "include/DHeap.h"


std::string Application::Description() {
    return "The program is an implementation of the d-heap data structure"
    "By default, the heap is represented by [13, 16, 31, 41, 51 , 100, 41]\n"
    "To create your own heap, use the -DHeap flag. Then specify the heap"
    "elements in any order,"
    "considering that only positive elements are avaliable.\n"
    "To specify the dimension of the heap use flag -d. "
    "Then specify the value.\n"
    "To specify the capacity of the heap use flag -cap. "
    "Then specify the value.\n"
    "To extract the minimum of the heap use flag -min.\n"
    "To decrease the value in the heap use flag -dec."
    "Then specify the position and new value.\n"
    "To get the elements of the heap use flag -get"
    "To insert element to the heap use flag -ins";
}

std::string Application::getElem(std::vector<std::string>::iterator it,
                                         const std::vector<std::string>& args,
                                         std::vector<double>* ans) {
    it++;
    ans->clear();
    while (it != args.end()) {
        if ((*it)[0] == '-') {
            break;
        }
        for (size_t i = 0; i < (*it).size(); i++) {
            if ((*it) < "0" || (*it) > "9") {
                std::string error_type = "Wrong type of values.\n"
                "Consider that only positive elements are avaliable";
                return error_type;
            }
        }
        (*ans).push_back(atof((*it).c_str()));
        it++;
    }
    if ((*ans).size() == 0) {
        std::string error_type = "No elements have been provided.\n"
            "Consider specify them right after flag -DHeap or -ins";
        return error_type;
    }
    return "";
}

std::string Application::getValue(std::vector<std::string> args,
                                  std::string value, int* ans) {
    std::vector<std::string>::iterator it;

    it = args.begin();
    it = find(args.begin(), args.end(), value);
    if (it != args.end()) {
        it++;
        if (it != args.end() && (*it)[0] != '-') {
            for (size_t i = 0; i < (*it).size(); i++) {
                if ((*it) < "0" || (*it) > "9") {
                    std::string error_type = "Wrong type of value.\n"
                    "Consider that only positive elements are avaliable";
                    return error_type;
                }
            }
            *ans = atoi((*it).c_str());
        } else {
            std::string error_type = "No value have been provided.\n"
                "Consider specify its right after flag " + value;
            return error_type;
        }
    }

    return "";
}

std::string Application::getDec(std::vector<std::string> args,
                         int* pos, double* dec) {
    std::vector<std::string>::iterator it;

    it = args.begin();
    it = find(args.begin(), args.end(), "-dec");
    it++;
    if (it != args.end() && (*it)[0] != '-') {
        for (size_t i = 0; i < (*it).size(); i++) {
            if ((*it) < "0" || (*it) > "9") {
                std::string error_type = "Wrong type of value.\n"
                "Consider that only positive elements are avaliable";
                return error_type;
            }
        }
    } else {
        std::string error_type = "No value have been provided.\n"
                    "Consider specify them right after flag -dec";
        return error_type;
    }
    *pos = atoi((*it).c_str());

    it++;
    if (it != args.end() && (*it)[0] != '-') {
        for (size_t i = 0; i < (*it).size(); i++) {
            if (((*it) < "0" || (*it) > "9") && (*it) != ".") {
                std::string error_type = "Wrong type of value.\n"
                "Consider that only positive elements are avaliable";
                return error_type;
            }
        }
    } else {
        std::string error_type = "Not enough values have been provided.\n"
            "Consider specify the second value right after the first one";
        return error_type;
    }
    *dec = atof((*it).c_str());
    return "";
}

std::string Application::Get(std::vector<std::string> args, DHeap Tmp) {
    std::vector<std::string>::iterator it;
    std::string reply = "";
    it = args.begin();
    it = find(args.begin(), args.end(), "-get");
    if (it != args.end()) {
        reply = "[ ";
        while (!(Tmp.isEmpty())) {
            reply += std::to_string(Tmp.extractMin()) + ", ";
        }
        reply += "]";
    }
    return reply;
}

std::string Application::operator()(int argc, const char** argv) {
    std::string reply = "";
    std::ostringstream oss;
    if (argc == 1) {
        reply = "You don't enter any arguments."
        "Consider to enter them right after the name of .exe file"
        "To get more information use flag -help";
    } else if (argc > 1) {
        std::vector<std::string> args;
        std::vector<std::string>::iterator it;
        for (int i = 1; i < argc; i++) {
            args.push_back(std::string(argv[i]));
        }


        it = args.begin();
        it = find(args.begin(), args.end(), "-help");
        if (it != args.end()) {
            reply = Description();
            oss << reply;
            return oss.str();
        }

        it = args.begin();
        it = find(args.begin(), args.end(), "-DHeap");
        if (it != args.end()) {
            std::vector<double> elem;
            std::string some_err = getElem(it, args, &elem);
            if (some_err.size() > 0) {
                oss << some_err;
                return oss.str();
            }
            int d = 2;
            int capacity = 1;

            std::string error_type;
            error_type = getValue(args, "-d", &d);
            if (error_type.size() > 0) {
                oss << error_type;
                return oss.str();
            }
            error_type = getValue(args, "-cap", &capacity);
            if (error_type.size() > 0) {
                oss << error_type;
                return oss.str();
            }
            if (d == 0 || d == 1 || capacity == 0) {
                reply = "Wrong format of heap option.\n";
                reply += "Consider don't use d = 0 or 1 or cap = 0.";
                oss << reply;
                return oss.str();
            }
            DHeap MyHeap(capacity, d);
            for (size_t i = 0; i < elem.size(); i++) {
                MyHeap.insert(elem[i]);
            }

            it = args.begin();
            it = find(args.begin(), args.end(), "-dec");
            if (it != args.end()) {
                int pos;
                double dec;
                std::string error_type = getDec(args, &pos, &dec);
                if (error_type.size() > 0) {
                    oss << error_type;
                    return oss.str();
                }
                MyHeap.decreaseValue(pos, dec);
            }
            reply = "success";

            it = args.begin();
            it = find(args.begin(), args.end(), "-min");
            if (it != args.end() && !MyHeap.isEmpty()) {
                reply += "\nmin is " + std::to_string(MyHeap.extractMin());
            }

            std::string result = Get(args, MyHeap);
            if (result != "") {
                reply += "\n" + Get(args, MyHeap);
            }
        } else {
            DHeap Default;
            std::vector<double> entries = {13, 16, 31, 41, 51, 100, 41};
            for (size_t i = 0; i < entries.size(); i++) {
                Default.insert(entries[i]);
            }

            it = args.begin();
            it = find(args.begin(), args.end(), "-ins");
            if (it != args.end()) {
                std::vector<double> elem;
                std::string some_err = getElem(it, args, &elem);
                if (some_err.size() > 0) {
                    oss << some_err;
                    return oss.str();
                }
                for (size_t i = 0; i < elem.size(); i++) {
                    Default.insert(elem[i]);
                }
            }

            it = args.begin();
            it = find(args.begin(), args.end(), "-dec");
            if (it != args.end()) {
                int pos;
                double dec;
                std::string error_type = getDec(args, &pos, &dec);
                if (error_type.size() > 0) {
                    oss << error_type;
                    return oss.str();
                }
                Default.decreaseValue(pos, dec);
            }

            reply = "success";

            it = args.begin();
            it = find(args.begin(), args.end(), "-min");
            if (it != args.end() && !Default.isEmpty()) {
                reply = "min is " + std::to_string(Default.extractMin());
            }

            std::string result = Get(args, Default);
            if (result != "") {
                reply += "\n" + Get(args, Default);
            }
        }
    }

    oss << reply;
    return oss.str();
}
