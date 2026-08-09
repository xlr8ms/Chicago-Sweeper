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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            ListNode* head = nullptr;
            return head;
        }
        vector<int> ans;
        for(int i=0; i<lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp){
                ans.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(ans.begin(), ans.end());
        if(ans.size() == 0){
             ListNode* head = nullptr;
            return head;
        }
        return vectortoLL(ans);
    }
    ListNode* vectortoLL(vector<int>& v){
        ListNode* temp = new ListNode(v[0]);
        ListNode* head = temp;
        for(int i = 1; i<v.size(); i++){
            ListNode* temp1 = new ListNode(v[i]);
            temp->next = temp1;
            temp = temp1;
        }
        return head;
    }
};