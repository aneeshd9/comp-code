#include "ListNode.hpp"

class Solution {
public:
  bool hasCycle (ListNode *head) {
    if (head == nullptr || head->next == nullptr) return false;
    
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;

      if (fast == slow) return true;
    }

    return false;
  }
};

