from collections import defaultdict

class Solution(object):
    MAX_LEN = int(5e5)

    def frequencySort(self, s: str) -> str:
        counts = defaultdict(int)
        for i in range(len(s)):
            counts[s[i]] += 1
        buckets = []
        for _ in range(self.MAX_LEN + 1):
            buckets.append([])
        for k, v in counts.items():
            buckets[v].append(k)
        ans = ""
        for i in range(len(buckets) - 1, -1, -1):
            for c in buckets[i]:
                ans = ans + (c * i)
        return ans