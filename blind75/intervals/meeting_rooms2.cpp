#include <functional>
#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
  int minMeetingRooms(std::vector<std::vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end());

    std::priority_queue<int, std::vector<int>, std::greater<>> q;
    q.push(intervals[0][1]);

    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] >= q.top()) q.pop();
      q.push(intervals[i][1]);
    }

    return q.size();
  }
};
