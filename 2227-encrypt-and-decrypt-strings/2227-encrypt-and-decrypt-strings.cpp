/**
* Leetcode Problem - https://leetcode.com/problems/encrypt-and-decrypt-strings/
* Author - Shubham Nagaria
* Date - 3rd April 2022
Encrypt and Decrypt Strings
**/
class Encrypter {
public:
    unordered_map<char,string>key_value;
    vector<string>dict;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        key_value.clear();
        int n = keys.size();
        for(int i =0; i < n;i++)
            key_value[keys[i]]=values[i];
        dict = dictionary;
        
        
    }
    
    string encrypt(string word1) {
        string res="";
        for(char c : word1)
            res+= key_value[c];
        return res;
    }
    int decrypt(string word2) {
        int n = dict.size();
        int count = 0;
        for(int i =0; i < n ; i++){
            string s = encrypt(dict[i]);
            if(s == word2) count++;
        }
        return count;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */