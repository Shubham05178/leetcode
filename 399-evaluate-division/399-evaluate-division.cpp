class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string, double>>>graph;
        vector<double>res;
        string src,des, intermediateSrc;
        double ans, newVal, val;
        int lenOfInput = values.size();
        for(int idx = 0; idx < lenOfInput; idx++) {
	        graph[equations[idx][0]].push_back({equations[idx][1],values[idx]});	
	        graph[equations[idx][1]].push_back({equations[idx][0],1/values[idx]});
        }
        for(auto &query : queries) {
	        ans = -1;
            src = query[0];
            des = query[1];
            if(graph.find(src) != graph.end() && graph.find(des) != graph.end()) {
                queue<pair<string,double>>que;
	            unordered_set<string>visited;
	            que.push({src,1});
	            visited.insert(src);
	            while(que.size() > 0) {
		            auto top = que.front();
                    que.pop();
		            intermediateSrc = top.first;
		            val = top.second;
		            if(intermediateSrc == des) {
                        ans = val;
		                break;
		            }
		            for( auto neighbours : graph[intermediateSrc]) {
		                if(visited.find(neighbours.first) == visited.end()) {
                            visited.insert(neighbours.first);
			                newVal = val * neighbours.second;
			                que.push({neighbours.first, newVal});
		                }
                    }
	            }
            }
	        res.push_back(ans);
	    }
	return res;
    }
};