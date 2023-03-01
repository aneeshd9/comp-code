#include "ListNode.hpp"

#include <vector>

class Solution {
public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    if (lists.size() == 0) return nullptr;

    int n = lists.size();
    while (n > 1) {
      for (int i = 0; i < n / 2; ++i) {
        lists[i] = mergeTwoLists(lists[i], lists[n - i - 1]);
      }
      n = (n + 1) / 2;
    }

    return lists[0];
  }

private:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr && list2 == nullptr)
      return nullptr;
    else if (list1 == nullptr && list2 != nullptr)
      return list2;
    else if (list1 != nullptr && list2 == nullptr)
      return list1;
    else {
      ListNode *merged;
      if (list1->val <= list2->val) {
        merged = list1;
        list1 = list1->next;
      } else {
        merged = list2;
        list2 = list2->next;
      }

      ListNode *curr = merged;

      while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
          curr->next = list1;
          list1 = list1->next;
        } else {
          curr->next = list2;
          list2 = list2->next;
        }
        curr = curr->next;
      }

      if (list1 != nullptr) {
        curr->next = list1;
      } else {
        curr->next = list2;
      }

      return merged;
    }
  }
};
