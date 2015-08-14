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
        Rect(int w, int h) : x(0), y(0), width(w), height(h) {}
        Rect(int x, int y, int w, int h) : x(x), y(y), width(w), height(h) {}
        Rect(const Rect& rect)
        : x(rect.x), y(rect.y), width(rect.width), height(rect.height) {}
        
        Rect Padded(int space) const
        {
            int w = width - space * 2;
            int h = height - space * 2;
            return Rect(x + space, y + space, w, h);
        }
        
        Rect Room(int space) const
        {
            auto padded = Padded(space);
            return Rect(padded.x + udist(0, padded.width * 0.5)(rd),
                        padded.y + udist(0, padded.height * 0.5)(rd),
                        padded.width - udist(0, padded.width * 0.5)(rd),
                        padded.height - udist(0, padded.height * 0.5)(rd));
        }
        
        bool Enable(int w, int h)
        {
            return w < width && h < height;
        }
        
        void Draw(Grid& target, const Rect& min)
        {
            if (!Enable(min.width, min.height))
                return;
            
            for (int i = y; i < y + height; ++i)
            {
                if (target.Height() <= i) break;
                
                for (int j = x; j < x + width; ++j)
                {
                    if (target.Width() <= j) break;
                    target[i][j] = (int)SquaresType::Room;
                }
            }
        }
    };
    
    std::random_device Rect::rd;
}

#endif
