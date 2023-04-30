from typing import List, Tuple


class Solution:
  def canAttendMeetings(self, intervals: List[Tuple[int, int]]) -> bool:
    if (len(intervals)) == 0:
      return True

    intervals.sort()
    lastEnd: int = intervals[0][1]
    for i in range(2, len(intervals)):
      if intervals[i][0] <= lastEnd:
        return False
      else:
        lastEnd = intervals[i][1]

    return True
