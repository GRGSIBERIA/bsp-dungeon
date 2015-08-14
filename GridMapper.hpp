//
//  GridMapper.hpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/14.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#ifndef DungeonMaker_GridMapper_hpp
#define DungeonMaker_GridMapper_hpp

#include <vector>
#include "BSPTree.hpp"

namespace dungeon
{
    class GridMapper
    {
        std::vector<const Rect*> rects;
        std::vector<const BSPTreePtr> trees;
        
        void RecursiveMappingRoom(const BSPTreePtr& tree, Grid& grid)
        {
            if (tree->Lhs() == nullptr || tree->Rhs() == nullptr)
            {
                rects.push_back(&tree->Rect());
                trees.push_back(tree);
            }
            else
            {
                RecursiveMappingRoom(tree->Lhs(), grid);
                RecursiveMappingRoom(tree->Rhs(), grid);
            }
        }
        
    public:
        void MappingRoom(const BSPTree& topTree, Grid& grid)
        {
            RecursiveMappingRoom(topTree.Lhs(), grid);
            RecursiveMappingRoom(topTree.Rhs(), grid);
        }
        
        void DrawRoom(Grid& grid, const Rect& min)
        {
            for (const auto& rect : rects)
            {
                auto padded = rect->Room(2);
                padded.Draw(grid, min);
            }
        }
    };
}

#endif
