#include <vector>
#include <string>
#include <map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
        std::map<std::string, std::vector<std::string>> m;
        for (auto &str: strs) {
            std::string key = make_key(str);
            m[key].push_back(str);
        }
        std::vector<std::vector<std::string>> ans;
        for (auto it = m.begin(); it != m.end(); ++it) {
            ans.push_back(it->second);
        }
        return ans;
    }
private:
    std::string make_key(std::string &s) {
        std::vector<int> counts(26, 0);
        for (auto ch: s) {
            counts[ch - 'a'] += 1;
        }
        std::string key {""};
        for (int c: counts) {
            key.append(std::to_string(c + 'a'));
        }
        return key;
    }
};