#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <list>
#include <cstdio>
#include <fstream>
#include <string>
#include <math.h>
#include <iomanip>
#include <cstdlib>
using namespace std;

void saveDataToFile(string FileName){
            ofstream of(FileName + ".txt");
            if(of.good()){
                for(int i = 0; i<=180 ; i++){
                    cout << setprecision(8) << i << "\t|" << (i * 3.14 / 180) << "\t|" << sin((i * 3.14 / 180)) << "\t|" << cos((i * 3.14 / 180)) << "\t|" <<endl;
                    of << setprecision(8) << i << "\t|" << (i * 3.14 / 180) << "\t|" << sin((i * 3.14 / 180)) << "\t|" << cos((i * 3.14 / 180)) << "\t|" <<endl;
                }
            of.close();
            }
}

void retDataFromFile(int nr, string fileName){
    fstream f(fileName + ".txt",ios::in);
    string dane;

    for(int c=0; c<=nr;c++){
        getline(f, dane);
    }

    cout<< "kat " << "\t|" << "Rad " << "\t|" << "SIN " << "\t|" << "COS " << "\t|" <<endl;
    cout<< dane <<endl;
    //return dane;

    f.close();
}

int main(){
    string fileName;
    cout<< "Podaj nazwe pliku(bez .txt): ";
    cin>> fileName;
    cin.ignore();
    saveDataToFile(fileName + ".txt");

    int nr;
    cout<< "Podaj kat(0 - 180): ";
    cin>> nr;
    cin.ignore();
    if( 0 <= nr and nr <= 180)
        retDataFromFile(nr, fileName);
    else
        cout<< "Wrong answer";

return 0;
}
