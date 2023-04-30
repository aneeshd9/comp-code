#include "ListNode.hpp"

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return head;

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    if (fast != nullptr) slow = slow->next;

    return slow;
  }
};