/*
N can be very large, So we must find some trick to solve this problem.
The length of the cell is only 8, so the maximum number of different cells is 2^8.
The front and the back must always be 0(except the day 0),so 2^8 becomes 2^6.
There must be a cycle along the cells!
First, we get this cycle and store them into a db,
Then make use of mod to choose the result cell from the db.
(N-1) is to except cells on day 0.

Time: O(1),
Space: O(1).
*/

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> temp(8,0);
        vector<vector<int>> db;
        for(int i=1;i<=6;i++) temp[i]=!(cells[i-1]^cells[i+1]);
        for(int i=0;i<8;i++) cells[i]=temp[i];
        db.push_back(cells);
        while(true){
            for(int i=1;i<=6;i++) temp[i]=!(cells[i-1]^cells[i+1]);
            for(int i=1;i<=6;i++) cells[i]=temp[i];
            if(cells==db.front()) break;
            db.push_back(cells);
        }
        return db[(N-1)%db.size()];
    }
};