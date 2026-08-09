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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        if(cnt>1){
        if(n==1){
            ListNode* temp = head;
            while(temp->next->next != nullptr){
                temp = temp->next;
            }
            temp->next = nullptr;
            return head;
        }
        }
        else if(cnt == 1){
            if(n==1){
                ListNode* temp = head;
                head = head->next;
                return head;
            }
        }
        int k = cnt - n + 1;
        cnt = 1;
        ListNode* temp1 = head;
        ListNode* prev = nullptr;
        while(temp1){
            if(cnt == k){
                if(k==1){
                    ListNode* temp2 = head;
                    head = head->next;
                    return head;
                }
                prev->next = prev->next->next;
                return head;
            }
            prev = temp1;
            temp1 = temp1->next;
            cnt++;
        }
        return head;
    }
};