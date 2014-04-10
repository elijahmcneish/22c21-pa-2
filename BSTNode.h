/* BSTNode.h
 * Copyright (c) 2014 Elijah McNeish. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BSTNODE_H_
#define BSTNODE_H_

#include <iostream>
#include "BinarySearchTree.h"

template<class Item>
class BinarySearchTree;

template<class Item>
class BSTNode
{
public:
    BSTNode(Item key, BSTNode<Item>* left=NULL, BSTNode<Item>* right=NULL)
    	{
    	    key_field = key;
    	    left_child = left;
    	    right_child = right;
    	}
    void dump() const;
    friend class BinarySearchTree<Item>;
private:
    Item key_field;
    BSTNode<Item>* left_child;
    BSTNode<Item>* right_child;
};

#endif
