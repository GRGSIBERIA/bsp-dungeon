//
//  GridSplitter.hpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/13.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#ifndef DungeonMaker_GridSplitter_hpp
#define DungeonMaker_GridSplitter_hpp

#include "Grid.hpp"

namespace dungeon
{
    class GridSplitter
    {
    public:
        Grid<int> Sprit(const Grid<int>& grid) const
        {
            return Grid<int>(grid.Width(), grid.Height(), 0);
        }
    };
}

#endif
