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
// Pass the BST's root node to the private insert counterpart.
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

template<class Item>
void BSTNode<Item>::dump() const
// Debug method.
{
    std::cout << "|"  << "Key: " << key_field << " Address: " << this << std::endl;
    if (left_child)
    { std::cout << "|" << "Left child: " << left_child->key_field << " Address: " << left_child << std::endl; }
    if (right_child)
    { std::cout  << "|" << "Right child: " << right_child->key_field << " Address: " << right_child << std::endl; }

    std::cout << std::endl;
}

#endif
