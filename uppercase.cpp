#include <iostream> 
using namespace std;

/*SORUNUN CEVAB�: VER�LEN STR�NGTEK� HARFLER� B�Y�K HARFE �EV�R�R.*/
void ozyinelemeli(char* str) {
    if (*str++ != '\0') {
        if (*str >= 'a' && *str <= 'z')
            *str += 'A' - 'a';
        ozyinelemeli(str++);
    }
    else
        return;
}
int main() {

    char str1[] = "alperen";

    ozyinelemeli(str1);

    cout << str1;
    return 0;

}