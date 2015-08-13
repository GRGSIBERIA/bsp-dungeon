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
#include <memory>

namespace dungeon
{
    class Grid
    {
        std::vector<std::vector<int>> rect;
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
        
        void fill(const int& fill)
        {
            for (int i = 0; i < width; ++i)
                std::fill(rect.at(i).begin(), rect.at(i).end(), fill);
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
        Grid(int width, int height, const int& fill)
        {
            init(width, height);
            this->fill(fill);
        }
        
        /**
         * @brief at [width][height]
         * @return a vertical line
         */
        std::vector<int>& operator[](int x) { return rect.at(x); }
        
        int Width() const { return width; }
        int Height() const { return height; }
    };
    
    typedef std::shared_ptr<Grid> GridPtr;
}

#endif
