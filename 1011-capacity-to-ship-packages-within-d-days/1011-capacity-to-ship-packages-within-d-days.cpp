class Solution {
public:
    bool canShip(vector<int> arr, int days,int cap){
        int d=1;
        int cur=0;
        for(auto weight :arr){
            if(cur+weight >cap){
                d++;
                cur=weight;
            }
            else{
                cur+=weight;
            }
        }
        return d<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans; 
        while(low<=high){
            int mid = low+(high-low)/2;
            if(canShip(weights,days,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;

    }
};