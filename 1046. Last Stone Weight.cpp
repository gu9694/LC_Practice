class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int len = stones.size();
        if (len == 1) {
            return stones[0];
        }
        priority_queue<int, vector<int>, less<int>> mypq;
        for (auto i : stones) {
            mypq.push(i);
        }
        while(mypq.empty() == false) {
            int first = mypq.top();
            mypq.pop();
            if (mypq.empty() == true) {
                return first;
            } else {
                int second = mypq.top();
                mypq.pop();
                if (first > second) {
                    mypq.push(first - second);
                }
            }
        }
        return 0;
    }
};