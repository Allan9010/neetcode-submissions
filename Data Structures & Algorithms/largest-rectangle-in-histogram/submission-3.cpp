class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        st.push({heights[0], 0});
        int vsize = heights.size();
        int ans = 0;

        for(int i = 1; i < vsize; ++i){
            int start = i;
            while(!st.empty() && st.top().first >= heights[i]){
                start = st.top().second;
                ans = std::max(ans, st.top().first * (i - start));
                st.pop();
            }
            st.push({heights[i], start});
        }
        while(!st.empty()){
            ans = std::max(ans, st.top().first * (vsize - 1 - st.top().second + 1));
            st.pop();
        }

        return ans;
    }
};
//區間高度會被最低限制
//大於時推入
//小於或掃完時，對所有在stack內小於的數結算並推入
//top保持當前區間的最大高