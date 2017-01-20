//
//  Error.cpp
//  SkiEquipment
//
//  Created by Mikołaj Stępniewski on 20.01.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//

#include "Error.hpp"

#include <iostream>
using namespace std;

Error::Error(int e) {
    noError = e;
}

void Error::what() {
    
    switch (noError) {
        case Brand:
            cout << "\nSorry, there is no such brand.\n";
            break;
        case Season:
            cout << "\nSorry, there is no such season.\n";
            break;
        case Category:
            cout << "\nSorry, there is no such category.\n";
            break;
        case Model:
            cout << "\nSory, there is no such model.\n";
            break;
        default:
            break;
    }
}

Error::~Error() {
    
}
