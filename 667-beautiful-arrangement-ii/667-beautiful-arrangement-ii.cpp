class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int>ans;
        int start =1, end = n;
        ans.push_back(start++);
        while(k > 1){    
            ans.push_back(end--);
            k--;
            if(k > 1){
                ans.push_back(start++);
                k--;
            }
        }
        if(ans.back() == start-1){
            while(start <= end)
                ans.push_back(start++);
        }
        else{
            while(start <= end){
                ans.push_back(end--);
            }
        }
        return ans;
    }
};