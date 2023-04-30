#include "ListNode.hpp"

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;

    ListNode *prev = nullptr;
    ListNode *current = head;
    ListNode *next = head->next;

    while (current != nullptr) {
      next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }

    return prev;
  }
};