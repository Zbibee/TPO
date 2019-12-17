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
	long double ratioRectangletoCirclus = number*M_PI*radius*radius/(a*b);

	cout<<b<<" "<<ratioRectangletoCirclus<<endl;

	long double r2=2*radius;

    std::default_random_engine random_generator(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<long double> distributionX(radius, a-radius);
    std::uniform_real_distribution<long double> distributionY(radius, b-radius);

	vector <Circle> Zs;
	Zs.resize(number);
    long double x = distributionX(random_generator);
    long double y = distributionY(random_generator);

	Zs[0].x = x;
	Zs[0].y = y;
	int j, i=1;

	do{
		int k=0;
		x=distributionX(random_generator);
		y=distributionY(random_generator);
		for(j=0; j<i; j++)
		{
			if(distanseBetweenCircles(x,y,Zs[i])<r2)
			{
				k=1;
				break;
			}
		}
		if (k==0){
			Zs[i] = {x,y};
			i++;
		}
	} while (i<number);

	stable_sort(Zs.begin(), Zs.end(), sortByX);
	fstream f;
	f.open("File.txt", ios::out);
	for (i=0;i<number;i++)
        f<< i << "\t|" << Zs[i].x<<"\t|"<<Zs[i].y<<endl;

    f.close();
    return 0;
}
