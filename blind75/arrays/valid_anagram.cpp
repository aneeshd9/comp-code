#include <string>
#include <map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::map<char, int> count_s;
        for (auto c: s) {
            count_s[c] += 1;
        }
        for (auto c: t) {
            count_s[c] -= 1;
        }
        for (auto it = count_s.begin(); it != count_s.end(); ++it) {
            if (it->second != 0) {
                return false;
            }
        }
        return true;
    }
};