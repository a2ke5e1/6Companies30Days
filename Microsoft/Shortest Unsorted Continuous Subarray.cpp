class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int i;
        int lo = 0;
        int n = nums.size();
        int hi = n-1;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        vector<int> mLR(n), mRL(n);
        
        for(i=0;i<n;i++) {
            maxi = max(maxi, nums[i]);
            mLR[i] = maxi;
        }
        
        for(i=n-1;i>=0;i--) {
            mini = min(mini, nums[i]);
            mRL[i] = mini;
        }

        while(lo < n && nums[lo] <= mRL[lo]) lo++;
        while(hi > lo && nums[hi] >= mLR[hi]) hi--;
        return hi-lo+1;
    }
};