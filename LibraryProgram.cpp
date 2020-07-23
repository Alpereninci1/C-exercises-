
#include <string>
#include <iostream>
using namespace std;
class Item
{
public:
	// Verilen parametrelere uygun �ekilde yeni bir item nesnesi olu�turur [5 Puan]
	// Constructs a new Item object accoring to the given parameters [5 points]
	Item();
	Item(const string& name, int count = 1)
	{
		this->name = name;

		count++;

	}
	int count; // Kitaptan kac adet oldugunu tutar // Holds the number of the item
	string name; // Kitab�n ad�n� tutar // Holds the name of the book
};
class BookCollection
{
	/* Koleksiyonda bulunan tum ogeleri ekrana bastirin [5 Puan]
	(iomanip, vb.) ek k�t�phaneler yard�m�yla tablo �eklinde bir g�r�n�m olu�turun [5 Ek Puan]*/
	/* prints all the items in the collection [5 point]
	use extra libraries (iomanip, etc.) to create a table view [5 points extra] */
	friend ostream& operator<<(ostream& out, const BookCollection& collection);
public:
	BookCollection(); // empty collection/ bos koleksiyon -> [5 puan/points]
	// 1 item of bookname [5 points]
	// verilen kitap isminden tek kitap iceren bir koleksiyon olusturur [5 puan]
	BookCollection(const string& bookname);
	BookCollection(const Item& item); // creates a collection of 1 item given -> 5 points
	/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	A�A�I EKS�K OLAN PROTOT�PLER� TAMAMLAYINIZ/COMPLETE THE MISSING FUNCTION PROTOTYPES BELOW!!!
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	// Write a destructor [5 points]
	// Y�k�c� fonksiyon [5 Puan]
	~BookCollection();
	// Write a copy constructor -> 10 points
	// Kopya Yap�c� [10 Puan]
	BookCollection(const BookCollection& other);
	// Write a move constructor -> 10 points
	// Ta��y�c� Yap�c� [10 puan]
	BookCollection(BookCollection&& other);
	// Overload copy assignment operator -> 10 points
	// Kopyalay�c� Atama Operat�r�n� a��r� y�kleyin [10 Puan]
	BookCollection& operator=(BookCollection& other);
	// Overload move assignment operator -> 10 points
	// Ta��y�c� Atama Operat�r�n� a��r� y�kleyin [10 Puan]
	BookCollection& operator=(BookCollection&& other);
	// Koleksiyon bo�sa true, de�ilse false d�nd�r�r
	// ! operator returns true if the collection is empty and it results false otherwise.
	bool operator!() const; // [3 puan/points]
	/* ==, != , >, <, >= ve <= operatorlerini a��r� y�kleyin
	Bu operat�rler Koleksiyon i�indeki TOPLAM ��E say�s�na g�re kar��la�t�rma yaparlar.
	T�m operat�rleri do�ru yapanlar [22 Puan], di�er durumda operat�r ba��na [3 Puan] */
	/* Overload ==, != , >, <, >= and <= operators
	These operators compare the TOTAL NUMBER OF ITEMS (counts of all items) in the collections
	Total points of comparison operators
	(6 operators = 22 points, less than 6 operators each operator is 3 points)*/
	bool operator==(const  BookCollection& other);
	bool operator!=(const  BookCollection& other);
	bool operator>=(const  BookCollection& other);
	bool operator<=(const  BookCollection& other);
	bool operator<(const  BookCollection& other);
	bool operator>(const  BookCollection& other);
	/* �ki koleksiyonu birle�tiren += operator�n� a��r� y�kleyiniz [25 Puan]
	E�er bir ��e mevcut koleksiyonda yoksa o ��eyi ekleyin,
	e�er ��e zaten mevcutsa adedini g�ncelleyin.*/
	/* Overload += operator which merges two collections [25 points]
	/ if an item in the otherCollection is already in the collection than only increase the item
	count
	/ otherwise add the item as a new item*/
	BookCollection& operator+=(const BookCollection& otherCollection);
	/* Koleksiyondan bir di�er koleksiyonu ��kartan -= operat�r�n� a��r� y�kleyin [30 Puan]
	E�er ��kart�lacak ��e koleksiyonda yoksa bir �ey yap�lmaz,
	��kart�lacak ��enin adedi mevcuttan fazlaysa/mevcuda e�itse ��e koleksiyondan ��kart�l�r,
	��kart�lacak ��enin adedi mevcuttan azsa sadece adet g�ncellenir.
	*/
	/* Overload -= operator which removes an item from the collection 30 points
	if an item that you need to remove is not a member of the collection than ignore that item
	if given item has equal or more number of instances than the collection has
	then you must completly remove the item from the collection otherwise only update the item
	count*/
	BookCollection& operator-=(const Item& item);
private:
	// numberOfUniqueItems koleksiyondaki Item say�s�n� tutar, TOPLAM ��E SAYISINI de�il
	// numberOfUniqueItems holds unique items not the total number of items in the collection
	int numberOfUniqueItems;
	Item* items;
	// Isterseniz buraya yard�mc� fonksiyonlar yazabilirsiniz.
	// If you want you can write helper functions here.

};



#include <iostream>
ostream& operator<<(ostream& out, const BookCollection& collection)
{
	if (collection.numberOfUniqueItems == 0) {

		out << "item yok" << endl;

		return out;
	}
	for (int i = 0; i < collection.numberOfUniqueItems; ++i) {

		out << collection.items[i];
		out << collection.numberOfUniqueItems;
	}
}

BookCollection::BookCollection()
{
	items = nullptr;
	numberOfUniqueItems = 0;
}

