class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 1) return 0;

        int slow = 0, fast = 1;
        int total = 0;
        
        while(slow < height.size() && fast < height.size()){
            if(height[slow] <= height[fast]){
                int high = std::min(height[slow], height[fast]);
                for(int i = slow + 1; i < fast; ++i){
                    total += (high - height[i]);
                }
                slow = fast;
                fast++;
            }
            else fast++;
        }
        
        int check = slow;
        slow = height.size() - 1;
        fast = height.size() - 2;
        while(slow >= check && fast >= check){
            if(height[slow] <= height[fast]){
                int high = std::min(height[slow], height[fast]);
                for(int i = slow - 1; i > fast; --i){
                    total += (high - height[i]);
                }
                slow = fast;
                fast--;
            }
            else fast--;    
        }

        return total;

    }
};
