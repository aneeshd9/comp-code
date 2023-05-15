#include "ListNode.hpp"

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    ListNode *other = reverse(middleNode(head));
    while (head != nullptr && other != nullptr) {
      if (head->val != other->val) return false;
      head = head->next;
      other = other->next;
    }
    return true;
  }

private:
  ListNode *middleNode(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    if (fast != nullptr) slow = slow->next;
    return slow;
  }

  ListNode *reverse(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while (curr != nullptr) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
};