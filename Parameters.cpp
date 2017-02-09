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


list<string> &Parameters::getTechnologies() {
    return _technologies;
}


