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
#include "Rect.hpp"

namespace dungeon
{
    class BSPTree
    {
        typedef std::shared_ptr<BSPTree> BSPTreePTr;
        
        BSPTreePtr lhs;
        BSPTreePTr rhs;
        Rect rect;
        
    public:
        /**
         * @brief recursive constructer
         */
        BSPTree(const BSPTree& parent, const Rect&min, const Rect& max)
        : rect(parent.rect)
        {
            
        }
        
        /**
         * @brief initialize constructer
         */
        BSPTree(const Rect& rect, const Rect& min, const Rect& max)
        : rect(rect)
        {
            
        }
    };
}

#endif
