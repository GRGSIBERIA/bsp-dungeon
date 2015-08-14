//
//  main.cpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/12.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#include <iostream>
#include <random>
#include <stdio.h>
#include "Rect.hpp"
#include "RectSpliter.hpp"
#include "BSPTree.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    dungeon::Rect rect(100, 100);
    dungeon::Rect min(8, 8);
    dungeon::Grid grid(rect.width, rect.height, (int)dungeon::SquaresType::Wall);
    dungeon::BSPTree bsp(rect, min);
    
    return 0;
}
