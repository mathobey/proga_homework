#include <bits/stdc++.h>
#include "plant.h"
#include "plantation.h"

using namespace std;

enum Command {
    Add,
    Sort,
    AddToSorted,
    Find,
    Delete,
    Load,
    Save,
    Clear,
    Exit,
    Help,
    Square,
    Incorrect
};

Command readCommand(){
    string s;
    cin>>s;
    if (stricmp(s.c_str(),"Help")==0) return Help;
    if (stricmp(s.c_str(),"Clear")==0) return Clear;
    if (stricmp(s.c_str(),"Load")==0) return Load;
    if (stricmp(s.c_str(),"Save")==0) return Save;
    if (stricmp(s.c_str(),"Add")==0) return Add;
    if (stricmp(s.c_str(),"AddToSorted")==0) return AddToSorted;
    if (stricmp(s.c_str(),"Sort")==0) return Sort;
    if (stricmp(s.c_str(),"Find")==0) return Find;
    if (stricmp(s.c_str(),"Delete")==0) return Delete;
    if (stricmp(s.c_str(),"Exit")==0) return Exit;
    if (stricmp(s.c_str(),"Square")==0) return Square;
    return Incorrect;
}

int main()
{
    Plantation plantation;
    bool not_exit = true;
    while(not_exit){
        Command s = readCommand();
        switch(s){
        case Add:
        {
            Plant plant;
            cin>>plant;
            plantation.add(plant);
            break;
        }
        case Sort:
        {
            plantation.sort();
            break;
        }
        case AddToSorted:
        {
            Plant plant;
            cin>>plant;
            plantation.addToSorted(plant);
            break;
        }
        case Find:
        {
            pair <int,int> p1,p2;
            cin>>p1.first>>p1.second>>p2.first>>p2.second;
            pair <double,double> acid;
            cin>>acid.first>>acid.second;
            pair <double,double> solar;
            cin>>solar.first>>solar.second;
            pair <double,double> temp;
            cin>>temp.first>>temp.second;
            pair <double,double> humid;
            cin>>humid.first>>humid.second;
            plantation.write(p1,p2,acid,solar,temp,humid);
            break;
        }
        case Delete:
        {
            pair <int,int> p1,p2;
            cin>>p1.first>>p1.second>>p2.first>>p2.second;
            pair <double,double> acid;
            cin>>acid.first>>acid.second;
            pair <double,double> solar;
            cin>>solar.first>>solar.second;
            pair <double,double> temp;
            cin>>temp.first>>temp.second;
            pair <double,double> humid;
            cin>>humid.first>>humid.second;
            plantation.remove(p1,p2,acid,solar,temp,humid);
            break;
        }
        case Load:
        {
            string file;
            cin>>file;
            ifstream in(file);
            in>>plantation;
            in.close();
            break;
        }
        case Save:
        {
            string file;
            cin>>file;
            ofstream out(file);
            out<<plantation;
            out.close();
            break;
        }
        case Clear:
        {
            Plantation clear_plantation;
            plantation = clear_plantation;
            break;
        }
        case Exit:
        {
            not_exit = false;
            break;
        }
        case Help:
        {
            cout<<"help - display help text\n"
            <<"save <file_name> - save plantation in file\n"
            <<"load <file_name> - load plantation from file\n"
            <<"clear - clear plantation\n"
            <<"add <plant_name> <minimal_acidity, maximal_acidity> <minimal_luminosity, maximal_luminosity> "
            <<"<minimal_temperature, maximal_temperature> <minimal_humidity, maximal_humidity> "
            <<"<number_of_plants> <x_1,y_1> ... <x_n,y_n> - add plant to plantation ('n' is number of plants)\n"
            <<"add_to_sorted (same input as in ""add"")- add plant to plantation considering sorting\n"
            <<"sort -  sort plantation\n"
            <<"find <x1,y1> <x2,y2> <minimal_acidity, maximal_acidity> <minimal_luminosity, maximal_luminosity> "
            <<"<minimal_temperature, maximal_temperature> <minimal_humidity, maximal_humidity> - display plants satisfying the conditions\n"
            <<"delete (same input as in ""find"")  - delete plants satisfying the conditions\n"
            <<"square <x> <y> - set good conditions in (x, y)"
            <<"exit - exit the programme\n";
            cout<<s;
            break;
        }
        case Square:
        {
            pair <int,int> p;
            cin>>p.first>>p.second;
            vector <pair<int,int> > places;
            places.push_back(p);
            plantation.setGoodConditions(places);
        }
        case Incorrect:
            cout<<"Unknown command"<<'\n';
        }
    }
    return 0;
}
