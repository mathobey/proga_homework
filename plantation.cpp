#include <bits/stdc++.h>
#include "plant.h"
#include "plantation.h"

using namespace std;

void Plantation::add(Plant plant){
    plant_list.push_back(plant);
}

void Plantation::sort(){
    plant_list.sort();
}

void Plantation::addToSorted(Plant plant){
    list<Plant>::iterator it = plant_list.begin();
    bool flag=false;
    while(it!=plant_list.end()){
        if((*it)>=plant){
            plant_list.insert(it,plant);
            flag=true;
        }
    }
    if (!flag){
        plant_list.push_back(plant);
    }
}

void Plantation::write(pair <int,int> p1, pair <int,int> p2, pair <double,double> acid,
        pair <double,double> solar, pair <double,double> temp,
        pair <double,double> humid){
    for(list<Plant>::iterator it = plant_list.begin();it!=plant_list.end();it++){
        if((*it).check(p1,p2,acid,solar,temp,humid)){
            cout<<(*it);
        }
    }
}

void Plantation::remove(pair <int,int> p1, pair <int,int> p2, pair <double,double> acid,
        pair <double,double> solar, pair <double,double> temp,
        pair <double,double> humid){
    for(list<Plant>::iterator it = plant_list.begin();it!=plant_list.end();it++){
        if((*it).check(p1,p2,acid,solar,temp,humid)){
            plant_list.erase(it);
        }
    }
}

vector <pair<int,int>> Plantation::setGoodConditions (vector <pair<int,int>> places){
    vector <pair<int,int>> bad_places;
    for(int k = 0; k<places.size(); k++){
        vector <Plant> current_plants;
        for(list<Plant>::iterator it = plant_list.begin();it!=plant_list.end();it++){
            for(int j = 0; j<(*it).getPlacesSize(); j++){
                if (((*it).getPlacesElement(j).first == places[k].first) && ((*it).getPlacesElement(j).second == places[k].second)){
                    current_plants.push_back((*it));
                    break;
                }
            }
        }
        if (current_plants.size() == 0){
            cout<<"any conditions in "<<places[k].first<<' '<<places[k].second<<'\n';
        }
        else{
            pair <double,double> acid = current_plants[0].getAcid();
            pair <double,double> humid = current_plants[0].getHumid();
            pair <double,double> solar = current_plants[0].getSolar();
            pair <double,double> temp = current_plants[0].getTemp();
            for(int j = 1; j<current_plants.size(); j++){
                if (current_plants[j].getAcid().first > acid.first)
                    acid.first = current_plants[j].getAcid().first;
                if (current_plants[j].getAcid().second < acid.second)
                    acid.second = current_plants[j].getAcid().second;
                if (current_plants[j].getHumid().first > humid.first)
                    humid.first = current_plants[j].getHumid().first;
                if (current_plants[j].getHumid().second < humid.second)
                    humid.second = current_plants[j].getHumid().second;
                if (current_plants[j].getSolar().first > solar.first)
                    solar.first = current_plants[j].getSolar().first;
                if (current_plants[j].getSolar().second < solar.second)
                    solar.second = current_plants[j].getSolar().second;
                if (current_plants[j].getTemp().first > temp.first)
                    temp.first = current_plants[j].getTemp().first;
                if (current_plants[j].getTemp().second < temp.second)
                    temp.second = current_plants[j].getTemp().second;
            }
            if ((acid.second >= acid.first) &&
                (humid.second >= humid.first) &&
                (solar.second >= solar.first) &&
                (temp.second >= temp.first)){
                cout<<"acidity "<<(acid.first+acid.second)/2
                <<" luminosity "<<(solar.first+solar.second)/2
                <<" temperature "<<(temp.first+temp.second)/2
                <<" humidity "<<(humid.first+humid.second)/2
                <<" in "<<places[k].first<<' '<<places[k].second<<'\n';
            }else{
                bad_places.push_back(places[k]);
            }
        }
    }
    for(int k = 0; k<bad_places.size(); k++){
        cout<<"no good conditions in "<<bad_places[k].first<<' '<<bad_places[k].second<<'\n';
    }
    return bad_places;
}

ostream& operator << (ostream &out,Plantation &plantation){
    out<<plantation.plant_list.size()<<'\n';
    for(list<Plant>::iterator it = plantation.plant_list.begin(); it!=plantation.plant_list.end(); it++){
        out<<(*it);
    }
    out<<'\n';
    return out;
}

istream& operator >> (istream &in,Plantation &plantation){
    int plantation_size;
    in>>plantation_size;
    plantation.plant_list.resize(plantation_size);
    for(list<Plant>::iterator it = plantation.plant_list.begin(); it!=plantation.plant_list.end(); it++){
        in>>(*it);
    }
    return in;
}
