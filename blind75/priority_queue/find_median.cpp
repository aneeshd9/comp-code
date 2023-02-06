#include <functional>
#include <ostream>
#include <queue>
#include <vector>

class MedianFinder {
public:
  MedianFinder() {
  }

  void addNum(int num) {
    if (left.size() == 0) {
      left.push(num);
    } else if (left.size() > right.size()) {
      if (num < left.top()) {
        right.push(left.top());
        left.pop();
        left.push(num);
      } else {
        right.push(num);
      }
    } else {
      if (num > right.top()) {
        left.push(right.top());
        right.pop();
        right.push(num);
      } else {
        left.push(num);
      }
    }
  }

  double findMedian() {
    if (left.size() == right.size()) {
      return static_cast<double>(left.top() + right.top()) / 2;
    } else if (left.size() > right.size()) {
      return left.top();
    } else {
      return right.top();
    }
  }

private:
  std::priority_queue<int, std::vector<int>, std::less<>> left;
  std::priority_queue<int, std::vector<int>, std::greater<>> right;
};
