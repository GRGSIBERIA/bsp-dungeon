//
//  main.cpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/12.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#include <iostream>
#include "Dungeon.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    dungeon::Grid<int> hoge(10, 10, 10);
    
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; j++)
            printf("%d,", hoge[j][i]);
        printf("\n");
    }
    
    return 0;
}
