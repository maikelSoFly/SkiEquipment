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
    static int id;
    int iid;
    
    
    template <typename T>
    friend void printLog(std::string, T *, char);
    friend void printLog(std::string);
    
public:
    
    File();
    ~File();
    
    Skis *ski;
    
    void readTechnologies(std::string);
    void readCategories(std::string);
    void readModels(std::string);
    void readFromPath(std::string, std::list<std::string>&);
    void readParameters(std::string,
                        std::list<int>&,
                        std::list<double>&,
                        std::list<int>&);
    bool writeToLocation(std::string,  Skis*&);
    
};
