#include "ListNode.hpp"
#include <iostream>
#include <vector>

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *merged = nullptr;
    
    ListNode *current = merged;
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val < list2->val) {
        addToEndAndAdvance(&current, &list1, &merged);
      } else {
        addToEndAndAdvance(&current, &list2, &merged);
      }
    }

    while (list1 != nullptr) {
      addToEndAndAdvance(&current, &list1, &merged);
    }

    while (list2 != nullptr) {
      addToEndAndAdvance(&current, &list2, &merged);
    }

    return merged;
  }
private:
  void addToEndAndAdvance(ListNode **current, ListNode **nextElem, ListNode **head) {
    if (*current == nullptr) {
      *current = *nextElem;
      *head = *nextElem;
      ListNode *temp = (*nextElem)->next;
      (*current)->next = nullptr;
      *nextElem = temp;
    } else {
      (*current)->next = *nextElem;
      *current = (*current)->next;
      ListNode *temp = (*nextElem)->next;
      (*current)->next = nullptr;
      *nextElem = temp;
    }
  }
};

ListNode *makeList(std::vector<int> &nums) {
  ListNode *head = nullptr;
  ListNode *current = head;

  for (auto num: nums) {
    ListNode *newNode = new ListNode(num);
    if (current == nullptr) {
      head = newNode;
      current = head;
    } else {
      current->next = newNode;
      current = newNode;
    }
  }

  return head;
}

int main(void) {
  std::vector<int> list1 {1, 2, 4};
  std::vector<int> list2 {1, 3, 4};

  ListNode *l1 = makeList(list1);
  ListNode *l2 = makeList(list2);
  Solution s;
  ListNode *merged = s.mergeTwoLists(l1, l2);

  while (merged != nullptr) {
    std::cout << merged->val << " ";
    merged = merged->next;
  }

  return 0;
}
