/*
Try to solve this problem with constant extra space.
The key issue is how to get information about random pointer.

The solution is, add every new node just after origin node, connect the random pointer,
and then extract new nodes, connect next pointer.

Diagram like:
1->2->3->4->5->NULL

1->1->2->2->3->3->4->4->5->5->NULL

Get: 1->2->3->4->5->NULL and 1->2->3->4->5->NULL

Time: O(n);
Space O(1).
*/

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        RandomListNode *cur=head,*nex;
        while(cur){
            RandomListNode *cp=new RandomListNode(cur->label);
            cp->next=cur->next;
            cur->next=cp;
            cur=cur->next->next;
        }
        RandomListNode *res=head->next;
        cur=head,nex=res;
        while(cur){
            if(!cur->random)
                nex->random=NULL;
            else
                nex->random=cur->random->next;
            cur=cur->next->next;
            if(cur) nex=cur->next;
        }
        cur=head,nex=res;
        while(cur){
            cur->next=nex->next;
            cur=cur->next;
            if(cur){
                nex->next=cur->next;
                nex=nex->next;
            }
        }
        return res;
    }
};