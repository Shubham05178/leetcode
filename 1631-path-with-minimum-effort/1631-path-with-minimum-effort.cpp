class Solution {
public:
    int findParent(vector<int> &parent, int node) {
        if(parent[node] == node) {
            return node;
        }
        parent[node] = findParent(parent, parent[node]);
        return parent[node];
    }
    bool Union(vector<int>& parent, int node1, int node2, int src, int des) {
        int p1 = findParent(parent, node1);
        int p2 = findParent(parent, node2);
        if(p1 != p2){
            parent[p1] = p2;
        }
        int srcParent = findParent(parent, src);
        int desParent = findParent(parent, des);
        return srcParent == desParent;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int columns = heights[0].size();
        if(rows == 1 && columns == 1) return 0;
        vector<vector<int>> arr;
        for(int idx = 0; idx < rows; idx++) {
            for(int idy = 0 ; idy < columns; idy++) {
                if(idx - 1 >= 0)
                    arr.push_back({abs(heights[idx - 1][idy] - heights[idx][idy]),(idx - 1) * columns + idy, (idx * columns) + idy});
                if(idy - 1 >= 0)
                    arr.push_back({abs(heights[idx][idy - 1] - heights[idx][idy]), (idx * columns) + (idy - 1), (idx * columns) + idy});
            }
        }
        sort(arr.begin(),arr.end());
        int sizeOfmatrix = rows * columns;
        int src = 0, des = sizeOfmatrix - 1;
        vector<int> parent(sizeOfmatrix);
        for(int id = 0; id < sizeOfmatrix; id++)
            parent[id] = id;
        for(int id = 0; id < arr.size(); id++) {
            if(Union(parent, arr[id][1], arr[id][2], src, des)) {
                return arr[id][0];
            }            
        }
    return arr[sizeOfmatrix - 1][0];
    }
};



// 0,0 (0)<- 0*3+ 0
// 0,1  (1)<- 0*3+1
// 0,2  (2)<- 0*3+2
// 1,0. (3)<- 1*3+0
// 1,1  (4)<- 1*3+1
// (i*m)+j
// 0  1   2
// i*noofelemts+
    
// 3  4.  5
// 3/3 = 1
// 3%3=0
//     4/3 =1
    
// 4%3 = 1
//     1          0
// [1------2---------2]
// |
// 2        6         0
// |   5         6
// [3-----=8=========2]
                                    
//  2         2       3
        
// [5      3         5]


//  1      2---------2
//                   |   
//                    2