from typing import List

class Solution(object):
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda p: p[0])
        ans = [intervals[0]]
        for start, end in intervals[1:]:
            prevEnd = ans[-1][1]
            if start <= prevEnd:
                ans[-1][1] = max(prevEnd, end)
            else:
                ans.append([start, end])
        return ans
                