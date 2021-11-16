//
// Created by kmou424 on 2021/11/16.
//

#include <tools.hpp>

/**
 *  @order Plus two large number
 *  @param  _addend1  The first addend large number
 *  @param  _addend2  The second addend large number
 *  @return Plus result
*/

LargeNumber largeNumberPlus(LargeNumber _addend1, LargeNumber _addend2) {
    unsigned int _len1 = _addend1.size(), _len2 = _addend2.size();
    if (_len1 < _len2) {
        std::swap(_len1, _len2);
        std::swap(_addend1, _addend2);
    }
    _addend1.insert(_addend1.begin(), 0);
    for (int i = (int) _len2 - 1; i >= 0; --i) {
        _addend1[_len1 - _len2 + i + 1] += _addend2[i];
        for (int j = (int) (_len1 - _len2) + i + 1; j > 0; --j) {
            if (_addend1[j] >= 10) {
                _addend1[j] -= 10;
                _addend1[j - 1]++;
            }
        }
    }
    if (_addend1[0] == 0)
        _addend1.erase(_addend1.begin());
    return _addend1;
}
