//
//  main.cpp
//  SkiEquipment
//
//  Created by Mikołaj Stępniewski on 17.01.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include "File.hpp"
#include <curses.h>

using namespace std;

string pathCompiler(string s1, string s2, string s3) {
    string absolutePath = "";
    char bs = '/';
    absolutePath = "Data/" + s1 + bs + s2 + bs + s3;
    return absolutePath;
}

string pathCompiler(string s1, string s2, string s3, string s4) {
    string absolutePath = "";
    char bs = '/';
    absolutePath = "Data/" + s1 + bs + s2 + bs + s3 + bs + s4;
    return absolutePath;
}

string pathCompiler(string s1, string s2, string s3, string s4, string s5) {
    string absolutePath = "";
    char bs = '/';
    absolutePath = "Data/" + s1 + bs + s2 + bs + s3 + bs + s4 + bs + s5;
    return absolutePath;
}

int main() {
    Skis *save = NULL;
    string brand, season, category, model, path, type;
    bool compare = 0;
    bool loop = 0;
    char c = '\0';
    try {
        while (!loop){
            
            loop = 0;
            
            File *file= new File();
            
            cout << "Ski equipment > Skis > Brands:\n\n";
            cout << setw(15) << internal << "HEAD" << setw(15) << "Rossignol" << setw(15) << "Voelkl" << setw(15) << "Fischer" << setw(15) << "Atomic" << endl;
            cin >> brand;
            file->ski->setBrand(brand);
            cout << setw(15) << "14-15" << setw(15) << "15-16" << setw(15) << "16-17" << endl;
            cin >> season;
            file->ski->setSeason(season);
            file->readFromPath(pathCompiler(brand, season, "Categories.csv"), file->ski->getCategories());
            cout << endl;
            file->ski->printCategories();
            cin >> category;
            file->ski->setCategory(category);
            file->readFromPath(pathCompiler(brand, season, category, "Models.csv"), file->ski->getModels());
            cout << endl;
            file->ski->printModels();
            cin.ignore();
            getline(cin, model);
            file->ski->setModelName(model);
           
            
            file->readFromPath(pathCompiler(brand, season, category, model, "Technologies.csv"), file->ski->getTechnologies());
            cout << endl;
            file->ski->printTechnologies();
        
            file->readParameters(pathCompiler(brand, season, category, model, "Parameters.csv"), file->ski->getLenghts(), file->ski->getRadius(), file->ski->getSidecut());
            file->ski->printParameters();
            file->ski->printTargetIndicator();
            
            if (compare) {
                file->ski->compare(*save);
                compare = 0;
            }
            
            cout << "\nDo you want to compare to another skis?\n";
            cin >> c;
            if (c == 'Y' || c == 'y') {
                save = *&file->ski;
                for (int i = 0; i < 20; i++) cout << "     ";
                cout << "> Copy created\n";
                compare = 1;
            }
            
            delete file;
            c = '\0';
            
                while (c != 'Y' && c != 'N' & c != 'n' && c != 'y' && !compare) {
                    cout << "Do you want to search for another skis? Y/N\n";
                    cin >> c;
                    if (c == 'N' || c == 'n') loop = 1;
                    cout << endl;
                }
            
        }
    } catch (Error &e) {
        e.what();
    }
    
    delete save;

    return 0;
}
