from typing import List

class Solution(object):
    def insert(self, intervals: List[List[int]],
                       newInterval: List[int]) -> List[List[int]]:
        
        updatedIntervals = []
        for i in range(len(intervals)):
            if newInterval[1] < intervals[i][0]:
                updatedIntervals.append(newInterval)
                updatedIntervals += intervals[i:]
                return updatedIntervals
            elif newInterval[0] > intervals[i][1]:
                updatedIntervals.append(intervals[i])
            else:
                newInterval = [min(newInterval[0], intervals[i][0]),
                               max(newInterval[1], intervals[i][1])]
        updatedIntervals.append(newInterval)
        return updatedIntervals