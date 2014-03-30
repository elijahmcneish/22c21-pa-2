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

int main()
{
    // Parse input phrase.
    std::string PHRASE = "data structure is one of the most important courses in computer science";
    std::queue<std::string> words;
    char delim = ' ';
    std::stringstream ss(PHRASE);
    while (!ss.eof())
    {
	std::string s;
	std::getline(ss, s, delim);
	words.push(s);
    }

    // Create the binary search tree.
    BinarySearchTree<std::string>* tree = new BinarySearchTree<std::string>;
    while (!words.empty())
    {
	tree->insert_node(words.front());
	words.pop();
    }
    
    std::cout << std::endl << "LVR traverse" <<  std::endl;
    std::cout << "============" << std::endl;
    tree->inorder_traverse(tree->get_root());

    return 0;
}
