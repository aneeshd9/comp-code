#include "ListNode.hpp"

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return;

        ListNode *prev = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        return merge(head, reverse(slow));
    }
private:
    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next = curr->next;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void merge(ListNode *list1, ListNode *list2) {
        while (list1 != nullptr) {
            ListNode *next1 = list1->next;
            ListNode *next2 = list2->next;

            list1->next = list2;
            if (next1 == nullptr) break;
            list2->next = next1;

            list1 = next1;
            list2 = next2;
        }
    }
};