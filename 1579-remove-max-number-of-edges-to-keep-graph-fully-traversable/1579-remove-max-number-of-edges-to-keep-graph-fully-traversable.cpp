/**
* Leetcode Problem - https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
* Author - Shubham Nagaria
* Date - 7th April 2022
Remove Max Number of Edges to Keep Graph Fully Traversable
**/
class Solution {
public:
    int findParent(int arr[],int x){
        if(x==arr[x])
            return x;
        arr[x]=findParent(arr,arr[x]);
        return arr[x];
    }
    int merge(int x, int y, int arr[] ,int &c){
        int p1=findParent(arr,x);
        int p2=findParent(arr,y);
        if(p1!= p2){
            arr[p1] =p2;
            c--;
            return 0;
        }
        return 1;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        int Alice[n+1], Bob[n+1];
        sort(edges.begin(),edges.end(),[] (vector<int> &a, vector<int> &b) { return a[0] > b[0]; });
        for(int i = 0; i < n+1; i++)
            Bob[i]=Alice[i]=i;
        int count = 0;
        int alicecount = n, bobcount = n;
        for(int i = 0 ; i < m; i++){
            if(edges[i][0]==1)
                count += merge(edges[i][1], edges[i][2],Alice,alicecount);
            else if(edges[i][0]==2)
                count += merge(edges[i][1], edges[i][2],Bob,bobcount);
            else
                count+= merge(edges[i][1], edges[i][2],Alice,alicecount) |  merge(edges[i][1], edges[i][2],Bob,bobcount);
        }
        return (alicecount==1 && bobcount ==1) ? count : -1;
    }
};