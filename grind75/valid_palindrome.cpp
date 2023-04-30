#include <string>
#include <cctype>

class Solution {
public:
  bool isPalindrome(std::string s) {
    std::string processed = preprocess(s);
    int left = 0;
    int right = processed.size() - 1;

    while (left < right) {
      if (processed[left] != processed[right]) return false;
      left++;
      right--;
    }

    return true;
  }
private:
  std::string preprocess(std::string s) {
    std::string processed = "";
    for (auto c: s) {
      if (std::isalnum(c)) {
        processed += std::tolower(c);
      }
    }
    return processed;
  }
};
