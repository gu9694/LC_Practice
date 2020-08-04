class Solution {
public:
    int maxArea(vector<int>& height) {
        int tmp=0;
        int len=height.size();
        int l=0;
        int r=len-1;
        while(l<r)
        {
            int h=min(height[l],height[r]);
            int w= r-l;
            int area= h*w;
            tmp=max(area,tmp);
            if(height[l]>height[r])
            {
                r--;
            }
            else
                l++;
        }
        return tmp;
    }
};
//双指针的移动                                         
