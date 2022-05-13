class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        sort(aliceSizes.begin(),aliceSizes.end() );
        unordered_set<int>bob(bobSizes.begin(), bobSizes.end());
       long int sumofalice =0, sumofbob =0;
        for(int i : aliceSizes )
            sumofalice +=i;
        for(int i : bobSizes )
            sumofbob += i;
        for(int i : aliceSizes){
         long diff =( sumofbob+i) - (sumofalice-i);
            if(diff%2 == 1)
                continue;
            long searching = diff/2;
            if(bob.find(searching) != bob.end()){
                return {i,(int)searching};
            }
        }
        return {};
    }
};
/**
2j = ( (bsum+i)- (asum -i) )
[5002,10002]
a = 25005002 = 25000000  25000000
                        25020004
 b = 25015002 + 5002

Input: aliceSizes = [1,1], bobSizes = [2,2]


sumofcandiesalice =0 , sumoofcandiesofbob =0
2                               4


[1,
2-1 =1 


j[2,2]
 4-2+1 == 2-1+2
**/
