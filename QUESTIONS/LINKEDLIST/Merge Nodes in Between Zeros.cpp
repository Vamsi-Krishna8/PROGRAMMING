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

//Approach 1
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* p1=head->next;
        ListNode* p2=p1;

        while(p2!=NULL){
            int sum=0;
            while(p2!=NULL && p2->val!=0){
                sum+=p2->val;
                p2=p2->next;
            }
            p1->val=sum;
            p2=p2->next;
            p1->next=p2;
            p1=p2;
        }
        return head->next;
    }
};

//Approach 2(recursion)

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        head=head->next;
        if(head==NULL) return head;
        ListNode* temp=head;
        int sum=0;
        while(temp!=NULL && temp->val!=0){
            sum+=temp->val;
            temp=temp->next;
        }
        head->val=sum;
        head->next=mergeNodes(temp);
        return head;

    }
};