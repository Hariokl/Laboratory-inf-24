#include <cstring>

class Fraction{
private:
    bool positive = true;
    int integ = NULL;
    int frag_up = NULL;
    int frag_bot = NULL;
public:
    Fraction(int integ) {
        if (integ < 0) {
            this->positive = false;
        }
        this->integ = abs(integ);
    }

    Fraction(char *fract) {
        int length = strlen(fract);
        int i = 0;
        if (fract[0] == '-') {
            this->positive = false;
            ++i;
        }
        int id = NULL;
        for (; i < length; i++) {
            if (fract[i] == '/') {
                id = i;
                break;
            }
        }
        char buffer_up[id + 1];
        strncpy(buffer_up, fract, id);
        buffer_up[id] = '\0';
        this->frag_up = abs(atoi(buffer_up));

        char buffer_bot[length + 1];  // МОЖЕТ БЫТЬ ОШИБКА
        strncpy(buffer_bot, fract + id + 1, length);  // МОЖЕТ БЫТЬ ОШИБКА
        buffer_bot[length] = '\0';
        this->frag_up = abs(atoi(buffer_bot));
    }

    Fraction(int integ, char *fract) {
        if (integ < 0) {
            this->positive = false;
        }
        this->integ = abs(integ);

        int length = strlen(fract);
        int id = NULL;
        for (int i = 0; i < length; i++) {
            if (fract[i] == '/') {
                id = i;
                break;
            }
        }
        char buffer_up[id + 1];
        strncpy(buffer_up, fract, id);
        buffer_up[id] = '\0';
        this->frag_up = abs(atoi(buffer_up));

        char buffer_bot[length + 1];  // МОЖЕТ БЫТЬ ОШИБКА
        strncpy(buffer_bot, fract + id + 1, length);  // МОЖЕТ БЫТЬ ОШИБКА
        buffer_bot[length] = '\0';
        this->frag_up = abs(atoi(buffer_bot));
    }

};
