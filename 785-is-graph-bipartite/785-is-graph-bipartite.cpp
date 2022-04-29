class Solution {
public:
    bool dfs(int srcNode, vector<int>& groupAllocated, vector<vector<int>>& graph) {
	    for(int &neighbourNode	: graph[srcNode]) {
		    if(groupAllocated[neighbourNode] == -1) {
		    	groupAllocated[neighbourNode] = 1 -  groupAllocated[srcNode];
		    	if(!dfs(neighbourNode, groupAllocated, graph))
			    	return false;
	    	}
	    	else if(groupAllocated[srcNode] == groupAllocated[neighbourNode]) {
			    return false;
		    }
	    }
    	return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int totalNodes = graph.size();
        vector<int> groupAllocated(totalNodes, -1); // -1 denotes no group allocated
        for(int node = 0; node < totalNodes; node++) {
            if(groupAllocated[node] == -1) {
                groupAllocated[node] = 1; // allocating 1st group
                if(!dfs(node, groupAllocated, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
};