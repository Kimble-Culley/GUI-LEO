#ifndef FILES_H
#define FILES_H

#include <string>

class Files {
private:
    int counter;
    std::string fileName;
    int avgQual;
    int scanSize;
public:
    Files() : counter(-1), fileName("files/csv/sorted_xyz.csv"), avgQual(0), scanSize(0) {}

    void readCSV();
    int getCounter() const { return counter; }
    std::string getFileName() const { return fileName; }
};

#endif //FILES_H