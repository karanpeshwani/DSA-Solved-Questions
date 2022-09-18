#include <bits/stdc++.h>
using namespace std;


//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode * ptr = head;
        while(ptr != NULL){
            ptr = ptr->next;
            size++;
        }
        ptr = head;
        ListNode* ptr2;
        int nodeNumberFromStart = size - n + 1;
        if(nodeNumberFromStart == 1){
            ptr2 = ptr->next;
            delete ptr;
            return ptr2;
        }
        for(int i=0;i<nodeNumberFromStart-2;i++){
            ptr = ptr->next;
        }
        ptr2 = ptr->next;
        ptr->next = ptr->next->next;
        delete ptr2;
        return head;
    }
};