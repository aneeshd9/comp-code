import java.util.Stack;

class Solution {
  public boolean backspaceCompare(String s, String t) {
    return removeBackspace(s).equals(removeBackspace(t));
  }

  private String removeBackspace(String s) {
    Stack<Character> stack = new Stack<>();
    for (int i = 0; i < s.length(); ++i) {
      if (s.charAt(i) == '#' && !stack.empty()) {
        stack.pop();
      } else if (s.charAt(i) != '#') {
        stack.push(s.charAt(i));
      }
    }

    String ans = "";
    while (!stack.empty()) {
      ans = ans + stack.pop();
    }
    return ans;
  }
}