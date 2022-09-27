#include "options.hpp"
<<<<<<< HEAD

const std::regex knownOptions[] = {std::regex("-f"), std::regex("--file=.*")};
void parse_options(std::vector<std::string> args){
    std::vector<unsigned int> ignore_list;
    printf("Size: %u\n", args.size());
    for (unsigned int unparsedArgument_i = 0; unparsedArgument_i < args.size(); unparsedArgument_i++){
        if (std::find(ignore_list.begin(),ignore_list.end(), unparsedArgument_i)!=ignore_list.end() || unparsedArgument_i==0) continue;
        auto unparsedArgument = args[unparsedArgument_i];
        std::cmatch argumentMatch;
        printf("Argument - %s: %u ",unparsedArgument.c_str(),std::regex_match(unparsedArgument.c_str(), argumentMatch, std::regex("-f")));
        if (std::regex_match(unparsedArgument.c_str(), argumentMatch, std::regex("-f"))) {
            printf("//Short file argument detected");
            if (!(unparsedArgument_i+1 < args.size())) {
                printf("Error: Please provide filepath to read");
                return;
            }
            printf("\nPath: %s\n", args[unparsedArgument_i+1].c_str());
            ignore_list.push_back(unparsedArgument_i+1);
            continue;
        }
        if (std::regex_match(unparsedArgument.c_str(), argumentMatch, std::regex("--file=(.*)"))) {
            printf("//Long file argument detected %s", argumentMatch[1].str().c_str());
            printf("\nPath: %s\n",  argumentMatch[1].str().c_str());
            continue;
        }
        printf("\nPath: %s\n", unparsedArgument.c_str());
=======
#include <cstdio>
#include <string>
#include <regex>
const std::regex knownOptions[] = {std::regex("-f"), std::regex("--file=.*")};
void parse_options(std::vector<std::string> args){    
    for (std::string unparsedArgument : args){
        printf("%s\n", unparsedArgument.c_str());
>>>>>>> main
    }
}
