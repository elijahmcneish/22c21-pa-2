/* BinarySearchTree.cpp
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

#include <iostream>
#include "BinarySearchTree.h"

template<class Item>
BSTNode<Item>* BinarySearchTree<Item>::get_root()
{
    return root;
}

template<class Item>
void BinarySearchTree<Item>::print_root()
// Debug method.
{
    std::cout << std::endl << "Root: " << root->key_field << " Address: " << root << std::endl;
}

template<class Item>
void BinarySearchTree<Item>::insert(Item key, BSTNode<Item>*& sub)
// Private method. The root node is not specified in the public interface.
{
    if (!sub)
    { sub = new BSTNode<Item>(key); }
    else if (key < sub->key_field)
    { insert(key, sub->left_child); }
    else if (key > sub->key_field)
    { insert(key, sub->right_child); }
// Duplicate keys will be ignored.
}

template<class Item>
void BinarySearchTree<Item>::insert(Item key)
// Pass the BST's root node to the private insert method counterpart.
{
    insert(key, root);
}

template<class Item>
void BinarySearchTree<Item>::inorder_traverse(BSTNode<Item>* node) const
{
    if (node != NULL)
    {
	inorder_traverse(node->left_child);
	std::cout << "\tKey: " << node->key_field << std::endl;
	inorder_traverse(node->right_child);
    }
}