BookCollection::BookCollection(const string& bookname)
{
	this->items->name = bookname; 

	this->items->count++;
}

BookCollection::BookCollection(const Item& item)
{
	items->name = item.name;
	items->count = item.count;
}

BookCollection::~BookCollection()
{
	if (items != nullptr) {

		delete[] items;
	}
}

BookCollection::BookCollection(const BookCollection& other)
{
	numberOfUniqueItems = other.numberOfUniqueItems; 
	items = nullptr; 

	if (numberOfUniqueItems != 0) {

		items = new Item[numberOfUniqueItems];
		if (items != nullptr) {
			exit(-1);
			if (memcpy(items, other.items, numberOfUniqueItems * sizeof(Item)) == nullptr)
				exit(-1);
		}
	}
}

BookCollection::BookCollection(BookCollection&& other):items(nullptr),numberOfUniqueItems(0)
{
	items = other.items;
	numberOfUniqueItems = other.numberOfUniqueItems;

	other.items = nullptr;
	other.numberOfUniqueItems = 0;
}

BookCollection& BookCollection::operator=(BookCollection & other)
{
	if (this == &other)
		return *this;
	if (items != nullptr)
		delete[] items;

	numberOfUniqueItems = other.numberOfUniqueItems;

	items = new Item[numberOfUniqueItems];
	if (items != nullptr) {
		exit(-1);
		if (memcpy(items, other.items, numberOfUniqueItems * sizeof(Item)) == nullptr)
			exit(-1);
	}

	return *this;
}

BookCollection& BookCollection::operator=(BookCollection&& other)
{
	if (this != &other) {
		delete[] items;

		items = other.items;
		numberOfUniqueItems = other.numberOfUniqueItems;

		other.items = nullptr;
		other.numberOfUniqueItems = 0;

	}

	return *this;
}

bool BookCollection::operator!() const
{ 
	if (items == nullptr) {

		return true;
	}
	else {
		return false;
	}
}

bool BookCollection::operator==(const BookCollection& other)
{  
	int say1 = 0;
	int say2 = 0;
	for (int i = 0; i < numberOfUniqueItems; i++) {
		say1 += items[i].count;
	}
	for (int i = 0; i < numberOfUniqueItems; ++i) {

		say2 += items[i].count;
	}

	if (say1 == say2) {

		return true;
	}
	return false;
}

bool BookCollection::operator!=(const BookCollection& other)
{
	int say1 = 0;
	int say2 = 0;
	for (int i = 0; i < numberOfUniqueItems; i++) {
		say1 += items[i].count;
	}
	for (int i = 0; i < numberOfUniqueItems; ++i) {

		say2 += items[i].count;
	}

	if (say1 != say2) {

		return true;
	}
	return false;
}

bool BookCollection::operator>=(const BookCollection& other)
{
	int say1 = 0;
	int say2 = 0;
	for (int i = 0; i < numberOfUniqueItems; i++) {
		say1 += items[i].count;
	}
	for (int i = 0; i < numberOfUniqueItems; ++i) {

		say2 += items[i].count;
	}

	if (say1 >= say2) {

		return true;
	}
	return false;
}

bool BookCollection::operator<=(const BookCollection& other)
{  
	int say1 = 0;
	int say2 = 0;
	for (int i = 0; i < numberOfUniqueItems; i++) {
		say1 += items[i].count;
	}
	for (int i = 0; i < numberOfUniqueItems; ++i) {

		say2 += items[i].count;
	}

	if (say1 <= say2) {

		return true;
	}
	return false;
}

bool BookCollection::operator<(const BookCollection& other)
{
	int say1 = 0;
	int say2 = 0;
	for (int i = 0; i < numberOfUniqueItems; i++) {
		say1 += items[i].count;
	}
	for (int i = 0; i < numberOfUniqueItems; ++i) {

		say2 += items[i].count;
	}

	if (say1 < say2) {

		return true;
	}
	return false;
}

bool BookCollection::operator>(const BookCollection& other)
{
	int say1 = 0;
	int say2 = 0;
	for (int i = 0; i < numberOfUniqueItems; ++i) {
		say1 += items[i].count;
	}
	for (int i = 0; i < numberOfUniqueItems; ++i) {

		say2 += items[i].count;
	}

	if (say1 > say2) {

		return true;
	}
	return false;
}

BookCollection& BookCollection::operator+=(const BookCollection& otherCollection)
{
	BookCollection temp;
	temp.numberOfUniqueItems = numberOfUniqueItems;
	temp.items = new Item[temp.numberOfUniqueItems];

	if (temp.items == nullptr) exit(-1);
	for (unsigned i = 0; i < temp.numberOfUniqueItems; i++)
		temp.items[i] = items[i];
	if (items != nullptr)
		delete[] items;
	numberOfUniqueItems = temp.numberOfUniqueItems + otherCollection.numberOfUniqueItems;
	items = new Item[numberOfUniqueItems];
	if (items == nullptr)exit(-1);
	for (int i = 0; i < temp.numberOfUniqueItems; i++)
	{
		items[i] = temp.items[i];
	}
	for (int j = 0; j < otherCollection.numberOfUniqueItems; j++)
	{
		items[j + temp.numberOfUniqueItems] = otherCollection.items[j];
	}
	return *this;
}

BookCollection& BookCollection::operator-=(const Item& item)
{
	BookCollection temp1;
	
	if (temp1.items->count >= item.count) {

			temp1.items - items;
	}
	else {
		temp1.items->count = item.count;
	}
	
	return *this;
}

Item::Item()
{
	this->name = nullptr;
	this->count = 0;
}
