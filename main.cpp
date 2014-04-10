/* main.cpp
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
#include <queue>
#include <sstream>
#include <string>
#include "BSTNode.h"
#include "BinarySearchTree.h"
#include "BSTNode.cpp"
#include "BinarySearchTree.cpp"

int main()
{
    // Parse input phrase.
    const std::string PHRASE = "data structure is one of the most important courses in computer science";
    std::queue<std::string> words;
    const char DELIM = ' ';
    std::stringstream ss(PHRASE);
    while (!ss.eof())
    {
	std::string s;
	std::getline(ss, s, DELIM);
	words.push(s);
    }

    // Create the binary search tree.
    std::cout << std::endl << "Phrase: " << PHRASE << std::endl;
    BinarySearchTree<std::string>* tree = new BinarySearchTree<std::string>;
    std::cout << std::endl << "Inserting nodes into BST..." ;
    while (!words.empty())
    {
	tree->insert(words.front());
        words.pop();
    }
    std::cout << "Done." << std::endl;
	
    // Traverse the BST.
    std::cout << std::endl << "LVR Traversal" <<  std::endl;
    tree->inorder_traverse(tree->get_root());
    std::cout << std::endl;
    
    return 0;
}
