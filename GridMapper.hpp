//
//  GridMapper.hpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/14.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#ifndef DungeonMaker_GridMapper_hpp
#define DungeonMaker_GridMapper_hpp

#include "BSPTree.hpp"

namespace dungeon
{
    class GridMapper
    {
        void RecursiveMappingRoom(const BSPTree& tree, Grid& grid)
        {
            if (tree.Lhs() == nullptr || tree.Rhs() == nullptr)
                tree.Rect().Room(2).Draw(grid);
            else
            {
                RecursiveMappingRoom(*tree.Lhs(), grid);
                RecursiveMappingRoom(*tree.Rhs(), grid);
            }
        }
        
    public:
        
        void MappingRoom(const BSPTree& topTree, Grid& grid)
        {
            RecursiveMappingRoom(topTree, grid);
        }
    };
}

#endif
