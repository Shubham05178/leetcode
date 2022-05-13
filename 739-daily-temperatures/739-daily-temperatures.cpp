class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int size = temperatures.size() - 1;
        vector<int>ans(size+1);
        for(int idx = size; idx >= 0; --idx){
            while(!st.empty() && temperatures[st.top()] <= temperatures[idx])
                st.pop();
            if(st.empty()) ans[idx] = 0;
            else ans[idx] = st.top() - idx;
        st.push(idx);
        }
    return ans;
    }
};
/**
[73,74,75,71,69,72,76,73]
0   1.  2  3  4 5.  6  7


[              1,1 , 4,    2,  1 ,1,0,0 ]

[89,62,70,58,47,47,46,76,100,70]

st FRNT = TOP[0,1,2,6]
**/