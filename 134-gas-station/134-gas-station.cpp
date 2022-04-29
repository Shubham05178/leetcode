class Solution {
public:
    int canCompleteCircuit(vector<int>& A, vector<int>& B) {
        int N = A.size(), gas = 0, mini = INT_MAX, id;
	    for(int idx = 0; idx < N; ++idx) { 
		    gas += A[idx] - B[idx];
		    if(gas < mini) {
		        id = idx + 1;
    	        mini = gas;
		    }
	    }
	    if(gas >= 0) return id % N;
	    else return -1;
    }
};