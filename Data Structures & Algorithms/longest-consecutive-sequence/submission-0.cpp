class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int ans = 0;
        for(auto num : nums){
            if (unionHash.count(num)) continue;
            unionHash[num] = num;
            unionLen[num] = 1;

            int currentLen = 1;
            if (unionHash.count(num - 1)){
                currentLen = unionCount(num, num - 1);
            }
            if (unionHash.count(num + 1)){
                currentLen = unionCount(num, num + 1);
            }

            ans = std::max(ans, currentLen);
        }
        return ans;
    }

private:
    unordered_map<int, int> unionHash;
    unordered_map<int, int> unionLen;

    int find(int child){
        int parent = child;
        while(unionHash[parent] != parent){
            parent = unionHash[parent];
        }
        return parent;
    }
    int unionCount(int a, int b){
        int a_parent = find(a);
        int b_parent = find(b);

        if(unionLen[a_parent] >= unionLen[b_parent]){
            unionHash[b_parent] = a_parent;
            unionLen[a_parent] += unionLen[b_parent];
            return unionLen[a_parent];
        }
        else{
            unionHash[a_parent] = b_parent;
            unionLen[b_parent] += unionLen[a_parent];
            return unionLen[b_parent];        
        }
    }
};
