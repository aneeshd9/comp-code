#include <string>
#include <stack>

class Solution {
public:
  bool isValid(std::string s) {
    if (s.size() == 0) return true;
    
    std::stack<char> stk;

    for (auto c: s) {
      if (isOpen(c)) stk.push(c);
      else {
        if (stk.empty()) return false;
        char open = stk.top();
        stk.pop();
        if (!matched(open, c)) return false;
      }
    }

    if (!stk.empty()) return false;

    return true;
  }

private:
  bool isOpen(char c) {
    return c == '(' || c == '{' || c == '[';
  }

  bool isClose(char c) {
    return c == ')' || c == '}' || c == ']';
  }

  bool matched(char open, char close) {
    switch (open) {
      case '(':
        return close == ')';
      case '{':
        return close == '}';
      case '[':
        return close == ']';
      default:
        return false;
    }
  }
};
