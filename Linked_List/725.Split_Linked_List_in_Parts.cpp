/*
For the k parts, extra of it should be length of (base + 1), others should be length of (base).

Time: O(n),
Space: O(1)
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int l = getlength(root);
        int base = l / k, extra = l % k;
        vector<ListNode*> res;
        auto cur = root;
        for (int i = 0; i < k; i++)
        {
            res.push_back(cur);
            for (int j = 0; j < base - (extra <= 0); j++)
            {
                cur = cur->next;
            }
            if (cur)
            {
                auto temp = cur->next;
                cur->next = NULL;
                cur = temp;
            }
            extra--;
        }
        return res;
    }
    int getlength(ListNode* root)
    {
        int res = 0;
        auto p = root;
        while (p)
        {
            res++;
            p = p->next;
        }
        return res;
    }
};