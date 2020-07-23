#include <vector>
#include <string>
#include <iostream>
using namespace std;
class MyFavoriteSong
{
public:
    MyFavoriteSong() {} // empty song
    // nesnenize sarkinin bir misrasini ekler [10 puan]
    // adda a new verse to your object [10 points]
    void addNewVerse(const string& verse)
    {

        this->song.push_back(verse);
        

    }
    // nesne icindeki sarkinin tum sozlerini ekrana bastirir [7 puan]
    // print each verse in a new line [7 points]
    void printLyric() const
    {
        int n = this->song.size();
        for (int i = 0; i < n; i++) {

            cout << this->song.at(i);
        }
        
    }
private:
    vector<string> song;
};
int main()
{
    MyFavoriteSong song;
    /* Asagidaki fonksiyonlarin parametrelerini duzenleyerek en sevdiginiz sarkinin sozlerinin
    nesnenize eklenmesini saglayin [3 PUAN] */
    // edit these lines so when I run the code I can see your favorite song [3 points]
    song.addNewVerse("Dunyaya baktim da gozlerim doldu \n");
    song.addNewVerse("Hicbir sey eksiksiz yaratilmamis \n");
    song.addNewVerse("Sevenin sevdasi yarida kalmis \n");
    // isterseniz bu aralýða daha fazla song.addNewVerse(""); satýrý ekleyip düzenleyebilirsiniz
    // ... if you desire you can add and edit more lines of song.addNewVerse(""); here

    song.addNewVerse("Kimine ask nedir anlatilmamis \n");
    song.printLyric();
    return 0;
}