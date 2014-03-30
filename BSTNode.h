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
    void insert_node(BSTNode<Item>*, Item key);
    void inorder_traverse(BSTNode<Item>*) const;
private:
    Item key_field;
    BSTNode<Item>* left_child;
    BSTNode<Item>* right_child;
};

template<class Item>
void BSTNode<Item>::insert_node(BSTNode<Item>* root, Item key)
{
    BSTNode *cursor = root, *prev = 0;

    while (cursor != NULL)
    {
    	prev = cursor;
    	if (key < cursor->key_field)
    	{ cursor = cursor->left_child; }
    	else
    	{ cursor = cursor->right_child; }
    }

    if (key < prev->key_field)
    { prev->left_child = new BSTNode(key); }
    else if (key > prev->key_field)
    { prev->right_child = new BSTNode(key); }
    // Duplicate keys will be ignored
    
}

template<class Item>
void BSTNode<Item>::inorder_traverse(BSTNode<Item>* node) const
{
    if (node != NULL)
    {
	inorder_traverse(node->left_child);
	std::cout << "Key: " << node->key_field << std::endl;
	inorder_traverse(node->right_child);
    }
}

#endif
