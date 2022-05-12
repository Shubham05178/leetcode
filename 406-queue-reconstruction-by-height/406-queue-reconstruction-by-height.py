class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end());
        int size = people.size();
        vector<vector<int>>ans(size, vector<int>(2,-1));
        for(int idx = 0; idx < size; idx++){
            int count = people[idx][1];
            int idy = 0;
            while(idy < size){
                if(count == 0 && ans[idy][0] == -1)
                    break;
                else if( ans[idy][0] == -1 || ans[idy][0] >= people[idx][0])
                    count--;
                idy++;
            }
            ans[idy]= people[idx];
        }
        return ans;
    }
};