/*
If we loop on the array and find all friend requests, the time complexity is O(n^2).
We notice that:
1 <= ages.length <= 20000.
1 <= ages[i] <= 120.
The length of array is large but the range of age is small, 
so we use a hash map to record number of every age,loop on the age range
then get the result by some mathematical calculation.
this strategy reduce the time complexitu to O(n).

Some interpretation about friend making conditions:
1.age[B] > 100 && age[A] < 100 is redundant, because it is a sufficient conditions of age[B] > age[A].
2.we loop on j>=i so ages[A]>=ages[B] is guaranteed, we don't have to test it every time.
3.we loop on j in ascending order, once j/2+7>=i, the following j also meet j/2+7>=i, so we break thsi loop.

Time: O(n),
Space: O(n).
*/

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int res=0;
        unordered_map<int,int> count;
        for(int i:ages) count[i]++;
        for(int i=1;i<=120;i++){
            int temp1=count[i];
            for(int j=i;j<=120;j++){//j>=i
                int temp2=count[j];
                if(i<=j/2+7) break;
                else res+=j==i ? temp1*(temp1-1):temp1*temp2;
            }
        }
        return res;
    }
};