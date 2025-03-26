
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class File{
private:
    char fileName_[30];
    char creationDate_[30];
    char fileSize_[30];
public:
    File() {
        fileName_[0] = '\0';
        creationDate_[0] = '\0';
        fileSize_[0] = '\0';
    }
    File(const char* fileName, const char* creationDate, const char* fileSize) {
        strcpy(fileName_, fileName);
        strcpy(creationDate_, creationDate);
        strcpy(fileSize_, fileSize);
    }

    void setFileName(const char* fileName) { strcpy(fileName_, fileName);}
    void setCreationDate(const char* creationDate) { strcpy(creationDate_, creationDate);}
    void setFileSize(const char* fileSize) { strcpy(fileSize_, fileSize);}

    char* getFileName() { return this->fileName_;}
    char* getCreationDate() { return this->creationDate_;}
    char* getFileSize() { return this->fileSize_;}

    void coutAllParams() {
        cout << "File: " << getFileName() << '\n';
        cout << "Date time: " << getCreationDate() << '\n';
        cout << "Size: " << getFileSize() << '\n';
    }
};


int main() {
    // test 1
    File test1;
    test1.coutAllParams();

    // test 2
    File test2("homework", "19.02.2025", "100000000000000000000000000000000 PB");
    test2.coutAllParams();

    // test 3
    File *test3;
    test3->coutAllParams();
    test3->setFileName("HW for tomorrow");
    test3->coutAllParams();


    // test 4
    test3->setFileSize("13 TB");
    test3->coutAllParams();

    // test 5
    File *test5("HW for tomorrow", "20.02.2025", "10000000000000000000000000000000000000000000 PB");
    tes5->coutAllParams();
    test3->setFileName("HW for today");
    test3->coutAllParams();
}
