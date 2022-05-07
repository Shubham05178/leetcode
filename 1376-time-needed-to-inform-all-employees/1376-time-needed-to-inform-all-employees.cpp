class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>mangerToEmployees[n + 1];
        for(int idx = 0; idx < n; idx++) {
          if(manager[idx] != -1)
              mangerToEmployees[manager[idx]].push_back(idx);
        }
      vector<int>time(n);
      queue<int>informingEmployees;
      informingEmployees.push(headID);
      int maxTime = 0;
      while(informingEmployees.size() > 0){
        int manager = informingEmployees.front();
        informingEmployees.pop();
        for(int emp : mangerToEmployees[manager]){
            time[emp] = (time[manager] + informTime[manager]);
            informingEmployees.push(emp);
            maxTime = max(maxTime, time[emp]);
        }
      }
      return maxTime;
    }
};

/**
n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
[manager[i]+1].push(i+1)

**/