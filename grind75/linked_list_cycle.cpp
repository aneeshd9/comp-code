#include "ListNode.hpp"

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return false;

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (slow->next != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;

      if (slow == fast) return true;
    }

    return false;
  }
};
