class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }else if(nums[0]<nums[nums.size()-1]){
            return nums[0];
        }
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(mid != 0 && nums[mid] < nums[mid-1]){
                return nums[mid];
            }else if(mid != nums.size() - 1 &&  nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            else if(nums[start]<nums[mid]){// left part is sorted
                start=mid+1;
            }
            else{//right part sorted
                end=mid-1;
            }
        }
        return -1;
    }
};