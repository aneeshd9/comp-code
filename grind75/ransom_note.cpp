#include <string>

class Solution {
public:
  bool canConstruct(std::string ransomNote, std::string magazine) {
    int count[26] = {0};
    for (auto c: magazine) count[c - 'a']++;
    for (auto c: ransomNote) count[c - 'a']--;
    for (auto c: count) if (c < 0) return false;
    return true;
  }
};