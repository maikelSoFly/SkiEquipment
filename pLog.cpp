//
//  pLog.cpp
//  SkiEquipment
//
//  Created by Mikołaj Stępniewski on 09.02.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

//pLog is for printing log messages in the right margin

template <typename T>
void printLog(std::string objName, T *t = NULL, char opt = ' ') { /* objName: name of object, *t: pointer to object, opt(c): for constructor,
                                                                        opt(d) - for destructor, opt(p): for printing path of opened file */
    if (t && opt != ' ') {
        for (int i = 0; i < 20; i++) std::cout << "     ";
        switch(opt) {
            case 'c': std::cout << "> "<< objName <<" object (id " << t->id++ << ") created.\n";
                break;
            case 'd': std::cout << "> "<< objName <<" object (iid " << t->iid << ") removed from memory.\n";
                break;
            case 'p': {
                std::cout << "> OPEN: ~/";
                for (int i = 0; i < t->path.length(); ++i) {
                    if (i == 39) {
                        std::cout << std::endl;
                        for (int i = 0; i < 20; i++) std::cout << "     ";
                    }
                    std::cout << t->path[i];
                }
            }
                break;
            default: std::cout << "\n> PrintLog error\n";
        }
    }
    else { //When function is called with only one argument
        for (int i = 0; i < 20; i++) std::cout << "     ";
        std::cout << "> " << objName << std::endl;
    }
}

