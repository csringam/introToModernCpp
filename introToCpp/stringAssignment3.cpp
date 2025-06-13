#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include <vector>

enum class Case { SENSITIVE, INSENSITIVE };

std::string ToInse(const std::string& str) {
    std::string res;
    for (char c : str) {
        res += std::tolower(c);
    }
    return res;
}

std::vector<int> FindAll(
    const std::string& target,              //Target string to be searched
    const std::string& search_string,       //The string to search for
    Case searchCase = Case::INSENSITIVE,    //Choose case sensitive/insensitive search
    size_t offset = 0) {                    //Start the search from this offset
    //Implementation
    std::vector<int> pos;

    if (searchCase == Case::INSENSITIVE) {
        pos.push_back(static_cast<int>(ToInse(target).find(search_string, offset)));
    }
    else {
        pos.push_back(static_cast<int>(target.find(search_string, offset)));
    }

    if (!pos.empty()) {
        size_t nextPos = pos[0];
        while (nextPos != std::string::npos) {
            if (searchCase == Case::INSENSITIVE) {
                nextPos = ToInse(target).find(search_string, nextPos + 1);
            }
            else {
                nextPos = target.find(search_string, nextPos + 1);
            }
            if (nextPos != std::string::npos) {
                pos.push_back(static_cast<int> (nextPos));
            }
        }
    }
    /*
    Return indices of found strings,
    else an empty vector
    */
    return pos;
}

void stringAssignment3() {
    std::string input;
    std::string searchFor;
    std::vector<int> pos;
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

    pos = FindAll(input, searchFor, searchCase, offset);
    if (!pos.empty()) {
        std::cout << "Found at: ";
        for (auto i : pos) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Not found." << std::endl;
    }
}