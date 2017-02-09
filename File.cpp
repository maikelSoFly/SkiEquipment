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

File::File() : iid(id) {
    ski = new Skis();
    printLog("File", this, 'c');
    
}

File::~File() {
    printLog("File", this, 'd');
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
        
        printLog("File", this, 'p');

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
        
        printLog("File", this, 'p');

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


