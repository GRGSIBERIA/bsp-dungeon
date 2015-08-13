//
//  Rect.hpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/13.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#ifndef DungeonMaker_Rect_hpp
#define DungeonMaker_Rect_hpp

namespace dungeon
{
    class Rect
    {
    public:
        int x;
        int y;
        int width;
        int height;
        
        Rect() : x(0), y(0), width(0), height(0) {}
        Rect(int w, int h) : width(w), height(h) {}
        Rect(int x, int y, int w, int h) : x(x), y(y), width(w), height(h) {}
    };
}

#endif
