//
//  Parameters.hpp
//  SkiEquipment
//
//  Created by Mikołaj Stępniewski on 17.01.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//



#include <stdio.h>
#include <string>
#include <list>
#include <iostream>

class Parameters {
    
protected:
    std::list<int> _lenghts;
    std::list<double> _radius;
    std::list<int> _sideCut;
    std::list<std::string> _technologies;
    bool targetIndicator[9];
    std::string path; //hack for printLog
    
public:
    
    virtual void printTargetIndicator() = 0;
    virtual std::list<std::string> &getTechnologies();
};




