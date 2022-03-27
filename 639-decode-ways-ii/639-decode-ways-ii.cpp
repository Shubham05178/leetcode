
class Solution {
public:
    int mod = 1e9+7;
    long long int decodeWays(string &s, int i, long long int dp[]){
        if(i == -1) 
            return 1;
        if(dp[i] != -1) 
            return dp[i];
        long long int ans;
        dp[i] = 0;
        if( i>=0){ 
            ans =  decodeWays(s,i-1,dp);
            ans%=mod;
            if(s[i]=='*')
                    dp[i] += ((9*ans)%mod);
            else if(s[i] > '0')
                    dp[i] += (ans%mod); 
        }
        dp[i]%=mod;
       if(i>0){ 
           ans = decodeWays(s, i-2,dp);
           ans%=mod;
            if(s[i-1]=='*' && s[i]=='*')
                dp[i] += ((15* ans)%mod);
           else if(s[i-1]=='*'){
               dp[i]+=  (ans%mod);
              int n = s[i]- '0';
              if(n<=6){
                  dp[i] +=  (ans%mod);
              }
             }
             else if(s[i]== '*'){
                if(s[i-1]=='1')
                     dp[i] += ((9*ans)%mod);
                else if(s[i-1]=='2')
                        dp[i] += ((6* ans)%mod);   
            }
            else{ 
                int num = (s[i-1]-'0') * 10 + (s[i]-'0');
                if(num >9 && num <= 26)
                    dp[i] += (ans%mod);
            }
        }
        return dp[i]%mod;
    }
    int numDecodings(string s) {
        int n = s.size();
        long long int dp[n];
        memset(dp,-1,sizeof(dp));
        return decodeWays(s,n-1,dp);
    }
};