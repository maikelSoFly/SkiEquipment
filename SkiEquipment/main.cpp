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

using namespace std;

string pathCompiler(string s1, string s2) { //This one is only for writing to a file
    string absolutePath = "";
    char bs = '/';
    absolutePath = s1 + bs + s2;
    return absolutePath;
}

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
    bool isOK;
    File writeFile;
    string writePath;
    char willSave = 0;
    
    while (!loop){
        
        loop = 0;
        
        File *file= new File();
        
        cout << "Ski equipment > Skis > Brands:\n\n";
        cout
        << setw(15) << "HEAD"
        << setw(15) << "Rossignol"
        << setw(15) << "Voelkl"
        << setw(15) << "Fischer"
        << setw(15) << "Atomic"
        << endl;
        
        do {
            isOK = 1;
            try {
                
                cin >> brand;
                file->ski->setBrand(brand);
            }
            catch (Error &e) {
                e.what();
                isOK = 0;
            }
            
        }while (isOK == 0);
            
        cout
        << setw(15) << "14-15"
        << setw(15) << "15-16"
        << setw(15) << "16-17"
        << endl;
        
        do {
            isOK = 1;
            try {
                
                cin >> season;
                file->ski->setSeason(season);
            }
            catch (Error &e) {
                e.what();
                isOK = 0;
            }
            
        }while (isOK == 0);
        
        file->readFromPath(pathCompiler(file->ski->getBrand(),
                                        file->ski->getSeason(),
                                        "Categories.csv"),
                           file->ski->getCategories());
        
        cout << endl;
        file->ski->printCategories();
        
        do {
            isOK = 1;
            try {
                
                cin >> category;
                file->ski->setCategory(category);
            }
            catch (Error &e) {
                e.what();
                isOK = 0;
            }
            
        }while (isOK == 0);
        
        file->readFromPath(pathCompiler(file->ski->getBrand(),
                                        file->ski->getSeason(),
                                        file->ski->getCategory(),
                                        "Models.csv"),
                           file->ski->getModels());
        
        cout << endl;
        file->ski->printModels();
        
        cin.ignore();
        do {
            isOK = 1;
            try {
                
                getline(cin, model);
                file->ski->setModelName(model);
            }
            catch (Error &e) {
                e.what();
                isOK = 0;
            }
            
        }while (isOK == 0);
        
        file->readFromPath(pathCompiler(file->ski->getBrand(),
                                        file->ski->getSeason(),
                                        file->ski->getCategory(),
                                        file->ski->getModelName(),
                                        "Technologies.csv"),
                           file->ski->getTechnologies());
        
        cout << endl;
        file->ski->printTechnologies();
        
        file->readParameters(pathCompiler(file->ski->getBrand(),
                                          file->ski->getSeason(),
                                          file->ski->getCategory(),
                                          file->ski->getModelName(),
                                          "Parameters.csv"),
                             file->ski->getLenghts(),
                             file->ski->getRadius(),
                             file->ski->getSidecut());
        
        file->ski->printParameters();
        file->ski->printTargetIndicator();
        
        
        if (compare) {
            file->ski->compare(*save);
            compare = 0;
        }
        
        cout << "\nDo you want to compare to another skis? Y/N\n";
        cin >> c;
        if (c == 'Y' || c == 'y') {
            for (int i = 0; i < 20; i++) cout << "     ";
            cout << "> Copy created\n";
            compare = 1;
        }
        
        save = *&file->ski; //Saving last skis everytime
        delete file;
        c = '\0';
        
            while (c != 'Y' && c != 'N' & c != 'n' && c != 'y' && !compare) {
                cout << "Do you want to search for another skis? Y/N\n";
                cin >> c;
                if (c == 'N' || c == 'n') loop = 1;
                cout << endl;
            }
        
    }
    
    cout << "> Do you want to save details of last skis? Y/N\n";
    cin >> willSave;
    
    if (willSave == 'Y' || willSave == 'y') {
        bool writeOK = 0;
        cout << "\n> Type location to save skis details";
        do {
            cout << "\n> ~/";
            cin >> writePath;
            string fileName = save->getModelName() + "(details).csv";
            writeOK = writeFile.writeToLocation(pathCompiler(writePath, fileName), save);
        } while (!writeOK);
    }
    
    delete save;

    return 0;
}
