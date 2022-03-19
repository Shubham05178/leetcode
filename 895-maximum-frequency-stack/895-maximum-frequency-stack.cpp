/**
* Leetcode Problem - https://leetcode.com/problems/maximum-frequency-stack/submissions/
* Author - Shubham Nagaria
* Date - 19th March 2022
Maximum Frequency Stack
**/
class FreqStack {
public:
    unordered_map<int,stack<int>>mfs;
    unordered_map<int,int>freq;
    int m;
    FreqStack() {
        mfs.clear();
        freq.clear();
        m=0;
    }
    
    void push(int val) {
        freq[val]++;
        mfs[freq[val]].push(val);
        m = max(m, freq[val]);
    }
    
    int pop() {
        int val = mfs[m].top();
        mfs[m].pop();
        freq[val]--;
        if(mfs[m].size()==0) m--;
        return val;
    }    
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */