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
    class Grid
    {
        std::vector<std::vector<T>> rect;
        int width;
        int height;
        
        void init(int width, int height)
        {
            this->width = width;
            this->height = height;
            
            rect.resize(width);
            for (int i = 0; i < width; ++i)
                rect.at(i).resize(height);
        }
        
    public:
        /**
         * @brief 2D vector array
         */
        Grid(int width, int height)
        {
            init(width, height);
        }
        
        /**
         * @brief 2D vector array
         * @param[in] fill a filling value
         */
        Grid(int width, int height, const T& fill)
        {
            init(width, height);
            for (int i = 0; i < width; ++i)
                std::fill(rect.at(i).begin(), rect.at(i).end(), fill);
        }
        
        /**
         * @brief at [width][height]
         * @return a vertical line
         */
        std::vector<T>& operator[](int x) { return rect.at(x); }
        
        void ResizeRow(int size, const T& fill)
        {
            
        }
        
        void ResizeCol(int size, const T& fill)
        {
            
        }
    };
}

#endif
