#include<iostream>
#include<stdexcept>
#include<math.h>
#include <random>
#include <chrono>
#include <vector>
#include<algorithm>
#include<fstream>

# define M_PI           3.14159265358979323846  /* pi */
using namespace std;

struct Circle{
    long double x, y;
};

long double distanseBetweenCircles(long double x, long double y, Circle c){
    return sqrt(pow(x-c.x, 2)+pow(y-c.y, 2));
}

bool sortByX( Circle const & c1, Circle const & c2){
    return c1.x < c2.x;
}

int main(){
    long double radius=1.0;
	int number = 10000;

	long double a=20*radius;
	long double b=10*number*M_PI*radius*radius/a;
	long double fieldRectangle = (a*b);
	long double fieldOfAllCirclus = number*M_PI*radius*radius;
	long double ratioCirclustoRectangle = fieldOfAllCirclus/fieldRectangle;

	cout<< "Radius of Circules: " << radius <<endl;
	cout<< "Number of Circules: " << number <<endl;
	cout<< "The sides of the rectangle\n\tA: " << a << "\n\tB: " << b <<endl;
	cout<< "Field of rectangle " << fieldRectangle <<endl;
	cout<< "Field of circulus: " << fieldOfAllCirclus <<endl;
	cout<< "Ratio sum fields of all circulus to field rectangle: " << ratioCirclustoRectangle <<endl;

	long double diameter=2*radius;

    std::default_random_engine random_generator(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<long double> distributionX(radius, a-radius);
    std::uniform_real_distribution<long double> distributionY(radius, b-radius);

	vector <Circle> circlesVec;
	circlesVec.resize(number);
    long double x = distributionX(random_generator);
    long double y = distributionY(random_generator);

	circlesVec[0] = {x,y};
	int j, i=1, k=0;
	do{
		x=distributionX(random_generator);
		y=distributionY(random_generator);
		for(j=0; j<i; j++)
		{
			if(distanseBetweenCircles(x,y,circlesVec[i])<diameter)
			{
				k=1;
				break;
			}
		}
		if (k==0){
			circlesVec[i] = {x,y};
			i++;
		}
	} while (i<number);

	stable_sort(circlesVec.begin(), circlesVec.end(), sortByX);
	fstream f;
	f.open("File.txt", ios::out);
	for (i=0;i<number;i++)
        f<< i << "\t|" << circlesVec[i].x<<"\t|"<< circlesVec[i].y<<endl;

    f.close();
    return 0;
}
