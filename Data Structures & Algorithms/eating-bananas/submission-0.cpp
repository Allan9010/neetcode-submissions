class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxpile = 0;
        for(auto pile : piles){
            if(maxpile < pile) maxpile = pile;
        }

        int right = maxpile;
        int left = 1;
        int ans = 0;
        while(right >= left){
            int mid = (right + left) / 2;
            int total = 0;
            for(auto pile : piles){
                total += (pile + mid - 1) / mid;
            }
            if(total > h) left = mid + 1;
            else if(total <= h){
                ans = mid;
                right = mid - 1;
            }
        }

        return ans; 
    }
};
