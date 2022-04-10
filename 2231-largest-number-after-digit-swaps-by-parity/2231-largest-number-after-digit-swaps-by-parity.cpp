/**
* Leetcode Problem - https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/
* Author - Shubham Nagaria
* Date - 10th April 2022
Largest Number After Digit Swaps by Parity
**/
class Solution {
public:
    int largestInteger(int num){
        string s = to_string(num);
        int l = s.size();
        int arr[l];
        string even="";
        string odd="";
        memset(arr,0,sizeof(arr));
        for(int i =0; i <l;i++){
            if(((s[i]-'0')%2) == 0){
                even += s[i];
                arr[i] = 1;
            }
            else
                odd += s[i];
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        int evenid = even.size()-1;
        int oddid = odd.size()-1;
        int number =0;
        for(int i =0 ; i < l;i++){
            if(arr[i]== 0)
                number= number*10+ (odd[oddid--]-'0');
            else
                number = number*10 + (even[evenid--]-'0');
        }
        return number;
    }
};