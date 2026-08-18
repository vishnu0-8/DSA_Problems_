class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int n=nums.size();
       if(n==1){
        cout<<nums[0];
       } 
       else{
        int i=0;
        int j=0;
         while(j<n){
        if(nums[i]!=0&&nums[j]!=0){
            i++;
            j++;
        }
        else if(nums[i]==0&&nums[j]==0){
            j++;
        }
        else if(nums[i]==0&&nums[j]!=0){
            swap(nums[i],nums[j]);
            i++;

        }}
       }
    }
};