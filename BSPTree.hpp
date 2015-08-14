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
#include "Grid.hpp"

namespace dungeon
{
    class BSPTree
    {
        typedef std::shared_ptr<BSPTree> BSPTreePtr;
        
        BSPTreePtr lhs;
        BSPTreePtr rhs;
        Rect rect;
        bool hasLeaves;
        
        void init(RectSpliter& split, const Rect& min, bool isVertical)
        {
            hasLeaves = split.EnableSplit();
            if (hasLeaves)
            {
                lhs = BSPTreePtr(new BSPTree(split.Lhs(), min, isVertical));
                rhs = BSPTreePtr(new BSPTree(split.Rhs(), min, isVertical));
            }
        }
        
    public:
        /**
         * @brief initialize constructer
         */
        BSPTree(const Rect& rect, const Rect& min)
        : rect(rect), lhs(nullptr), rhs(nullptr)
        {
            RectSpliter split(rect, min);
            init(split, min, split.IsVertical());
        }
        
        BSPTree(const Rect& rect, const Rect& min, bool isVertical)
        : rect(rect), lhs(nullptr), rhs(nullptr)
        {
            RectSpliter split(rect, min);
            init(split, min, isVertical);
        }
        
        bool HasLeaves() const { return hasLeaves; }
        const Rect& Rect() const { return rect; }
    };
}

#endif
