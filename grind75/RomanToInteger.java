import java.util.HashMap;
import java.util.Map;
import static java.util.Map.entry;

class Solution {
  private static Map<Character, Integer> values = new HashMap<>(Map.ofEntries(
    entry('I', 1),
    entry('V', 5),
    entry('X', 10),
    entry('L', 50),
    entry('C', 100),
    entry('D', 500),
    entry('M', 1000)
  ));

  public int romanToInt(String s) {
    int value = 0;
    for (int i = 0; i < s.length(); ++i) {
      char currentChar = s.charAt(i);

      if (i + 1 < s.length()) {
        char nextChar = s.charAt(i + 1);
        if (currentChar == 'I' && nextChar == 'V') {
          value += 4;
          i += 1;
        } else if (currentChar == 'I' && nextChar == 'X') {
          value += 9;
          i += 1;
        } else if (currentChar == 'X' && nextChar == 'L') {
          value += 40;
          i += 1;
        } else if (currentChar == 'X' && nextChar == 'C') {
          value += 90;
          i += 1;
        } else if (currentChar == 'C' && nextChar == 'D') {
          value += 400;
          i += 1;
        } else if (currentChar == 'C' && nextChar == 'M') {
          value += 900;
          i += 1;
        } else {
          value += values.get(currentChar);
        }
      } else {
        value += values.get(currentChar);
      }
    }
    return value;
  }

  public static void main() {
    String roman = "III";
    System.out.println(new Solution().romanToInt(roman));
  }
}