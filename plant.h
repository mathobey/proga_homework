#include <iostream>

#ifndef PLANT_H
#define PLANT_H

using namespace std;

class Plant{
    string name;
    vector <pair <int,int> > places;
    pair <double,double> acid;
    pair <double,double> solar;
    pair <double,double> temp;
    pair <double,double> humid;
public:
    Plant();
    Plant(string name, pair <double,double> acid, pair <double,double> solar, pair <double,double> temp,
        pair <double,double> humid, vector <pair <int,int> > places);
    bool check(pair <int,int> p1, pair <int,int> p2, pair <double,double> acid,
        pair <double,double> solar, pair <double,double> temp,
        pair <double,double> humid);
    friend int compare(Plant first, Plant last);
    bool isConsistentWith(Plant plant);
    friend ostream& operator << (ostream &out,Plant &plant);
    friend istream& operator >> (istream &in,Plant &plant);
    int getPlacesSize();
    pair <int,int> getPlacesElement(int i);
    pair <double,double> getAcid();
    pair <double,double> getSolar();
    pair <double,double> getTemp();
    pair <double,double> getHumid();
};
ostream& operator << (ostream &out,Plant &plant);
istream& operator >> (istream &in,Plant &plant);
bool operator < (Plant first,Plant second);
bool operator > (Plant first,Plant second);
bool operator == (Plant first,Plant second);
bool operator >= (Plant first,Plant second);
bool operator <= (Plant first,Plant second);
bool operator != (Plant first,Plant second);
#endif
