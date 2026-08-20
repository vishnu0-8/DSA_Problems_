class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int closest = INT_MAX;
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==target){
                    return sum;
                }
                if(sum>target){
                    int diff=abs(sum-target);
                    if(diff<=closest) {
                        closest=diff;
                        ans=sum;
                    }
                    k--;
                }
                if(sum<target){
                    int diff=abs(sum-target);
                    if(diff<=closest) {
                        closest=diff;
                        ans=sum;
                    }
                    j++;
                }
                
            }
            
        }
        return ans;
    }
};