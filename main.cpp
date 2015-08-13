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
#include "RectSpliter.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    dungeon::Rect rect(100, 100);
    dungeon::Rect min(8, 8);
    dungeon::RectSpliter split(rect, min);
    
    auto lhs = split.Lhs();
    auto rhs = split.Rhs();
    
    printf("lhs: %d, %d\n", lhs.width, lhs.height);
    printf("rhs: %d, %d\n", rhs.width, rhs.height);
    
    return 0;
}
