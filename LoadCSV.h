#pragma once
#include <fstream>
#include <sstream>
#include <vector>

static std::vector<std::vector<int>>LoadCsv(const std::string& csvFilePath){
    std::vector<std::vector<int>> intArray;
    std::ifstream file(csvFilePath);
    std::string line, value;

    while (std::getline(file, line)) {
        std::vector<int> row;
        std::istringstream iss(line);
        while (std::getline(iss, value, ',')) {
            // int型に変換して行に追加
            //intに変換
            int intValue = std::stoi(value);
            row.push_back(intValue);
        }
        intArray.push_back(row);
    }
    return intArray;
};


