class Solution {
public:
    void traverse(int pos, int n, vector<bool> &vis, int& count){
        if(pos > n)
            count++;
        for(int idx = 1; idx <= n; idx++){
            if(!vis[idx] && (pos % idx == 0 || idx % pos == 0)){
                vis[idx] = true;
                traverse(pos + 1, n, vis, count);
                vis[idx] = false;
            }
        }
    }
    int countArrangement(int n) {
        int count = 0;
        vector<bool>vis(n+1,false);
        traverse(1,n,vis,count);
        return count;
    }
};