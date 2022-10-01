#include "stdio.h"
#include "options.hpp"
#include "arrayToVec.hpp"
#include <vector>
int main(int argc, char *argv[]){
    parse_options(ch_arrToVec(argv, argc));
    return 0;
}
