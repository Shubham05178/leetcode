class Solution {
public:
    string getHint(string secret, string guess) {
        int arr[10];
        int countbulls = 0,countcows =0;
        int size = secret.size();
        memset(arr,0,sizeof(arr));
        for(int idx = 0; idx < size; idx++ ){
            if(secret[idx] == guess[idx]){
                countbulls++;
                continue;
            }else{
                if(arr[secret[idx]-'0'] < 0){
                    countcows++;
                }
                arr[secret[idx]-'0']++;
                arr[guess[idx]- '0']--;
                if(arr[guess[idx]-'0'] >= 0){
                    countcows++;
                }
            }
        }
        return to_string(countbulls)+"A"+to_string(countcows)+"B";
    }
};