class Solution {
public:
    int integerReplacement(int n) {
        int count = 0;
        if(n == 1) return count;
        queue<long int>que;
        que.push(n);
        while(que.size()){
            count++;
            int size = que.size();
            while(size--) {
               long int top = que.front();
                que.pop();
                if(top%2==0) {
                    if(top/2 ==1)
                        return count;
                    que.push(top/2);
                }
                else{
                    if(top+1 == 1 || top-1 == 1 )
                        return count;
                    que.push(top + 1);
                    que.push(top - 1);
                }
            }
        }
        return count;
    }
};

/**

**/