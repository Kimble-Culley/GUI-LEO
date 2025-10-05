#include <iostream>
#include <fstream>
#include <filesystem> 
#include "files.h"





void Files::readCSV(){
    std::ifstream file(fileName);
    

    if(!file.is_open()){
        std::cerr << "Error opening" << fileName << "\n";
    }
    std::string s;
    


    while(getline(file,s)){
        counter++;
    }
}