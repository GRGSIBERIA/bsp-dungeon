//
//  BSPTree.hpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/13.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#ifndef DungeonMaker_BSPTree_hpp
#define DungeonMaker_BSPTree_hpp

#include <memory>
#include "RectSpliter.hpp"

namespace dungeon
{
    class BSPTree
    {
        typedef std::shared_ptr<BSPTree> BSPTreePtr;
        
        BSPTreePtr lhs;
        BSPTreePtr rhs;
        Rect rect;
        bool hasLeaves;
        
    public:
        /**
         * @brief initialize constructer
         */
        BSPTree(const Rect& rect, const Rect& min)
        : rect(rect), lhs(nullptr), rhs(nullptr)
        {
            RectSpliter split(rect, min);
            
            if (hasLeaves = split.EnableSplit())
            {
                lhs = BSPTreePtr(new BSPTree(split.Lhs(), min));
                rhs = BSPTreePtr(new BSPTree(split.Rhs(), min));
            }
        }
        
        bool HasLeaves() const { return hasLeaves; }
    };
}

#endif
