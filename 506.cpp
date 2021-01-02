class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<int, vector<int>, less<int>> mypq;
        vector<string> res(nums.size());
        unordered_map<int, int> mymap;
        for(int i = 0; i < nums.size(); i++) {
            mypq.push(nums[i]);
            mymap[nums[i]] = i;
        }
        int rank = 1;
        while( mypq.empty() == false) {
            int points = mypq.top();
            int index = mymap[points];
            mypq.pop();
            if (rank == 1) {
                res[index] = "Gold Medal";
            }
            else if (rank == 2) {
                res[index] = "Silver Medal";
            }
            else if (rank == 3) {
                res[index] = "Bronze Medal";
            }
            else {
                res[index] = to_string(rank);
            }
            rank ++;
        }
        return res;
    }
};