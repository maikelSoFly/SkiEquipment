//
//  File.hpp
//  SkiEquipment
//
//  Created by Mikołaj Stępniewski on 17.01.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//
#include <fstream>
#include <string>
#include "Skis.hpp"
#include <list>

class File {
    std::fstream file;
    std::string path;
    std::string type;
    int size;
    
    
public:
    File();
    ~File();
    Skis *ski;
    void readTechnologies(std::string);
    void readCategories(std::string);
    void readModels(std::string);
    void readFromPath(std::string, std::list<std::string>&);
    void readParameters(std::string, std::list<int>&, std::list<int>&, std::list<int>&);
    
};
