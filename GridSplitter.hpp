//
//  GridSplitter.hpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/13.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#ifndef DungeonMaker_GridSplitter_hpp
#define DungeonMaker_GridSplitter_hpp

#include <memory>
#include "Grid.hpp"

namespace dungeon
{
    class GridSplitter
    {
    public:
        static GridPtr Sprit(const Grid& grid) const
        {
            return GridPtr(new Grid(grid.Width(), grid.Height(), 0));
        }
    };
}

#endif
