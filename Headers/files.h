#ifndef FILES_H
#define FILES_H

#include <string>
#include <vector>

class Files {
private:
    int counter;
    std::string fileName;
    int avgQual;
    int scanSize;
    std::vector<std::string> fileList;
public:
    Files() : counter(-1), fileName("files/csv/sorted_xyz.csv"), avgQual(0), scanSize(0) {}

    void findFiles();
    void readCSV();
    void updateFileName(std::string newFileName);

    int getCounter() const { return counter; }
    std::string getFileName() const { return fileName; }
};

#endif //FILES_H