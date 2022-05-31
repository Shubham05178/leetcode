class Solution {
public:
    bool check(vector<int>& bloomDay,int days, int m, int k){
        int countbotique = 0, dayscontinuous = 0;
        for(int elem :bloomDay ){
            if(elem <= days)
                dayscontinuous++;
            else
                dayscontinuous = 0;
            if(dayscontinuous == k){
                countbotique++;
                dayscontinuous = 0;
            }
        }
        return countbotique >= m;
    } 
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n < m * k) 
            return -1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int low  = *min_element(bloomDay.begin(), bloomDay.end());
        int ans = high, mid;
        while(low <= high){
            mid = low + ((high - low) >> 1);
            if(check(bloomDay, mid, m, k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};