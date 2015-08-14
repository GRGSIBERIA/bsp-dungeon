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

int main(int argc, const char * argv[]) {
    // insert code here...
    
    dungeon::Rect rect(100, 100);
    dungeon::Rect min(8, 8);
    dungeon::RectSpliter split(rect, min);
    dungeon::Grid grid(100, 100, (int)dungeon::SquaresType::Wall);
    
    auto lhs = split.Lhs();
    auto rhs = split.Rhs();
    
    printf("lhs: %d, %d\n", lhs.width, lhs.height);
    printf("rhs: %d, %d\n", rhs.width, rhs.height);
    
    lhs.Padded(2).Draw(grid);
    
    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL)
        exit(0);
    
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            fprintf(fp, "%d", grid[j][i]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    
    return 0;
}
