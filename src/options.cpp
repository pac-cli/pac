#include "options.hpp"
#include <cstdio>
#include <string>
#include <regex>
const std::regex knownOptions[] = {std::regex("-f"), std::regex("--file=.*")};
void parse_options(std::vector<std::string> args){    
    for (std::string unparsedArgument : args){
        printf("%s\n", unparsedArgument.c_str());
    }
}
