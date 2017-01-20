//
//  Skis.hpp
//  SkiEquipment
//
//  Created by Mikołaj Stępniewski on 17.01.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//



#include <stdio.h>
#include <string>
#include "Parameters.hpp"
#include <list>

class Skis : public Parameters {
    std::string _brand;
    std::string _season;
    std::string _category;
    std::string _modelName;
    std::list<std::string> _models;
    std::list<std::string> _categories;
    friend class File;

public:
    Skis();
    Skis(std::string);
    Skis(std::string, std::string);
    ~Skis();
    
    std::list<std::string> &getCategories();
    std::list<std::string> &getModels();
    std::list<int> &getLenghts();
    std::list<int> &getRadius();
    std::list<int> &getSidecut();
    
    void setBrand(std::string);
    void setSeason(std::string);
    void setModelName(std::string);
    void setCategory(std::string);
    
    void compare(const Skis&);
    void printTechnologies();
    void printCategories();
    void printModels();
    void printParameters();
    
    void operator=(const Skis&);
    
};