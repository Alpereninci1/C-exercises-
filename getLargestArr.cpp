#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Do not edit MyClass!!!
// MyClass sınıfı üzerinde herhangi bir değişlik yapmayınız!!!
class MyClass {
	friend ostream& operator<<(ostream& out, const MyClass& c) {
		out << "a: " << c.a << " b: " << c.b << endl;
		return out;
	}
public:
	MyClass(int a, int b) :a{ a }, b{ b } {}

	bool operator>(const MyClass& other) {
		if ((a * a + b * b) > (other.a * other.a + other.b * other.b))
			return true;

		return false;
	}

private:
	int a, b;
};

// Asagidaki fonksiyonu gercekleyiniz [30 puan]
// Fonksiyon verilen sirasiz bir dizideki n. en buyuk degeri bulup dondurur
// n parametresinin değeri 1 ile sizeOfArr arasında olmalıdır. 
// Aksi durumda aykırı durum oluşturulmalıdır.

// implement the function below [30 points]
// it returns the n th largest element of a given unsorted arr 
// Value of n must be between 1 and sizeOfArr otherwise the functions throws an exception
template<class T>
T getNthLargest(T * arr, int sizeOfArr, int n) 
{
	try{
        if(n < 1 || n > sizeOfArr){
            throw "n degeri 1 ile sizeOfArr arasinda olmalidir";
        }
        vector <T> temp;
        for(int i = 0 ; i < sizeOfArr; i++){
            temp.push_back(arr[i]);
        }
        
        for (int i = 0; i < n - 1; i++){
            for (int j = n - 1; i < j; j--){
                    if ((temp[j] > temp[j - 1])) 
                      swap(temp[j], temp[j - 1]);
            }
        }
        for(int i = 0 ; i < sizeOfArr; i++){
            cout << temp[i] << " ";
        }

        return temp[n-1];
    }
    catch (const char* m) {
        cerr << m << endl;
    }


}

int main()
{
	int arrInt[] = { 45, 3, 65, 32, 8, 3, 9, 0, 12, 34, 768, 23 };
	double arrDouble[] = { 4.5, -14.65, 3.0, 0.65, 32.3, 8.8, 9.3, 9., 0.334, 1.2, 3.4, 76.8, 23.456 };
	MyClass arrMyClass[] = { {8, 4}, {2, 3}, {6, 5}, {56, 12}, {78, 59}, {2, 0}, 
								{45, 5}, {68, 10}, {9, 9}, {12, 4} };

	cout << getNthLargest(arrInt, sizeof(arrInt) / sizeof(int), 4) << endl;
	cout << getNthLargest(arrDouble, sizeof(arrDouble) / sizeof(double), 6) << endl;
	cout << getNthLargest(arrMyClass, sizeof(arrMyClass) / sizeof(MyClass), 1) << endl;

	// an exception must be occurred
	cout << getNthLargest(arrMyClass, sizeof(arrMyClass) / sizeof(MyClass), -2) << endl;

	return 0;
}