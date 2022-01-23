//
// Created by kmou424 on 2021/11/29.
//

#include <tools.hpp>

int getWordShowTimesBeginWith(DictNodePoint * dictNode, std::string word) {
    if (word.empty())
        return true;
    const char * word_c = word.c_str();
    int showTimes = 0;
    for (int i = 0; i < word.length(); ++i) {
        if (dictNode->nextDictNode == NULL)
            break;
        if (dictNode->nextDictNode->chars[word_c[i] - 'a'].character == word_c[i]) {
            showTimes = (i > 0 ? std::min(showTimes, dictNode->nextDictNode->chars[word_c[i] - 'a'].cnt) : dictNode->nextDictNode->chars[word_c[i] - 'a'].cnt);
        } else {
            showTimes = 0;
            break;
        }
        dictNode = dictNode->nextDictNode;
    }
    dictNode = NULL;
    return showTimes;
}

void insertWord(DictNodePoint * dictNode, std::string word) {
    if (word.empty())
        return;
    const char * word_c = word.c_str();
    for (int i = 0; i < word.length(); ++i) {
        if (dictNode->nextDictNode == NULL)
            dictNode->nextDictNode = new DictNodePoint;
        if (dictNode->nextDictNode->chars[word_c[i] - 'a'].character != word_c[i]) {
            dictNode->nextDictNode->chars[word_c[i] - 'a'].character = word_c[i];
            dictNode->nextDictNode->chars[word_c[i] - 'a'].cnt = 1;
        } else
            dictNode->nextDictNode->chars[word_c[i] - 'a'].cnt += 1;
        dictNode = dictNode->nextDictNode;
    }
    dictNode = NULL;
}