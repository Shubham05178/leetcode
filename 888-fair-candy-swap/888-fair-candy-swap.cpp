class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        long int asum = 0, bsum = 0;
        for(int idx: aliceSizes)
            asum+= idx;
         for(int idx : bobSizes)
            bsum+= idx;
        for(int idx :aliceSizes){
            for(int idy: bobSizes){
                if((asum-idx+idy) ==( bsum -idy +idx))
                return {idx,idy};
            }
        }
        return {};
    }
};

/**
aliceSizes = [1,1], bobSizes = [2,2]


alicesum =2 bobsum = 4

alicsum =2 -1 +2 = 3
bobsum = 4+1-2=3





**/
// 