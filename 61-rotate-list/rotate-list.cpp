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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;
        vector<int> v;
        while(temp){
            cnt++;
            v.push_back(temp->val);
            temp = temp->next;
        }
        if(head == nullptr){
            return head;
        }
        int n = k%cnt;
        vector<int> ans;
        for(int i=(cnt - n); i<v.size(); i++){
            ans.push_back(v[i]);
        }
        for(int i=0; i<(cnt-n); i++){
            ans.push_back(v[i]);
        }
        return vectortoLL(ans);
    }
    ListNode* vectortoLL(vector<int>& v){
        ListNode* temp = new ListNode(v[0]);
        ListNode* head = temp;
        for(int i=1; i<v.size(); i++){
            ListNode* temp1 = new ListNode(v[i]);
            temp->next = temp1;
            temp = temp1;
        }
        return head;
    }
};