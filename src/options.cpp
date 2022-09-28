#include "options.hpp"

void parse_options(std::vector<std::string> args){
    std::vector<unsigned int> ignore_list;
    printf("Size: %u\n", args.size());
    for (unsigned int current_argument = 0; current_argument < args.size(); current_argument++){
        if (std::find(ignore_list.begin(), ignore_list.end(), current_argument)!=ignore_list.end() || current_argument==0) continue;
        auto unparsedArgument = args[current_argument];
        std::cmatch argumentMatch;
        printf("Argument - %s: %u ", unparsedArgument.c_str(), std::regex_match(unparsedArgument.c_str(), argumentMatch, std::regex("-f")));
        if (std::regex_match(unparsedArgument.c_str(), argumentMatch, std::regex("-f"))) {
            printf("//Short file argument detected");
            if (!(current_argument+1 < args.size())) {
                printf("Error: Please provide filepath to read");
                return;
            }
            printf("\nPath: %s\n", args[current_argument+1].c_str());
            ignore_list.push_back(current_argument+1);
            continue;
        }
        if (std::regex_match(unparsedArgument.c_str(), argumentMatch, std::regex("--file=(.*)"))) {
            printf("//Long file argument detected %s", argumentMatch[1].str().c_str());
            printf("\nPath: %s\n",  argumentMatch[1].str().c_str());
            continue;
        }
        printf("\nPath: %s\n", unparsedArgument.c_str());
    }
}
