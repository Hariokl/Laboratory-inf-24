#include <iostream>
#include <cstring>

using namespace std;

class Abiturient {
private:
    char* FIO_ = nullptr;
    int results_[3];
public:
    Abiturient() {}
    ~Abiturient() { delete[] FIO_; }
    char* GetFIO() { return FIO_; }
    int* GetResults() { return results_; }
    void SetFIO(char* fio) {
        if (FIO_) {
            delete[] FIO_;  // Free existing memory if any
        }
        FIO_ = new char[strlen(fio) + 1];  // Allocate memory for the new string
        strcpy(FIO_, fio);  // Copy the string
    }
    void SetResults(int results[3]) {
        for (int i = 0; i < 3; i++) {
                this->results_[i] = results[i];
            }
    }

	Abiturient(Abiturient & klass) {
        (*this).SetFIO(klass.GetFIO());
        (*this).SetResults(klass.results_);
	}

	Abiturient & operator=(Abiturient & klass) {
		if (this != &klass) {
            delete[] this->FIO_;
            (*this).SetFIO(klass.GetFIO());
            (*this).SetResults(klass.results_);
		}
		else {
			std::cout << "Самоприсваивание" << std::endl;
		}
		return *this;
	}
};

ostream& operator<<(ostream& out, Abiturient& abtr) {
    out << abtr.GetFIO() << " " << abtr.GetResults();
    return out;
}



int main() {
    Abiturient abtr;
    char* name = new char[30];
    strcpy(name, "Михаил Петрович");


    abtr.SetFIO(name);
    int res[3] = {2, 2, 2};
    abtr.SetResults(res);

    Abiturient abtr2(abtr);
    cout << abtr2 << '\n';

    Abiturient abtr3 = abtr;
    cout << abtr2 << '\n';

    free(name);
    name = nullptr;
    return 0;
}
