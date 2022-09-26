#include "stdio.h"
#include "./options.hpp"
#include "./arrayToVec.hpp"
#include <vector>
int main(int argc, char *argv[]){
    /*for (unsigned int argument_index=0; argument_index<argc; argument_index++) {
        printf("%u - %s\n", argument_index, argv[argument_index]);
    }*/
    parse_options(ch_arrToVec(argv, argc));
    return 0;
}
