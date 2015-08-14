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
#include "GridMapper.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    dungeon::Rect rect(100, 100);
    dungeon::Rect min(10, 10);
    dungeon::Rect disableSize(5, 5);
    dungeon::Grid grid(rect.width, rect.height, (int)dungeon::SquaresType::Wall);
    dungeon::BSPTree bsp(rect, min);
    dungeon::GridMapper mapper;
    
    mapper.MappingRoom(bsp, grid);
    mapper.DrawRoom(grid, disableSize);
    
    FILE *fp = fopen("test.txt", "w");
    for (int h = 0; h < rect.height; ++h)
    {
        for (int w = 0; w < rect.width; ++w)
        {
            fprintf(fp, "%d", (int)grid[h][w]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    
    return 0;
}
