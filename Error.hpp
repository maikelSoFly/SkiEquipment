//
//  Error.hpp
//  SkiEquipment
//
//  Created by Mikołaj Stępniewski on 20.01.2017.
//  Copyright © 2017 Mikołaj Stępniewski. All rights reserved.
//

class Error {
    int noError;
    
public:
    
    Error(int e);
    ~Error();
    
    enum {Brand, Season, Category, Model};
    void what();
};
