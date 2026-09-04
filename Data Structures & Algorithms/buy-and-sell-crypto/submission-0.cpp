class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int ans = 0;
        for(auto price : prices){
            if(price < minprice) minprice = price;
            ans = std::max(ans, price - minprice);
        }
        
        return ans;
    }
};
