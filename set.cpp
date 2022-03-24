/*  Copyright (C) 2021-2022 kmou424
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <tools.hpp>

/**
 *  @order Init the set of MergeSearchSet
 *  @param  n  The length of set
*/
MergeSearchSet::MergeSearchSet(int n) {
    _set = std::vector<int>(n + 1);
    _cnt = std::vector<int>(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        _set[i] = i;
    }
}

/**
 *  @order Count children and get children's amount of every tree
 *  @return A array which is contain the children's amount of every tree
*/
std::vector<int> MergeSearchSet::count() {
    std::vector<int> res;
    for (int i = 1; i <= _set.size() - 1; ++i) {
        _cnt[find(i)]++;
    }
    for (int i = 1; i <= _set.size() - 1; ++i) {
        if (_cnt[i] != 0) res.push_back(_cnt[i]);
    }
    return res;
}

/**
 *  @order Find root node of specific node
 *  @param  x  A node need to find
 *  @return The root node of x node
*/
int MergeSearchSet::find(int x) {
    if (x == _set[x]) {
        return x;
    } else {
        _set[x] = find(_set[x]);
        return _set[x];
    }
}

/**
 *  @order Merge a node into other node
 *  @param  parent  A node need to contain another node
 *  @param  child  A node need to merge into another node
*/
void MergeSearchSet::merge(int parent, int child) {
    _set[find(child)] = find(parent);
}
