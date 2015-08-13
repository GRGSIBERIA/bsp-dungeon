//
//  BSPTree.hpp
//  DungeonMaker
//
//  Created by Eiichi Takebuchi on 2015/08/13.
//  Copyright (c) 2015年 Eiichi Takebuchi. All rights reserved.
//

#ifndef DungeonMaker_BSPTree_hpp
#define DungeonMaker_BSPTree_hpp

#include <array>
#include <memory>

namespace dungeon
{
    /**
     * @brief
     *  Binary Space Partitioning Tree
     */
    template <typename T>
    class BSPTree
    {
        typedef std::shared_ptr<BSPTree> BSPTreePtr;
        
        std::array<BSPTreePtr, 2> leaves;
        T& object;
        
    public:
        BSPTree(T& obj) object(obj) { }
        
        T& Object() { return object; }
        
        void Assign(T& lhs, T& rhs)
        {
            leaves[0] = BSPTreePtr(new BSPTree(lhs));
            leaves[1] = BSPTreePtr(new BSPTree(rhs));
        }
        
        BSPTree& L() { return *leaves[0]; }
        BSPTree& R() { return *leaves[1]; }
    };
}

#endif
