#include "arrayToVec.hpp"
std::vector<std::string> ch_arrToVec(char** arr, int arr_len){
    std::vector<std::string> tmpVec;
    
   for (int i=0; i < arr_len; i++) {
      tmpVec.push_back(arr[i]);
   }
    return tmpVec;
}
