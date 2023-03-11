from typing import List

class Solution(object):
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        ans = 0
        intervals.sort(key=lambda p: p[0])
        prevEnd = intervals[0][1]
        for start, end in intervals[1:]:
            if start < prevEnd:
                ans += 1
                prevEnd = min(end, prevEnd)
            else:
                prevEnd = end
        return ans