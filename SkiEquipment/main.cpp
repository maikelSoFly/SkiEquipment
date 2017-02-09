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

void askQuestion (string, bool&, string = "");
string pathCompiler(string = "", string = "", string = "", string = "", string = "");

int main() {
    
//  ••••••••••••••••••••••
    File writeFile;
    Skis *save = NULL;
    
    string brand, season, category, model, writePath;
    
//  flags
    bool cmpFlag = false;
    bool loopFlag = true;
    bool saveFlag = false;
    bool exceptionFlag = false;
//  ••••••••••••••••••••••
    
    
    while (loopFlag){
        
        File *file= new File();
        
        cout << "Ski equipment > Skis > Brands:\n\n";
        cout << setw(20) << "• HEAD •"
             << setw(25) << "• Rossignol •"
             << setw(20) << "• Voelkl •"
             << setw(20) << "• Fischer •"
             << setw(20) << "• Atomic •"
             << endl;
        
        do {
            exceptionFlag = false;
            try {
                
                cin >> brand;
                file->ski->setBrand(brand);
            }
            catch (Error &e) {
                e.what();
                exceptionFlag = true;
            }
            
        }while (exceptionFlag);
            
        cout << setw(21) << "• 14-15 •"
             << setw(25) << "• 15-16 •"
             << setw(25) << "• 16-17 •"
             << endl;
        
        do {
            exceptionFlag = false;
            try {
                
                cin >> season;
                file->ski->setSeason(season);
            }
            catch (Error &e) {
                e.what();
                exceptionFlag = true;
            }
            
        }while (exceptionFlag);
        
        file->readFromPath(pathCompiler(file->ski->getBrand(),
                                        file->ski->getSeason(),
                                        "Categories.csv"),
                           file->ski->getCategories());
        
        cout << endl;
        file->ski->printCategories();
        
        do {
            exceptionFlag = false;
            try {
                
                cin >> category;
                file->ski->setCategory(category);
            }
            catch (Error &e) {
                e.what();
                exceptionFlag = true;
            }
            
        }while (exceptionFlag);
        
        file->readFromPath(pathCompiler(file->ski->getBrand(),
                                        file->ski->getSeason(),
                                        file->ski->getCategory(),
                                        "Models.csv"),
                           file->ski->getModels());
        
        cout << endl;
        file->ski->printModels();
        
        cin.ignore();
        do {
            exceptionFlag = false;
            try {
                
                getline(cin, model);
                file->ski->setModelName(model);
            }
            catch (Error &e) {
                e.what();
                exceptionFlag = true;
            }
            
        }while (exceptionFlag);
        
        file->readFromPath(pathCompiler(file->ski->getBrand(),
                                        file->ski->getSeason(),
                                        file->ski->getCategory(),
                                        file->ski->getModelName(),
                                        "Technologies.csv"),
                           file->ski->getTechnologies());
        
        cout << endl;
        if (!cmpFlag)
            file->ski->printTechnologies();
        
        file->readParameters(pathCompiler(file->ski->getBrand(),
                                          file->ski->getSeason(),
                                          file->ski->getCategory(),
                                          file->ski->getModelName(),
                                          "Parameters.csv"),
                             file->ski->getLenghts(),
                             file->ski->getRadius(),
                             file->ski->getSidecut());
        if (!cmpFlag) {
            file->ski->printParameters();
            file->ski->printTargetIndicator();
        }
        
        
        if (cmpFlag) {
            if (file->ski->getModelName() != save->getModelName()) {
                file->ski->compare(*save);
                cmpFlag = false;
            }
            else cout << "\n> Comparison of identical skis. Try again.\n";
        }
        
        if (!cmpFlag)
        askQuestion("Do you want to compare to another skis?", cmpFlag, "Copy created.");
        
        save = file->ski; //Saving last skis everytime
        delete file;

        if (!cmpFlag)
            askQuestion("Do you want to search for another skis?", loopFlag);
        
    }
    
    askQuestion("Do you want to save details of last skis?", saveFlag);
    if (saveFlag) {
        bool writeOK = false;
        cout << "\n> Type location to save skis details";
        do {
            cout << "\n> ~/";
            cin >> writePath;
            string fileName = save->getModelName() + "(details).csv";
            writeOK = writeFile.writeToLocation(pathCompiler(writePath, fileName), save);
        } while (!writeOK);
    }
    
    delete save;
    printLog<File>("Copy removed from memory.");

    return 0;
}




void askQuestion (string qst, bool &flag, string mssg) {

    char answ = '\0';
    cout << endl << qst << " Y/N\n";
    
    while(answ != 'Y' && answ != 'y' && answ != 'N' && answ != 'n') {
        cin >> answ;
    }
    
    if (answ == 'Y' || answ == 'y') {
        flag = true;
        if (mssg != "")
            printLog<File>(mssg);
    }
    else flag = false;
}

string pathCompiler(string s1, string s2, string s3, string s4, string s5) {
    char bs = '/';
    string absolutePath = s1 + bs + s2;
    if(s3 != "") {
        absolutePath = "Data/" + s1 + bs + s2 + bs + s3;
        if (s4 != "") absolutePath += bs + s4; {
            if (s5 != "") absolutePath += bs + s5;
        }
    }
    return absolutePath;
}
