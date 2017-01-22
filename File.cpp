//
//  File.cpp
//  SkiEquipment
//
//  Created by Mikołaj Stępniewski on 17.01.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//

#include "File.hpp"
#include <iostream>
#include <sstream>
using namespace std;

int File::id = 0;

File::File(){
    ski = new Skis();
    iid = id;
    for (int i = 0; i < 20; i++) cout << "     ";
    cout << "> File object (id " << id++ << ") created.\n";
    
}

File::~File() {
    for (int i = 0; i < 20; i++) cout << "     ";
    cout << "> File object (iid " << iid << ") removed from memory.\n";
}

void File::readFromPath(string _path, list<string> &list) {
    
    string field;
    path = _path;
    file.open(path, ios::in);
    
    if(file.good()) {
        
        while(!file.eof()) {
            
            if (_path.find("Categories") != std::string::npos) {
                file >> field;
            }
            else getline(file, field, '\n');
            
            list.push_back(field);
        }
        
        for (int i = 0; i < 20; i++) cout << "     ";
        cout << "> OPEN: ~/";
        for (int i = 0; i < _path.length(); ++i) {
            if (i == 39) {
                cout << endl;
                for (int i = 0; i < 20; i++) cout << "     ";
            }
            cout << _path[i];
        }

        file.close();
    } else cout << "\n> Reading from file failed!\n";
    
}

void File::readParameters(string _path,
                          list<int> &lenghts,
                          list<double> &radius,
                          list<int> &sideCut) {
    string field;
    path = _path;
    file.open(path, ios::in);
    
    if(file.good()){
        
         for (int i = 0; i < 3; i++) {
            getline(file, field, ';');
            if (field != "\n") {
            lenghts.push_back(stoi(field));
            }
        }
        
        for (int i = 0; i < 3; i++) {
            getline(file, field, ';');
            radius.push_back(stoi(field));
        }
        
        for (int i = 0; i < 3; i++) {
            getline(file, field, ';');
            sideCut.push_back(stoi(field));
        }
        
        while(!file.eof()) {
            getline(file, field, ';');
            ski->targetIndicator[stoi(field)] = 1;
        }
        
        for (int i = 0; i < 20; i++) cout << "     ";
        cout << "> OPEN: ~/";
        for (int i = 0; i < _path.length(); ++i) {
            if (i == 39) {
                cout << endl;
                for (int i = 0; i < 20; i++) cout << "     ";
            }
            cout << _path[i];
        }

        
        file.close();
        
    }else cout << "\n> Reading from file failed (Paramaters)\n";
}

bool File::writeToLocation(string _path,  Skis*& ski) {
    
    file.open(_path, ios::out);
    if (file.good()) {
        list<int>::const_iterator iP;
        list<double>::const_iterator iPd;
        file
        << "Brand:;" << ski->_brand
        << ";;" << "Lenghts:;";
        
        for (iP = ski->_lenghts.begin(); iP != ski->_lenghts.end(); ++iP) {
            file << *iP << ";";
        }
    
        file
        << "\nSeason:;" << ski->_season
        << ";;" << "Sidecut:;";
        
        
        for (iP = ski->_sideCut.begin(); iP != ski->_sideCut.end(); ++iP) {
            file << *iP << ";";
        }
        
        file
        << "\nCategory:;" << ski->_category
        << ";;" << "Radius:;";
        int itr = 0;
        for( iPd = ski->_radius.begin(); iPd != ski->_radius.end(); ++iPd) {
            itr++;
            if (*iPd != 0){
                double db = *iPd;
                if (db > 100 && itr < 2)
                    file << db/10;
                else file << db;
            }
            if (itr < 2) {
                file << ";m for;";
            }
        }file << ";cm";

        
        file
        << "\nModel:;" << ski->_modelName << endl << endl
        << "TECHNOLOGIES: \n\n";
        
        list<string>::const_iterator i;
        
        
        for( i = ski->_technologies.begin(); i != ski->_technologies.end(); ++i) {
            string st = *i;
            st.erase(st.size()-1);
            file << st << endl;
        }

        file.close();
        cout << "\n> Details saved to: ~/" << _path << endl;
        return true;
        
    } else cout << "\n> Writing to this location failed. Try again\n";
   
    return false;
}
