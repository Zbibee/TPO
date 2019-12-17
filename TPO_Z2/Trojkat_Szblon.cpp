#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
struct point {
	T x;
	T y;
	point();
	point(T x, T y);
	point(string x, string y) = delete;
	void printPoint();
};

template <class T>
point<T>::point() {
	this->x = 0;
	this->y = 0;
}

template <class T>
point<T>::point(T x, T y) {
	this->x = x;
	this->y = y;
}

template <class T>
void point<T>::printPoint() {
	cout << "(" << this->x << "," << this->y << ")" << endl;
}

template <class T>
class Trojkat
{
	long double AB, BC, CA;
public:
	struct point<T> a, b, c;
	Trojkat();
	Trojkat(point<T>, point<T>, point<T>);
	//Trojkat(point<string>, point<string>, point<string>) = delete;
	Trojkat(string,string,string,string,string,string) = delete;
	Trojkat(T, T, T, T, T, T);
	void setPunkta(point<T>);
	void setPunktb(point<T>);
	void setPunktc(point<T>);
	point<T> getPointA();
	point<T> getPointB();
	point<T> getPointC();
	long double GetAB();
	long double GetBC();
	long double GetCA();
	bool IsIsosceles();//równoramienny
	bool IsEquilateral();// równoboczny
	bool IsRectangular(); // prostokatny
	bool IsTriangle();
	long double GetCircumference();
	long double GetField();
	~Trojkat();
};

template <class T>
void TestTrojkat(Trojkat<T> t);

template <class T>
Trojkat<T>::Trojkat()
{
	this->a = { 0,0 };
	this->b = { 0,0 };
	this->c = { 0,0 };
}

template <class T>
Trojkat<T>::Trojkat(point<T> p1, point<T> p2, point<T> p3) {
	this->a = p1;
	this->b = p2;
	this->c = p3;
}

template <class T>
Trojkat<T>::Trojkat(T ax, T ay, T bx, T by, T cx, T cy) {
	this->a = { ax,ay };
	this->b = { bx,by };
	this->c = { cx,cy };
}

template <class T>
void Trojkat<T>::setPunkta(point<T> p1) {
	this->a = p1;
}

template <class T>
void Trojkat<T>::setPunktb(point<T> p2) {
	this->b = p2;
}

template <class T>
void Trojkat<T>::setPunktc(point<T> p3) {
	this->c = p3;
}

template <class T>
point<T> Trojkat<T>::getPointA() {
	return a;
}

template <class T>
point<T> Trojkat<T>::getPointB() {
	return b;
}

template <class T>
point<T> Trojkat<T>::getPointC() {
	return c;
}

template <class T>
Trojkat<T>::~Trojkat()
{
}

template <class T>
long double Trojkat<T>::GetAB() {
	this->AB = sqrt(pow(this->b.x - this->a.x, 2) + pow(this->b.y - this->a.y, 2));
	return this->AB;
}

template <class T>
long double Trojkat<T>::GetBC() {
	this->BC = sqrt(pow(this->c.x - this->b.x, 2) + pow(this->c.y - this->b.y, 2));
	return this->BC;
}

template <class T>
long double Trojkat<T>::GetCA() {
	this->CA = sqrt(pow(this->a.x - this->c.x, 2) + pow(this->a.y - this->c.y, 2));
	return this->CA;
}

template <class T>
bool Trojkat<T>::IsTriangle() {
	vector<double> v;
	v.push_back(this->GetAB());
	v.push_back(this->GetBC());
	v.push_back(this->GetCA());

	sort(v.begin(), v.end());

	if (v[2] < (v[0] + v[1]) and v[0] > 0){
        return true;
	}
	else{
        return false;
	}

}

template <class T>
bool Trojkat<T>::IsRectangular() {
        vector<double> v;
        v.push_back(this->GetAB());
        v.push_back(this->GetBC());
        v.push_back(this->GetCA());

        sort(v.begin(), v.end());

        if ((round(100 * pow(v[2],2))/100) == (round(100 * (pow(v[0], 2) + pow(v[1], 2))) / 100) and v[0] > 0 and this->IsTriangle())
            return true;
        else
            return false;
}

template <class T>
bool Trojkat<T>::IsIsosceles() {

    vector<double> v;
    v.push_back(this->GetAB());
    v.push_back(this->GetBC());
    v.push_back(this->GetCA());

    sort(v.begin(), v.end());

    if ((v[0] == v[1] or v[0] == v[2] or v[1] == v[2]) and v[0] > 0 and this->IsTriangle())
        return true;
    else
        return false;
}



template <class T>
bool Trojkat<T>::IsEquilateral() {
        vector<double> v;
        v.push_back(this->GetAB());
        v.push_back(this->GetBC());
        v.push_back(this->GetCA());

        sort(v.begin(), v.end());

        if (v[0] == v[1] and v[0] == v[2] and v[1] == v[2] and v[0] > 0 and this->IsTriangle())
            return true;
        else
            return false;
}

template <class T>
long double Trojkat<T>::GetField() {
    if(this->IsTriangle()){
        double obw = this->GetCircumference() / 2;
        return sqrt(obw*(obw - this->AB) * (obw - this->BC) *(obw - this->CA));
    }
    else
        return 0;
}

template <class T>
long double Trojkat<T>::GetCircumference() {
    if(this->IsTriangle()){
        return this->GetAB() +this->GetBC() +this->GetCA();
    }
    else
        return 0;
}

template <class T>
std::ostream& operator<<(std::ostream &strm, const point<T> &a) {
	return strm << "(" << a.x << "," << a.y << ")";
}

template <class T>
std::ostream& operator<<(std::ostream &strm, const Trojkat<T> &t) {
	return strm << "Trojkat posiada punkty:\n" << "a: " << t.a << "\nb: " << t.b << "\nc: " << t.c << endl;
}

template <class T>
void TestTrojkat(Trojkat<T> t) {
	bool tmp;
	cout << t << endl;
	cout << "|AB| = " << (double)t.GetAB() << endl;
	cout << "|BC| = " << (double)t.GetBC() << endl;
	cout << "|CA| = " << (double)t.GetCA() << endl;
	tmp = t.IsTriangle();
	cout << "\nCzy Trojkat: " << tmp << endl;
	tmp = t.IsEquilateral();
	cout << "Rownoboczny: " << tmp << endl;
	tmp = t.IsIsosceles();
	cout << "Rownoramienny: " << tmp << endl;
	tmp = t.IsRectangular();
	cout << "Prostopadly: " << tmp << endl;
	cout << "Obwod: " << (double)t.GetCircumference() << endl;
	cout << "Pole: " << (double)t.GetField() << endl;
	cout << "=============" << "\n" << endl;
}

int main()
{
	struct point<char> a = {'a','a'};
	struct point<char> b('a','c');
    struct point<char> c = {'c', 'c'};

    Trojkat<char> t1(1,2,3,4,5,6);

	TestTrojkat(t1);
/*
	t1.a = { 1,5 };
	t1.b = { 1,8 };
	t1.c = { -5,5 };

	TestTrojkat(t1);
*/
	t1.a = a;
	t1.b = b;
	t1.c = c;

	TestTrojkat(t1);
/*
	t1.a = { 1,0 };
	t1.b = { 0,1 };
	t1.c = { 0,0 };

	TestTrojkat(t1);

	t1.a = { 1,1 };
	t1.b = { 6,1 };
	t1.b = { 3, 20 };
	//t1.c = { 2.5 + 1, (5 * sqrt(3) / 2 + 1) };

	TestTrojkat(t1);
	*/
}
