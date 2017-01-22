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
    for (int i = 0; i < 20; i++) cout << "     ";
    cout << "> Exception " << noError;
}

void Error::what() {
    
    switch (noError) {
        case Brand:
            cout << "\n> Sorry, there is no such brand. Try again...\n";
            break;
        case Season:
            cout << "\n> Sorry, there is no such season. Try again...\n";
            break;
        case Category:
            cout << "\n> Sorry, there is no such category. Try again...\n";
            break;
        case Model:
            cout << "\n> Sory, there is no such model. Try again...\n";
            break;
        default:
            break;
    }
}

Error::~Error() {
    
}
