//
//  dungeon.hpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/12.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#ifndef DungeonMaker_Dungeon_hpp
#define DungeonMaker_Dungeon_hpp

#include "Grid.hpp"

namespace dungeon
{
    /**
     * @brief Dungeon generator
     */
    class DungeonGenerator
    {
        Rect size;
        
    public:
        DungeonGenerator(const Rect& dungeonSize)
        : size(dungeonSize) {}
    };
}

#endif
