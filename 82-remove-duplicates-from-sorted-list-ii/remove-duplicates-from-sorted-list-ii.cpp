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
        if(head == nullptr) return head;
        ListNode* temp = head;
        vector<int> v;
        map<int,int> m;
        while(temp){
            m[temp->val]++;
            temp = temp->next;
        }
        ListNode* temp1 = head;
        while(temp1){
            if(m[temp1->val] == 1){
                v.push_back(temp1->val);
            }
            temp1 = temp1->next;
        }
        return vectortoLL(v);
    }
    ListNode* vectortoLL(vector<int>& v){
        if(v.size() == 0) return nullptr;
        ListNode* head = new ListNode(v[0]);
        ListNode* temp = head;
        for(int i=1; i<v.size(); i++){
            ListNode* temp1 = new ListNode(v[i]);
            temp->next = temp1;
            temp = temp1;
        }
        return head;
    }
};