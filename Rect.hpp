//
//  Rect.hpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/13.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#ifndef DungeonMaker_Rect_hpp
#define DungeonMaker_Rect_hpp

#include <random>
#include "Grid.hpp"

namespace dungeon
{
    class Rect
    {
        static std::random_device rd;
        typedef std::uniform_int_distribution<int> udist;
        
    public:
        int x;
        int y;
        int width;
        int height;
        
        Rect() : x(0), y(0), width(0), height(0) {}
        Rect(int w, int h) : width(w), height(h) {}
        Rect(int x, int y, int w, int h) : x(x), y(y), width(w), height(h) {}
        Rect(const Rect& rect)
        : x(rect.x), y(rect.y), width(rect.width), height(rect.height) {}
        
        Rect Padded(int space) const
        {
            return Rect(x + space, y + space, width - space, height - space);
        }
        
        Rect Room(int space) const
        {
            auto padded = Padded(space);
            return Rect(padded.x + udist(0, padded.width >> 1)(rd),
                        padded.y + udist(0, padded.height >> 1)(rd),
                        padded.width - udist(0, padded.width >> 1)(rd),
                        padded.height - udist(0, padded.height >> 1)(rd));
        }
        
        void Draw(Grid& target)
        {
            for (int i = x; i < width; ++i)
            {
                for (int j = y; j < height; ++j)
                {
                    target[i][j] = (int)SquaresType::Room;
                }
            }
        }
    };
    
    std::random_device Rect::rd;
}

#endif
