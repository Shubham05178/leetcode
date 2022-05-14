class Solution {
public:
    vector<string> removeComments(vector<string>& a) {
        vector<string>ans;
        string interm, check;
        bool flag = false;
        for(string line : a){
            for(int idx =0; idx< line.size(); idx++){
                check = line.substr(idx,2);
                if(!flag){
                    if(check == "//") break;
                    else if(check == "/*") {
                        idx++;
                        flag = true;
                    }
                    else interm.push_back(line[idx]);
                }else if(check == "*/"){
                    idx++;
                    flag = false;
                }
            }
            if(!flag && interm.size()) {
                ans.push_back(interm);
                interm.clear();
            }
        }
        return ans;
    }
};