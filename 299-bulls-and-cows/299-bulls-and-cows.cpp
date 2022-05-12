class Solution {
public:
    string getHint(string secret, string guess) {
        int arr[10];
        int cA = 0,cB = 0;
        int size = secret.size();
        memset(arr,0,sizeof(arr));
        for(int idx = 0; idx < size; idx++ ){
            if(secret[idx] == guess[idx]){
                cA++;
                continue;
            }else{
                if(arr[secret[idx]-'0'] < 0)
                    cB++;
                arr[secret[idx]-'0']++;
                arr[guess[idx]- '0']--;
                if(arr[guess[idx]-'0'] >= 0)
                    cB++;
            }
        }
        return to_string(cA)+"A"+to_string(cB)+"B";
    }
};