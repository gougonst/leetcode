#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        else if (list2 == nullptr)
            return list1;
        
        ListNode* newList;
        if (list1->val <= list2->val) {
            newList = list1;
            list1 = list1->next;
        }
        else {
            newList = list2;
            list2 = list2->next;
        }

        ListNode* cur = newList;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;
            }
            else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = (list1 != nullptr) ? list1 : list2;
        
        return newList;
    }
};

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* newList = Solution().mergeTwoLists(list1, list2);
    while (newList != nullptr) {
        cout << newList->val << " ";
        newList = newList->next;
    }
    return 0;
}
