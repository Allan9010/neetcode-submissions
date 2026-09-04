class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2,  nums1);

        int m = nums1.size();
        int n = nums2.size();

        int right = nums1.size();
        int left = 0;
        int half = (m + n) / 2;

        while(left <= right){
            int mid1 = left + (right - left) / 2;
            int mid2 = half - mid1;

            int L1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int R1 = (mid1 == m) ? INT_MAX : nums1[mid1];
            int L2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int R2 = (mid2 == n) ? INT_MAX : nums2[mid2];

            if(L1 <= R2 && L2 <= R1){
                if((m + n) % 2 == 1) return min(R1, R2);
                else return (max(L1, L2) + min(R1, R2)) / 2.0;
            }
            else if(L1 > R2) right = mid1 - 1;
            else left = mid1 + 1;

        }

        return 0.0;
    }
};
//假設中位在1陣列，那2陣列也要找到一個數編號i，使這兩者編號加起來剛好是(m+n)/2
//兩邊各自二元搜尋，然後比較中位數
//[1 4] [2 3]
//[2 4] [1 3]