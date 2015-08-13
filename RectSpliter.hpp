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
        
        Rect lhs;
        Rect rhs;
        
        bool enableSplit;
        bool isVertical;
        
        void SplitVertical()
        {
            lhs.width = rect.width;
            rhs.width = rect.width;
            rhs.x = rect.x;
            
            int size = std::uniform_int_distribution<int>(min.height, rect.height)(rd);
            lhs.height = size;
            rhs.height = rect.height - size;
            
            rhs.y = rect.y + size;
        }
        
        void SplitHorizontal()
        {
            lhs.height = rect.height;
            rhs.height = rect.height;
            rhs.y = rect.y;
            
            int size = std::uniform_int_distribution<int>(min.width, rect.width)(rd);
            lhs.width = size;
            rhs.width = rect.width - size;
            
            rhs.x = rect.x + size;
        }
        
        void InitializeRects()
        {
            if (min.width * 2 > rect.width || min.height * 2 > rect.height)
                enableSplit = false;
            
            lhs.x = rect.x;
            lhs.y = rect.y;
            
            if (isVertical)
                SplitVertical();
            else
                SplitHorizontal();
        }
        
    public:
        RectSpliter(const Rect& rect, const Rect& min)
        : min(min), rect(rect), enableSplit(true)
        {
            int isv = std::uniform_int_distribution<int>(0, 1)(rd);
            isVertical = isv ? true : false;
            
            InitializeRects();
        }
        
        RectSpliter(const Rect& rect, const Rect& min, bool prevVertical)
        : min(min), rect(rect), enableSplit(true), isVertical(!prevVertical)
        {
            InitializeRects();
        }
        
        Rect Lhs() const { return lhs; }
        Rect Rhs() const { return rhs; }
        bool EnableSplit() const { return enableSplit; }
        bool IsVertical() const { return isVertical; }
    };
    
    std::random_device RectSpliter::rd;
}

#endif
