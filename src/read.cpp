#include "read.hpp"
#include "names.h"

std::vector<std::string> read(std::string path) {
    std::fstream f(path);
    if (!f.is_open()) std::cout << PROG_NAME << ": " << path << ": " << NOSUCHDERICTORY << std::endl;
    std::string file_data;
    std::vector<std::string> file;
    for (f >> file_data; !f.eof(); f >> file_data) {
        file.push_back(file_data);
    }
    return file;
}