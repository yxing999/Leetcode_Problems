/*
Build a min_heap to help merge sort.
The process is easy, just put all ListNode into priority_queue, 
pick the top one, push the next ListNode if it is not NULL, until the heap is empty.

I merged the original lists in place, to save space usage, maybe.

There are some cases like:[[]], [[],[]].
So we should check whether the list is NULL when we initiated the min_heap.

Time: O(n*logk);
Space: O(k).
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct compare{
        bool operator()(ListNode *a,ListNode *b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> min_heap;
        ListNode *res=new ListNode(-1);
        for(auto list:lists)
            if(list) min_heap.push(list);
        ListNode *cur=res;
        while(!min_heap.empty()){
            auto temp=min_heap.top();
            min_heap.pop();
            cur->next=temp;
            cur=cur->next;
            if(temp->next) min_heap.push(temp->next);
        }
        return res->next;
    }
};