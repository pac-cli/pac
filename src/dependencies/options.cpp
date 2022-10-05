#include "options.hpp"
//TODO: Rewrite it to the boost options
std::vector<std::string> parse_options(std::vector<std::string> args) {
    for (int argumentIndex = 1; argumentIndex < args.size(); argumentIndex++) {
        if (args.size() < 3) return std::vector<std::string> ({});
        std::cout << "ArgumentIndex - " << argumentIndex << std::endl;
        std::cmatch argumentMatch;
        std::cout << "Regex - " << std::regex_match(args[argumentIndex].c_str(), argumentMatch, std::regex("-f")) << std::endl;
        if (std::regex_match(args[argumentIndex].c_str(), argumentMatch, std::regex("-f"))) {
            std::cout << "//Short file argument detected" << std::endl;
            if (!(argumentIndex+1 < args.size())) {
                std::cout << "Please, provide filepath to read" << std::endl;
                return std::vector<std::string> ({});
            }
            std::cout << "Path - " << args[argumentIndex + 1] << std::endl;
            //return "-f";
        }
        std::cout << "Regex - " << std::regex_match(args[argumentIndex].c_str(), argumentMatch, std::regex("--file=(.*)")) << std::endl;
        if (std::regex_match(args[argumentIndex].c_str(), argumentMatch, std::regex("--file=(.*)"))) {
            std::cout << "//Long file argument detected" << std::endl;
            std::cout << "Path - " << argumentMatch[1];
            return std::vector<std::string> (args, args[2]});
        }
    }
    return std::vector<std::string> ({});
}

/*void parse_options(std::vector<std::string> args){
    std::vector<unsigned int> ignore_list;
    printf("Size: %u\n", args.size());
    for (unsigned int current_argument_index = 0; current_argument_index < args.size(); current_argument_index++){
        if (std::find(ignore_list.begin(), ignore_list.end(), current_argument_index)!=ignore_list.end() || current_argument_index==0) continue;
        std::string current_argument = args[current_argument_index];
        std::cmatch current_argument_match_result;
        printf("Argument - %s: %u ", current_argument.c_str(), std::regex_match(current_argument.c_str(), current_argument_match_result, std::regex("-f")));
        if (std::regex_match(current_argument.c_str(), current_argument_match_result, std::regex("-f"))) {
            printf("//Short file argument detected");
            if (!(current_argument_index+1 < args.size())) {
                printf("Error: Please provide filepath to read");
                return;
            }
            printf("\nPath: %s\n", args[current_argument_index+1].c_str());
            ignore_list.push_back(current_argument_index+1);
            continue;
        }
        if (std::regex_match(current_argument.c_str(), current_argument_match_result, std::regex("--file=(.*)"))) {
            printf("//Long file argument detected %s", current_argument_match_result[1].str().c_str());
            printf("\nPath: %s\n",  current_argument_match_result[1].str().c_str());
            continue;
        }
        printf("\nPath: %s\n", current_argument.c_str());
    }
}*/
