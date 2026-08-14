class Solution {
public:
    bool ispalindrome(string s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            else{
                l++;
                r--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int start=0;
        int end=s.length()-1;
        while(start<end){
            if(s[start]!=s[end]){
                return ispalindrome(s,start+1,end)||ispalindrome(s,start,end-1);
            }
            start++;
            end--;
        }
        return true;
    }
};