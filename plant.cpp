#include <bits/stdc++.h>
#include "plant.h"

using namespace std;

Plant::Plant(){}

Plant::Plant(string name, pair <double,double> acid, pair <double,double> solar, pair <double,double> temp,
        pair <double,double> humid, vector <pair <int,int> > places){
    this->name=name;
    this->acid=acid;
    this->solar=solar;
    this->temp=temp;
    this->humid=humid;
    this->places=places;
}

int compare(Plant first, Plant last){
    if(first.name>last.name){
        return 1;
    }else if(first.name==last.name){
        return 0;
    }
    return -1;
}

bool Plant::check(pair <int,int> p1, pair <int,int> p2, pair <double,double> acid,
        pair <double,double> solar, pair <double,double> temp,
        pair <double,double> humid)
{
    if (p1.first>p2.first)
        swap(p1.first,p2.first);
    if (p1.second>p2.second)
        swap(p1.second,p2.second);
    bool flag = false;
    if (!((this->acid.second >= acid.first) || (this->acid.first <= acid.second)))
        return false;
    if (!((this->solar.second >= solar.first) || (this->solar.first <= solar.second)))
        return false;
    if (!((this->temp.second >= temp.first) || (this->temp.first <= temp.second)))
        return false;
    if (!((this->humid.second >= humid.first) || (this->humid.first <= humid.second)))
        return false;
    for(int i = 0; i < this->places.size(); i++)
        if ((this->places[i].first >= p1.first) &&
            (this->places[i].second >= p1.second) &&
            (this->places[i].first <= p2.first) &&
            (this->places[i].second <= p2.second))
            flag = true;
    return flag;
}

bool Plant::isConsistentWith(Plant plant){
    for(int i=0; i < this->places.size(); i++)
        for(int j=0; j < plant.places.size(); j++)
            if (this->places[i] == plant.places[j])
            {
                if (!((this->acid.second >= plant.acid.first) || (this->acid.first <= plant.acid.second)))
                    return false;
                if (!((this->solar.second >= plant.solar.first) || (this->solar.first <= plant.solar.second)))
                    return false;
                if (!((this->temp.second >= plant.temp.first) || (this->temp.first <= plant.temp.second)))
                    return false;
                if (!((this->humid.second >= plant.humid.first) || (this->humid.first <= plant.humid.second)))
                    return false;
                return true;
            }
    return true;
}

ostream& operator << (ostream &out,Plant &plant){
    out<<plant.name<<'\n'
    <<plant.acid.first<<' '<<plant.acid.second<<'\n'
    <<plant.solar.first<<' '<<plant.solar.second<<'\n'
    <<plant.temp.first<<' '<<plant.temp.second<<'\n'
    <<plant.humid.first<<' '<<plant.humid.second<<'\n'
    <<plant.places.size()<<'\n';
    for(int i = 0; i < plant.places.size(); i++){
        out<<plant.places[i].first<<' '<<plant.places[i].second;
    }
    out<<'\n';
    return out;
}

istream& operator >> (istream &in,Plant &plant){
    int places_size;
    in>>plant.name>>plant.acid.first>>plant.acid.second
    >>plant.solar.first>>plant.solar.second
    >>plant.temp.first>>plant.temp.second
    >>plant.humid.first>>plant.humid.second
    >>places_size;
    plant.places.resize(places_size);
    for(int i = 0; i < places_size; i++){
        in>>plant.places[i].first>>plant.places[i].second;
    }
    return in;
}

bool operator < (Plant first,Plant second){
    return compare(first,second)<0;
}

bool operator > (Plant first,Plant second){
    return compare(first,second)>0;
}

bool operator == (Plant first,Plant second){
    return compare(first,second)==0;
}

bool operator >= (Plant first,Plant second){
    return compare(first,second)>=0;
}

bool operator <= (Plant first,Plant second){
    return compare(first,second)<=0;
}

bool operator != (Plant first,Plant second){
    return compare(first,second)!=0;
}

int Plant::getPlacesSize(){
    return places.size();
}

pair <int,int> Plant::getPlacesElement(int i){
    return places[i];
}

pair <double,double> Plant::getAcid(){
    return acid;
}
pair <double,double> Plant::getSolar(){
    return solar;
}
pair <double,double> Plant::getTemp(){
    return temp;
}
pair <double,double> Plant::getHumid(){
    return humid;
}
