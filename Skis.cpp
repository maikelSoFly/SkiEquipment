//
//  Skis.cpp
//  SkiEquipment
//
//  Created by Mikołaj Stępniewski on 17.01.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//

#include "Skis.hpp"
#include <iomanip>
#include <iostream>
using namespace std;

Skis::Skis(string brand, string season) {
    _brand = brand;
    _season = season;
}

Skis::Skis() {
    
}
Skis::~Skis() {
    
}

void Skis::setBrand(string brand) {
    _brand = brand;
}

void Skis::setSeason(string season) {
    _season = season;
}

void Skis::setModelName(string modelName) {
    _modelName = modelName;
}

void Skis::setCategory(string category) {
    _category = category;
}

list<string> &Skis::getCategories() {
    return _categories;
}

list<string> &Skis::getModels() {
    return _models;
}

list<int> &Skis::getLenghts() {
    return _lenghts;
}

list<int> &Skis::getRadius() {
    return _radius;
}

list<int> &Skis::getSidecut() {
    return _sideCut;
}

void Skis::operator=(const Skis& ski) {
    this->_brand = ski._brand;
    this->_category = ski._category;
    this->_modelName = ski._modelName;
    this->_season = ski._season;
    this->_lenghts = ski._lenghts;
    this->_radius = ski._radius;
    this->_sideCut = ski._sideCut;
    this->_technologies = ski._technologies;
    for (int i = 0; i < 9; i++) this->targetIndicator[i] = ski.targetIndicator[i];
}

void Skis::compare(const Skis& ski) {
    cout << endl << "\nSki > COMPARITION\n\n";
    cout << "   Brand:  " <<  this->_brand << "  /  " << ski._brand << endl;
    cout << "   Model:  " << this->_modelName << "  /  " << ski._modelName << endl;
    cout << "   Season:  " << this->_season << "  /  " << ski._season << endl;
    cout << "   Category:  " << this->_category << "  /  " << ski._category << endl << endl;
    cout << "Ski > COMPARITION > Technologies comparition:\n\n";
    
    list<string>::const_iterator i;
    list<string>::const_iterator i2;
    i2 = ski._technologies.begin();
    for( i = _technologies.begin(); i != _technologies.end(); ++i) {
        cout << "    " << *i << endl;
        if (i2 != ski._technologies.end()) cout << "                                               " << *i2;
        ++i2;
    }
    cout << endl << endl;
    
    cout << "Ski > COMPARITION > Parameters comparition:\n\n";
    cout << "    Lenght:  ";
    list<int>::const_iterator iP;
    int itrP = 0;
    for( iP = _lenghts.begin(); iP != _lenghts.end(); ++iP) {
        itrP++;
        cout << *iP;
        if (itrP < 3) {
            cout << " / ";
        }
    }
    itrP = 0;
    cout << "cm        ";
    
    for( iP = ski._lenghts.begin(); iP != ski._lenghts.end(); ++iP) {
        itrP++;
        cout << *iP;
        if (itrP < 3) {
            cout << " / ";
        }
    }
    itrP = 0;
    cout << "cm            " << endl;
    
    cout << "    Radius:  ";
    for( iP = _radius.begin(); iP != _radius.end(); ++iP) {
        itrP++;
        if (*iP != 0)cout << *iP;
        if (itrP < 2) {
            cout << "m for ";
        }
    }cout << "cm            ";
    itrP = 0;
    
    for( iP = ski._radius.begin(); iP != ski._radius.end(); ++iP) {
        itrP++;
        if (*iP != 0)cout << *iP;
        if (itrP < 2) {
            cout << "m for ";
        }
    }cout << "cm\n";
    itrP = 0;
    
    cout << "    Sidecut:  ";
    for( iP = _sideCut.begin(); iP != _sideCut.end(); ++iP) {
        itrP++;
        cout << *iP;
        if (itrP < 3) {
            cout << " / ";
        }
    }
    itrP = 0;
    cout << "           ";
    for( iP = ski._sideCut.begin(); iP != ski._sideCut.end(); ++iP) {
        itrP++;
        cout << *iP;
        if (itrP < 3) {
            cout << " / ";
        }
    }
    cout << endl << endl;

    cout << "Ski > COMPARITION > Advanced level comparition comparition:\n\n";
    cout << "beginiers                             experts"
    << "           "
    << "beginiers                             experts"
    <<"\n    |";
    for (int i = 0; i < 9; i++) {
        if(!targetIndicator[i]) cout << "   |";
        else cout << "///|";
        
    }
    cout << "                   |";
    for (int i = 0; i < 9; i++) {
        if(!ski.targetIndicator[i]) cout << "   |";
        else cout << "///|";
    }
    cout << endl << endl;
    
}

void Skis::printTechnologies() {
    
    cout << "\nSki > " << _brand << " > " << _season << " > " << _category << " > " << _modelName << " > Technologies:\n\n";
    
    list<string>::const_iterator i;
    for( i = _technologies.begin(); i != _technologies.end(); ++i)
        cout << "    " << *i;
    cout << endl;
}

void Skis::printCategories() {
    
    cout << "\nSki > " << _brand << " > " << _season << " > Categories:\n\n";
    
    list<string>::const_iterator i;
    for( i = _categories.begin(); i != _categories.end(); ++i) {
        cout << setw(15) << *i;
    }
    cout << endl;
}

void Skis::printModels() {
    
    cout << "\nSki > " << _brand << " > " << _season << " > " << _category << " > Models:\n\n";
    
    list<string>::const_iterator i;
    for( i = _models.begin(); i != _models.end(); ++i) {
        cout << "    " << *i;
    }
    cout << endl;
}

void Skis::printParameters() {
    
    cout << "\nSki > " << _brand << " > " << _season << " > " << _category << " > " << _modelName << " > Parameters:\n\n";
    cout << "    Lenghts:   ";
    list<int>::const_iterator i;
    int itr = 0;
    for( i = _lenghts.begin(); i != _lenghts.end(); ++i) {
        itr++;
        cout << *i;
        if (itr < 3) {
            cout << " / ";
        }
    }
    itr = 0;
    cout << "cm" << endl;
    cout << "    Radius:    ";
    for( i = _radius.begin(); i != _radius.end(); ++i) {
        itr++;
        if (*i != 0)cout << *i;
        if (itr < 2) {
            cout << "m for ";
        }
    }cout << "cm";
    itr = 0;
    cout << endl;
    cout << "    Sidecut:   ";
    for( i = _sideCut.begin(); i != _sideCut.end(); ++i) {
        itr++;
        cout << *i;
        if (itr < 3) {
            cout << " / ";
        }
    }
    cout << endl;
}
