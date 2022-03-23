/**
* Leetcode Problem - https://leetcode.com/problems/divisor-game/
* Author - Shubham Nagaria
* Date - 23rd March 2022
Divisor Game
**/
class Solution {
public:
    bool divisorGame(int n) {
        return 1-(n%2);
    }
};