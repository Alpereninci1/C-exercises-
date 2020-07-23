#include <iostream> 
using namespace std;

/*SORUNUN CEVABÝ: VERÝLEN STRÝNGTEKÝ HARFLERÝ BÜYÜK HARFE ÇEVÝRÝR.*/
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