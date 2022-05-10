class Solution {
public:
    vector<string> ans;
    void solver(string res, int open, int closed, int size,int tempsize){
        if(tempsize == (size<<1) ){
        if(open == size && closed == size)
            ans.push_back(res);    
        return;
        }
        if(open >= closed){
            solver(res+"(", open+1, closed,size,tempsize+1 );
        }
        if(open>closed){
            solver(res+")", open, closed + 1,size,tempsize+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        solver("",0,0,n,0);
        return ans;
    }
};