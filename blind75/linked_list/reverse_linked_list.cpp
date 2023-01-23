#include "ListNode.hpp"

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = head->next;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};