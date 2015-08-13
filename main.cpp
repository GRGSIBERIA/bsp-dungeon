//
//  main.cpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/12.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#include <iostream>
#include <random>
#include "Rect.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    dungeon::Rect r(10, 10);
    printf("%d, %d\n", r.width, r.height);
    
    std::random_device rd;
    std::uniform_int_distribution<int> uid(0, 10);
    
    printf("%d", uid(rd));
    
    return 0;
}
