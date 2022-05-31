class Solution {
public:
    bool check(vector<int>& bloomDay,int days, int m, int k){
        int count = 0, lc =0;
        for(int elem :bloomDay ){
            if(elem <= days)
                lc++;
            else
                lc = 0;
            if(lc == k){
                count++;
                lc = 0;
            }
        }
        return count >= m;
    } 
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n< m *k) return -1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int ans = high, mid;
        while(low <= high){
            mid = low + ((high - low)>>1);
            if(check(bloomDay,mid,m,k)){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};