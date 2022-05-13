class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
       long int sumofalice =0, sumofbob =0;
        for(int i : aliceSizes )
            sumofalice +=i;
        for(int i : bobSizes )
            sumofbob += i;
        for(int i : aliceSizes){
            for(int j : bobSizes){
                if((sumofalice+j)-i == (sumofbob+i)-j)
                    return {i,j};
            }
        }
        return {};
    }
};