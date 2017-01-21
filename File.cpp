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

File::File(){
    ski = new Skis();
    for (int i = 0; i < 20; i++) cout << "     ";
    cout << "> File object created\n";
}

File::~File() {
    for (int i = 0; i < 20; i++) cout << "     ";
    cout << "> File object removed from memory\n";
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
        
        file.close();
    } else cout << "\n> Reading file error!\n";
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
        file.close();
        
    }else cout << "\n> Reading file error (Paramaters)\n";
}
