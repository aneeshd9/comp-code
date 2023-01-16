#include <string>
#include <vector>

class Codec {
public:
    std::string encode(std::vector<std::string> &strs) {
        std::string code {""};
        for (auto &str: strs) {
            code.append(std::to_string(str.size()));
            code.append("#");
            code.append(str);
        }
        return code;
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> words;
        for (int i = 0; i < s.size(); ) {
            int j = i;
            while (j < s.size() && s[j] != '#') {
                ++j;
            }
            int len = std::stoi(s.substr(i, j - i));
            std::string word = s.substr(j + 1, len);
            words.push_back(word);
            i = j + 1 + len;
        }
        return words;
    }
};