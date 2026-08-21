class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        long long sum=0;
        long long maxSum=0;
        int distinct=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            mp[nums[i]]++;
            if(mp[nums[i]]==1){
                distinct++;
            }
        }
        if(distinct == k){
            maxSum=sum;
        }
        for(int j=k;j<nums.size();j++){
            // adding next element and increasing its fre;
            sum+=nums[j];
            mp[nums[j]]++;
            if(mp[nums[j]]==1){
                distinct++;
            }
            sum-=nums[j-k];
            mp[nums[j-k]]--;
            if(mp[nums[j-k]] == 0) {
                distinct--;
                mp.erase(nums[j-k]);
            }
            if(distinct == k) {
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;

    }
};