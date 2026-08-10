/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* temp = head;
        vector<int> v;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        int n = v.size()-1;
        while(temp){
            temp->val = v[n--];
            temp= temp->next;
        }
        return head;
    }
};