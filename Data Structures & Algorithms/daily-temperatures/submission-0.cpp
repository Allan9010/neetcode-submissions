class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size(), 0);
        st.push(0);

        for(int i = 1; i < temperatures.size(); ++i){
            int curtemp = temperatures[i];
            while(!st.empty() && curtemp > temperatures[st.top()]){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
