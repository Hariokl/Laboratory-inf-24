#include <fstream>
#include <iostream>

class DataBase{
const int kMaxRowLength = 20;
const int kMaxColLength = 20;
private:
    char* readFilePath;
    char* writeFilePath;
public:
    DataBase() {}
    ~DataBase() {delete[] readFilePath; delete[] writeFilePath;}
    void SetReadPath(char* readPath) { this->readFilePath = readPath; }
    void SetWritePath(char* writePath) { this->writeFilePath = writePath; }
    void ReadFile(char** in) {
        std::ifstream fin(this->readFilePath);
        if (!fin) {
            std::cout << "Heт файла " << readFilePath << std::endl;
            return;
        }

    }
}
