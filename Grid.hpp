//
//  Grid.hpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/12.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#ifndef DungeonMaker_Grid_hpp
#define DungeonMaker_Grid_hpp

#include <array>
#include <vector>
#include <algorithm>

namespace dungeon
{
    template <class T>
    class Grid : public std::vector<std::vector<T>>
    {
        void init(int width, int height)
        {
            this->resize(width);
            for (int i = 0; i < width; ++i)
                this->at(i).resize(height);
        }
        
    public:
        Grid(int width, int height)
        {
            init(width, height);
        }
        
        Grid(int width, int height, T fill)
        {
            init(width, height);
            for (int i = 0; i < width; ++i)
                std::fill(this->at(i).begin(), this->at(i).end(), fill);
        }
        
        /**
         * @brief at [width][height]
         * @return a vertical line
         */
        std::vector<T>& operator[](int x) { return this->at(x); }
    };
}

#endif
