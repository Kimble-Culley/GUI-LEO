#ifndef FILES_H
#define FILES_H

#include <string>
#include <vector>
#include <unordered_map>

class Files {
private:
    int counter;
    std::string fileName;
    int avgQual;
    int scanSize;
    std::vector<std::string> fileList;

    std::unordered_map<std::string, std::string> config;
    std::string sshUser;
    std::string sshHost;

    void loadConfig(const std::string &filename);

public:
    Files() : counter(-1), fileName("files/csv/sorted_xyz.csv"), avgQual(0), scanSize(0) {}

    void findFiles();
    void readCSV();
    void updateFileName(std::string newFileName);
    
    bool loadPiConfig(const std::string &filename = "config.ini");

    int getCounter() const { return counter; }
    std::string getFileName() const { return fileName; }
    std::vector<std::string> getFileList() const { return fileList; }
    std::string getsshUser() const { return sshUser; }
    std::string getsshHost() const { return sshHost; }
};

#endif //FILES_H