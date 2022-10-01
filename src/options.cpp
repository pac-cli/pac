#include "options.hpp"

std::string parse_options(std::vector<std::string> args) {
    for (int argumentIndex = 1; argumentIndex < args.size(); argumentIndex++) {
        if (args.size() < 3) continue;
        std::cout << "ArgumentIndex - " << argumentIndex << std::endl;
        std::cmatch argumentMatch;
        std::cout << "Regex - " << std::regex_match(args[argumentIndex].c_str(), argumentMatch, std::regex("-f")) << std::endl;
        if (std::regex_match(args[argumentIndex].c_str(), argumentMatch, std::regex("-f"))) {
            std::cout << "//Short file argument detected" << std::endl;
            if (!(argumentIndex+1 < args.size())) {
                std::cout << "Please, provide filepath to read" << std::endl;
                continue;
            }
            std::cout << "Path - " << args[argumentIndex + 1] << std::endl;
            return "-f";
        }
        std::cout << "Regex - " << std::regex_match(args[argumentIndex].c_str(), argumentMatch, std::regex("--file=(.*)")) << std::endl;
        if (std::regex_match(args[argumentIndex].c_str(), argumentMatch, std::regex("--file=(.*)"))) {
            std::cout << "//Long file argument detected" << std::endl;
            std::cout << "Path - " << argumentMatch[1];
            return "-f";
        }
    }
}

/*void parse_options(std::vector<std::string> args){
    std::vector<unsigned int> ignore_list;
    printf("Size: %u\n", args.size());
<<<<<<< HEAD
    for (unsigned int current_argument = 0; current_argument < args.size(); current_argument++){
        printf(std::find(ignore_list.begin(), ignore_list.end(), current_argument));
        if (std::find(ignore_list.begin(), ignore_list.end(), current_argument) != ignore_list.end() || current_argument==0) continue;
        auto unparsedArgument = args[current_argument];
        std::cmatch argumentMatch;
        printf("Argument - %s: %u ", unparsedArgument.c_str(), std::regex_match(unparsedArgument.c_str(), argumentMatch, std::regex("-f")));
        if (std::regex_match(unparsedArgument.c_str(), argumentMatch, std::regex("-f"))) {
=======
    for (unsigned int current_argument_index = 0; current_argument_index < args.size(); current_argument_index++){
        if (std::find(ignore_list.begin(), ignore_list.end(), current_argument_index)!=ignore_list.end() || current_argument_index==0) continue;
        std::string current_argument = args[current_argument_index];
        std::cmatch current_argument_match_result;
        printf("Argument - %s: %u ", current_argument.c_str(), std::regex_match(current_argument.c_str(), current_argument_match_result, std::regex("-f")));
        if (std::regex_match(current_argument.c_str(), current_argument_match_result, std::regex("-f"))) {
>>>>>>> 639cf933e59203a62a7708a731574ddf51b52886
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
