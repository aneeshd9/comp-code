class Solution {
  public String longestCommonPrefix(String[] strs) {
    if (strs.length == 0) return "";
    String prefix = strs[0];
    for (int i = 1; i < strs.length; ++i) {
      String current = strs[i];
      String newPrefix = "";
      int j = 0;
      while (j < prefix.length() && j < current.length() && current.charAt(j) == prefix.charAt(j)) {
        newPrefix += prefix.charAt(j);
        ++j;
      }
      prefix = newPrefix;
    }
    return prefix;
  }
}