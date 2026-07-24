class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int>arr;
        int m=nums1.size();
        int n=nums2.size();
        int i=0,j=0;
        while(i<m&&j<n){
            if(nums1[i]>=nums2[j]){
                arr.push_back(nums2[j]);
                j++;
            }else{
                arr.push_back(nums1[i]);
                i++;
            }
        }
        while(i<m){
            arr.push_back(nums1[i]);
            i++;
        }
         while(j<n){
            arr.push_back(nums2[j]);
            j++;
        }
        int len=arr.size();
        double mid=0;
        if(len%2!=0){
            mid=arr[(len/2)];
        }
        else{
            mid = (arr[len/2 - 1] + arr[len/2]) / 2.0;
        }
        return mid;

    }
};