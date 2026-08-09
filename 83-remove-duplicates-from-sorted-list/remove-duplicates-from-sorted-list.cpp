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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = head;
        map<int,int> m;
        while(temp){
            if(m[temp->val] > 0){
                prev->next = temp->next;
            }
            else{
            m[temp->val]++;
            prev = temp;
            }
            temp = temp->next;
        }
        return head;
    }
};