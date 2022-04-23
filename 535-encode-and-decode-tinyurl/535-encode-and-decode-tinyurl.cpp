/**
* Leetcode Problem - https://leetcode.com/problems/encode-and-decode-tinyurl/
* Author - Shubham Nagaria
* Date - 23rd April 2022
Encode and Decode TinyURL
**/
class Solution {
public:
    string tinyurl = "http://tinyurl.com/";
    unordered_map<string,string>encodeurls;
    string getRandom(int length){
        string alphanumeric = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        string resultstring;
        for(int index = 0; index < length ; index++)
            resultstring += alphanumeric[rand()%alphanumeric.size()];
        return resultstring;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string tiny = tinyurl+getRandom(6);
        if(encodeurls.find(tiny)!=encodeurls.end())
            return encode(longUrl);
        encodeurls[tiny]= longUrl;
        return tiny;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return encodeurls[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));