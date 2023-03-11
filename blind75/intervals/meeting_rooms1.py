from typing import List

class Solution(object):
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        intervals.sort(key=lambda p: p[0])
        if len(intervals) == 0:
            return True
        prevEnd = intervals[0][1]
        for start, end in intervals[1:]:
            if start < prevEnd:
                return False
            else:
                prevEnd = end
        return True