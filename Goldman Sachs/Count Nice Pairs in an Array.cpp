class Solution {
public:
    int countNicePairs(vector<int>& nums) {
       int pairs = 0; 
       int m = 1e9 + 7; 
        for (int i = 0; i < nums.size(); i++) {
            int m = nums[i]; 
            nums[i] -= rev(m); 
        }
        unordered_map<int,int> mp; 
        for(int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = 0; 
            } else {
                mp[nums[i]]++; 
                pairs = (pairs + mp[nums[i]]) % m;
            }
        }

       return pairs % m; 
    }

    int rev(int n) {
        int x = 0;
        int t = n;
        int l = n > 0 ? (int)log10((double) n) + 1: 1;
        while (t > 0) {
            int r = t % 10; 
            x += r * pow(10, l - 1); 
            t /= 10; 
            l--; 
        }
        return x; 
    } 

};