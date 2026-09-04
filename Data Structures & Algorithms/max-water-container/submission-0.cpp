class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        for(int i = 0, j = heights.size() - 1; i < j; ){
            int curArea = std::min(heights[i], heights[j]) * (j - i);
            
            ans = std::max(curArea, ans);
            if(heights[i] <= heights[j]) ++i;
            else --j;
        }

        return ans;

        //移動短的
    }
};
