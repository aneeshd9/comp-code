class Solution {
  public int[] countBits(int n) {
    int[] ans = new int[n + 1];
    ans[0] = 0;
    int nearest = 0;
    for (int k = 1; k <= n; ++k) {
      if ((k & (k - 1)) == 0) {
        ans[k] = 1;
        nearest = k;
      } else {
        ans[k] = ans[nearest] + ans[k - nearest];
      }
    }
    return ans;
  }
}