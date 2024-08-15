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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=head->next;
        int firstPos=0;
        int prevPos=0;
        int i=1;
        int minDist=INT_MAX;

        while(curr->next!=NULL){
            if((curr->val>prev->val && curr->val>curr->next->val)
                        ||(curr->val<prev->val && curr->val<curr->next->val)){
                //critical point
                if(firstPos==0){
                    firstPos=i;
                    prevPos=i;
                }
                else{
                    minDist=min(minDist,i-prevPos);
                    prevPos=i;
                }
            }
            i++;
            prev=curr;
            curr=curr->next;   
        }
        if(minDist==INT_MAX) return {-1,-1};
        return {minDist,prevPos-firstPos};
    }
};