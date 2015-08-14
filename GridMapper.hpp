//
//  GridMapper.hpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/14.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#ifndef DungeonMaker_GridMapper_hpp
#define DungeonMaker_GridMapper_hpp

#include <iostream>
#include <stdio.h>
#include "BSPTree.hpp"

namespace dungeon
{
    class GridMapper
    {
        void RecursiveMappingRoom(const BSPTreePtr& tree, Grid& grid, const Rect& min)
        {
            if (tree->Lhs() == nullptr || tree->Rhs() == nullptr)
            {
                tree->Rect().Padded(2).Draw(grid, min);
            }
            else
            {
                RecursiveMappingRoom(tree->Lhs(), grid, min);
                RecursiveMappingRoom(tree->Rhs(), grid, min);
            }
        }
        
    public:
        void MappingRoom(const BSPTree& topTree, Grid& grid, const Rect& min)
        {
            RecursiveMappingRoom(topTree.Lhs(), grid, min);
            RecursiveMappingRoom(topTree.Rhs(), grid, min);
        }
    };
}

#endif
