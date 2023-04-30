#include <string>

class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    int count[26] = {0};
    for (auto c: s) {
      count[c - 'a']++;
    }
    for (auto c: t) {
      count[c - 'a']--;
    }
    for (auto c: count) {
      if (c != 0) return false;
    }
    return true;
  }
};
