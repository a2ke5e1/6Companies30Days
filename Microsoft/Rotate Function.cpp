// Rotate Function

#include <algorithm>

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        vector<int> x;

        int sum=0;
        int nsum=0;

        for(int i= 0; i < nums.size(); i++){
            sum += nums[i];
            nsum += i * nums[i];
        }

        x.push_back(nsum);
        int k = nsum;
        
        for(int i=1; i< nums.size(); i++){
            k +=  sum - nums.size()*(nums[nums.size() - i]);
            x.push_back(k);
        }
        return *std::max_element( x.begin(), x.end() ); 
    }
};