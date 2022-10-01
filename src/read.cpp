#include "read.hpp"

void read(std::string path) {
    std::fstream file;
    file.open(path);
    if (!file.is_open()) {
        std::cout << "pac: " << path << ": " << "no such directory" << std::endl;
    }
}