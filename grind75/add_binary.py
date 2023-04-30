class Solution:
  def addBinary(self, a: str, b: str) -> str:
    ans: str = ""

    maxLen: int = max(len(a), len(b))
    carry: int = 0
    for i in range(maxLen):
      current: int = 0
      if len(a) - 1 - i >= 0:
        current += int(a[len(a) - 1 - i])
      if len(b) - 1 - i >= 0:
        current += int(b[len(b) - 1 - i])
      current += carry

      ans = str(current % 2) + ans
      carry = current // 2

    if carry:
      ans = str(carry) + ans

    return ans