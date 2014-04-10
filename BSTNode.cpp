/* BSTNode.cpp
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

#include "BSTNode.h"

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
