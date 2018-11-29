/*
Good problem to explore.
One solution is to implement a hashmap, build mapping relations between origin and new nodes.
Then connect the next and random pointer by referring this hashmap.

Time: O(n);
Space: O(n).
*/

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        RandomListNode *cur=head;
        unordered_map<RandomListNode*,RandomListNode*> hash;
        while(cur){
            hash[cur]=new RandomListNode(cur->label);
            cur=cur->next;
        }
        cur=head;
        while(cur){
            hash[cur]->next=hash[cur->next];
            hash[cur]->random=hash[cur->random];
            cur=cur->next;
        }
        return hash[head];
    }
};