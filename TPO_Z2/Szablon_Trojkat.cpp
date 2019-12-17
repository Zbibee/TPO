#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct point {
	double x;
	double y;
	point();
	template point(double x, double y);
	void printPoint();
};

point::point() {
	this->x = 0;
	this->y = 0;
}

template <int t>
point::point(double x, double y) {
	this->x = x;
	this->y = y;
}

void point::printPoint() {
	cout << "(" << this->x << "," << this->y << ")" << endl;
}

class Trojkat
{
	double AB, BC, CA;
public:
	struct point a, b, c;
	Trojkat();
	Trojkat(point, point, point);
	Trojkat(double, double, double, double, double, double);
	void setPunkta(point);
	void setPunktb(point);
	void setPunktc(point);
	point getPointA();
	point getPointB();
	point getPointC();
	double GetAB();
	double GetBC();
	double GetCA();
	bool IsIsosceles();//równoramienny
	bool IsEquilateral();// równoboczny
	bool IsRectangular(); // prostokatny
	bool IsTriangle();
	double GetCircumference();
	double GetField();
	~Trojkat();
};

void TestTrojkat(Trojkat t);

Trojkat::Trojkat()
{
	this->a = { 0,0 };
	this->b = { 0,0 };
	this->c = { 0,0 };
}

Trojkat::Trojkat(point p1, point p2, point p3) {
	this->a = p1;
	this->b = p2;
	this->c = p3;
}
Trojkat::Trojkat(double ax, double ay, double bx, double by, double cx, double cy) {
	this->a = { ax,ay };
	this->b = { bx,by };
	this->c = { cx,cy };
}

void Trojkat::setPunkta(point p1) {
	this->a = p1;
}

void Trojkat::setPunktb(point p2) {
	this->b = p2;
}

void Trojkat::setPunktc(point p3) {
	this->c = p3;
}

point Trojkat::getPointA() {
	return a;
}

point Trojkat::getPointB() {
	return b;
}
point Trojkat::getPointC() {
	return c;
}

Trojkat::~Trojkat()
{
}

double Trojkat::GetAB() {
	this->AB = sqrt(pow(this->b.x - this->a.x, 2) + pow(this->b.y - this->a.y, 2));
	return this->AB;
}

double Trojkat::GetBC() {
	this->BC = sqrt(pow(this->c.x - this->b.x, 2) + pow(this->c.y - this->b.y, 2));
	return this->BC;
}

double Trojkat::GetCA() {
	this->CA = sqrt(pow(this->a.x - this->c.x, 2) + pow(this->a.y - this->c.y, 2));
	return this->CA;
}

bool Trojkat::IsTriangle() {
	vector<double> v;
	v.push_back(this->GetAB());
	v.push_back(this->GetBC());
	v.push_back(this->GetCA());

	sort(v.begin(), v.end());

	if (v[2] < v[0] + v[1] && v[0] > 0)
		return true;
	else
		return false;
}

bool Trojkat::IsRectangular() {
	vector<double> v;
	v.push_back(this->GetAB());
	v.push_back(this->GetBC());
	v.push_back(this->GetCA());

	sort(v.begin(), v.end());

	if ((round(100 * pow(v[2],2))/100) == (round(100 * (pow(v[0], 2) + pow(v[1], 2))) / 100) and v[0] > 0)
		return true;
	else
		return false;
}

bool Trojkat::IsIsosceles() {
	vector<double> v;
	v.push_back(this->GetAB());
	v.push_back(this->GetBC());
	v.push_back(this->GetCA());

	sort(v.begin(), v.end());

	if ((v[0] == v[1] or v[0] == v[2] or v[1] == v[2]) && v[0] > 0)
		return true;
	else
		return false;
}

bool Trojkat::IsEquilateral() {
	vector<double> v;
	v.push_back(this->GetAB());
	v.push_back(this->GetBC());
	v.push_back(this->GetCA());

	sort(v.begin(), v.end());

	if (v[0] == v[1] and v[0] == v[2] and v[1] == v[2] and v[0] > 0)
		return true;
	else
		return false;
}

double Trojkat::GetField() {
	double obw = this->GetCircumference() / 2;
	return sqrt(obw*(obw - this->AB) * (obw - this->BC) *(obw - this->CA));
}

double Trojkat::GetCircumference() {
	return this->GetAB() +this->GetBC() +this->GetCA();
}

std::ostream& operator<<(std::ostream &strm, const point &a) {
	return strm << "(" << a.x << "," << a.y << ")";
}

std::ostream& operator<<(std::ostream &strm, const Trojkat &t) {
	return strm << "Trojkat posiada punkty:\n" << "a: " << t.a << "\nb: " << t.b << "\nc: " << t.c << endl;
}

void TestTrojkat(Trojkat t) {
	bool tmp;
	cout << t << endl;
	cout << "|AB| = " << t.GetAB() << endl;
	cout << "|BC| = " << t.GetBC() << endl;
	cout << "|CA| = " << t.GetCA() << endl;
	tmp = t.IsTriangle();
	cout << "\nCzy Trojkat: " << tmp << endl;
	tmp = t.IsEquilateral();
	cout << "Rownoboczny: " << tmp << endl;
	tmp = t.IsIsosceles();
	cout << "Rownoramienny: " << tmp << endl;
	tmp = t.IsRectangular();
	cout << "Prostopadly: " << tmp << endl;
	cout << "Obwod: " << t.GetCircumference() << endl;
	cout << "Pole: " << t.GetField() << endl;
	cout << "=============" << "\n" << endl;
}

int main()
{
	struct point a = point(2,3);
	struct point b = point(2,8);
	struct point c;

	Trojkat t1;
	//Trojkat t2 = Trojkat(2,1,2,4,0,0);
	//Trojkat t3 = Trojkat(a,b,c);

	TestTrojkat(t1);

	t1.a = { 1,5 };
	t1.b = { 1,8 };
	t1.c = { -5,5 };

	TestTrojkat(t1);

	t1.a = a;
	t1.b = b;
	t1.c = c;

	TestTrojkat(t1);

	t1.a = { 1,0 };
	t1.b = { 0,1 };
	t1.c = { 0,0 };

	TestTrojkat(t1);

	t1.a = { 1,1 };
	t1.b = { 6,1 };
	t1.c = { 2.5 + 1, (5 * sqrt(3) / 2 + 1) };

	TestTrojkat(t1);
	}

