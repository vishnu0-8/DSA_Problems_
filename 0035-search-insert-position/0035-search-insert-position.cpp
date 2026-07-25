class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       if(target<=nums[0]){
        return 0;
       }
        else if(target>nums[nums.size()-1]){
        return nums.size();
       }
       else if(target==nums[nums.size()-1]){
        return nums.size()-1;}
       int start=0;
       int end=nums.size()-1;
       while(start<=end){
        int mid=start+(end-start)/2;
        if(target<=nums[mid]&&target>nums[mid-1]){
            return mid;
        }else if(mid<nums.size()-1&&target>nums[mid]&&target<=nums[mid+1]){
            return mid+1;
        }else if(target>nums[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }
       }
       return 0;
    }
};