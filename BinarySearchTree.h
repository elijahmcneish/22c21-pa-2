/* BinarySearchTree.h
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

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "BSTNode.h"

template<class Item>
class BSTNode;

template<class Item>
class BinarySearchTree
{
public:
    BinarySearchTree()
	{ root = NULL; }
    BSTNode<Item>* get_root();
    void print_root();
    void insert(Item key);
    void inorder_traverse(BSTNode<Item>*) const;
private:
    BSTNode<Item>* root;
    void insert(Item key, BSTNode<Item>*& sub);
};

#endif
