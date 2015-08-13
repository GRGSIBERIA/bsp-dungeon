//
//  RectSpliter.hpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/13.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#ifndef DungeonMaker_RectSpliter_hpp
#define DungeonMaker_RectSpliter_hpp

#include <random>
#include "Rect.hpp"

namespace dungeon
{
    class RectSpliter
    {
        static std::random_device rd;
        
        const Rect& rect;
        const Rect& min;
        const Rect& max;
        
        Rect lhs;
        Rect rhs;
        
        void SplitVertical()
        {
            lhs.width = rect.width;
            rhs.width = rect.width;
            rhs.x = rect.x;
            
            int size = std::uniform_int_distribution<int>(min.height, max.height)(rd);
            lhs.height = size;
            rhs.height = rect.height - size;
            
            rhs.y = rect.y + size;
        }
        
        void SplitHorizontal()
        {
            lhs.height = rect.height;
            rhs.height = rect.height;
            rhs.y = rect.y;
            
            int size = std::uniform_int_distribution<int>(min.width, max.width)(rd);
            lhs.width = size;
            rhs.width = rect.width - size;
            
            rhs.x = rect.x + size;
        }
        
    public:
        RectSpliter(const Rect& rect, const Rect& min, const Rect& max)
        : min(min), max(max), rect(rect)
        {
            int isVerticel = std::uniform_int_distribution<int>(0, 1)(rd);
            
            lhs.x = rect.x;
            lhs.y = rect.y;
            
            if (isVertical)
            {
                SplitVertical();
            }
            else
            {
                SplitHorizontal();
            }
        }
    };
    
    std::random_device RectSpliter::rd;
}

#endif
