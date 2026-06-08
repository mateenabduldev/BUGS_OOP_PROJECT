#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Logger {
private:
    string filename;
public:
    Logger(string file = "logs/log.txt") {
        filename = file;
    }
    void log(string message) {
        ofstream file(filename, ios::app);
        file << message << endl;
        file.close();
    }
    template<typename T>
    void log(string message, T value) {
        ofstream file(filename, ios::app);
        file << message << value << endl;
        file.close();
    }
};