class Solution {
public:
    int dfs(int idx, vector<int>& manager, vector<int>&informTime) {
      if(manager[idx] != -1){
        informTime[idx] += dfs(manager[idx], manager, informTime);
        manager[idx]= -1;
      }
      return informTime[idx];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
      int maxTime = 0;
      for(int idx = 0; idx < n; idx++)
        maxTime = max(maxTime, dfs(idx, manager,informTime));
      return maxTime;
    }
};

/**
n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
[manager[i]+1].push(i+1)

**/