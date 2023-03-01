#include "ListNode.hpp"

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (head->next == nullptr) return nullptr;
    
    ListNode *behindPrev = nullptr;
    ListNode *behind = head;

    ListNode *ahead = head;
    for (int i = 0; i < n; ++i) {
      ahead = ahead->next;
    }

    if (ahead == nullptr) return head->next;

    while (ahead != nullptr) {
      ahead = ahead->next;
      behindPrev = behind;
      behind = behind->next;
    }

    behindPrev->next = behind->next;
    return head;
  }
};

int main(void) {
  ListNode *head = new ListNode(1, new ListNode(2, nullptr));
  int n = 2;

  ListNode *removed = Solution().removeNthFromEnd(head, 2);

  return 0;
}
