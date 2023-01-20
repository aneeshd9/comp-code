#include <string>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        if (s.size() == 0) return true;

        std::stack<char> stack;
        int i = 0;
        while (i < s.size()) {
            if (isOpen(s[i])) {
                stack.push(s[i]);
                i += 1;
            } else {
                if (stack.empty()) return false;
                char open = stack.top();
                stack.pop();
                if (matches(open, s[i])) i += 1;
                else return false;
            }
        }
        
        if (stack.empty()) return true;
        else return false;
    }
private:
    bool isOpen(char ch) {
        return ch == '(' || ch == '[' || ch == '{';
    }

    bool isClose(char ch) {
        return ch == ')' || ch == ']' || ch == '}';
    }

    bool matches(char open, char close) {
        if (open == '(' && close == ')') return true;
        else if (open == '[' && close == ']') return true;
        else if (open == '{' && close == '}') return true;
        else return false;
    }
};