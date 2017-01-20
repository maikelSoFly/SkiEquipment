//
//  Parameters.cpp
//  SkiEquipment
//
//  Created by Mikołaj Stępniewski on 17.01.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//

#include "Parameters.hpp"
#include <iostream>
using namespace std;

void Parameters::printTargetIndicator() {
    cout << endl << "Advanced level:\n";
    cout << "beginiers                             experts\n    |";
    for (int i = 0; i < 9; i++) {
        if(!targetIndicator[i]) cout << "   |";
        else cout << "///|";
    }
    cout << endl << endl;
}

void Parameters::setTargetIndicator() {
    
}

list<string> &Parameters::getTechnologies() {
    return _technologies;
}
