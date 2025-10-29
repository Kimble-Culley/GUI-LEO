#include <iostream>
#include <fstream>
#include <filesystem> 
#include <vector>
#include "files.h"
    

namespace fs = std::filesystem;


void Files::loadConfig(const std::string &filename){
    std::ifstream file(filename);

    if (!file.is_open()){
        std::cerr << "Error: failed to open config file: " << filename << std::endl;
        return;
    }

    std::string line;
    while(std::getline(file,line)){
        if(line.empty() || line[0] == '[') continue;

        size_t pos = line.find('=');
        if(pos != std::string::npos){
            std::string key = line.substr(0,pos);
            std::string value = line.substr(pos+1);
            config[key] = value;
        }
    }
    file.close();
}


bool Files::loadPiConfig(const std::string &filename){
    loadConfig(filename);

    if(config.find("host") == config.end() || config.find("user") == config.end()){
        std::cerr << "error: Host or user not found in " << filename << std::endl;
        return false;
    }

    sshHost = config["host"];
    sshUser = config["user"];

    std::cout << "Loaded " << sshUser << "@" << sshHost << std::endl;
    return true;
}










//Upon clicking the OpenScan button this function will go through the assigned directory
//our default directory will be ./files/csv
//after it manuvers to that directory, a list of .csv files will be printed, and the user will
//be asked to select a file to open.
//For now I think a text entry box would be the simplest, will will just concatinate it with the default directory.
void Files::findFiles(){
    fileList.clear();
    const::fs::path defaultPath{"./files/csv"};
    std::string fileExt = ".csv";

    for(auto const& directoryEntry : fs::directory_iterator{defaultPath}){
        fileList.push_back(directoryEntry.path());
    }

    /*
    for(int i = 0; i < static_cast<int>(fileList.size()); i++){
        std::cout << fileList[i] << std::endl;
    }
    */
}



void Files::readCSV(){
    counter = -1;
    std::ifstream file(fileName);
    

    if(!file.is_open()){
        std::cerr << "Error opening" << fileName << "\n";
    }
    std::string s;
    


    while(getline(file,s)){
        counter++;
    }
}

void Files::updateFileName(std::string newFileName){
    fileName = newFileName;

}

