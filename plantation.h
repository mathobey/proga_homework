#include <iostream>

using namespace std;

#ifndef TESTBASE_H
#define TESTBASE_H

class Plantation{
    list <Plant> plant_list;
public:
    void add(Plant plant);
    void sort();
    void addToSorted(Plant plant);
    void write(pair <int,int> p1, pair <int,int> p2, pair <double,double> acid,
        pair <double,double> solar, pair <double,double> temp,
        pair <double,double> humid);
    void remove(pair <int,int> p1, pair <int,int> p2, pair <double,double> acid,
        pair <double,double> solar, pair <double,double> temp,
        pair <double,double> humid);
    vector <pair<int,int>> setGoodConditions (vector <pair<int,int> > places);
    friend ostream& operator << (ostream &out, Plantation &plantation);
    friend istream& operator >> (istream &in, Plantation &plantation);
};

ostream& operator << (ostream &out, Plantation &plantation);
istream& operator >> (istream &in, Plantation &plantation);

#endif
