#include "./dependencies/options.hpp"
#include "./dependencies/arrayToVec.hpp"
#include "./dependencies/include.h"

int main(int argc, char *argv[]){
    std::cmatch argumentMatch;
    std::cout << "Regex(main) - " << std::regex_match(argv[1], argumentMatch, std::regex("--file=(.*)")) << std::endl;
    std::cout << "Argc - " << argc << std::endl;
    parse_options(ch_arrToVec(argv, argc));
    return 0;
}
