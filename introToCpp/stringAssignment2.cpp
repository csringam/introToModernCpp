#include <iostream>
#include <string>
#include <memory>
#include <sstream>

enum class Case { SENSITIVE, INSENSITIVE };

std::string ToIns(const std::string& str) {
    std::string res;
    for (char c : str) {
        res += std::tolower(c);
    }
    return res;
}

size_t Find(
    const std::string& source,         //Source string to be searched
    const std::string& search_string,  //The string to search for
    Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
    size_t offset = 0) {                //Start the search from this offset
    //Implementation
    size_t pos{ std::string::npos };

    if (searchCase == Case::INSENSITIVE) {
        pos = ToIns(source).find(search_string, offset);
    }
    else {
        pos = source.find(search_string, offset);
    }
    /*
    return position of the first character
    of the substring, else std::string::npos
    */
    return pos;
}

void demoAssignment2() {
    std::string input;
    std::string searchFor;
    size_t pos;
    std::stringstream ss;
    Case searchCase{ Case::INSENSITIVE };
    size_t offset{ 0 };

    std::cout << "Enter source string: ";
    std::getline(std::cin, input);
    std::cout << "Enter string to search for: ";
    std::getline(std::cin, searchFor);
    std::cout << "Enter 0 for sensitive search or 1 for insensitive search (1/0), then offset amount (0): ";
    std::string searchParam;
    std::getline(std::cin, searchParam);
    ss.str(searchParam);

    int i;
    ss >> i;
    if (i == 0) {
        searchCase = Case::SENSITIVE;
    }
    else if (i > 1) {
        std::cout << "Invalid search case, using insensitive search." << std::endl;
    }

    ss >> offset;

    pos = Find(input, searchFor, searchCase, offset);
    if (pos != std::string::npos) {
        std::cout << "Found at: " << pos << std::endl;
    }
    else {
        std::cout << "Not found." << std::endl;
    }
}