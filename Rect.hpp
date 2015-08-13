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
        int width;
        int height;
        
        Rect(int w, int h) : width(w), height(h) {}
    };
}

#endif
