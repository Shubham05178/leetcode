class Solution {
public:
    void nextPermutation( vector<int>& nums ) {
        int lenOfnums = nums.size(), indexOfFirstSwap, indexOfnextSwap, indexForNextgreaterElement, diff, maxDiff = INT_MAX;
        // finding the first index where element can swap with. (lets take as indexOfFirstSwap)
        for( indexOfFirstSwap  = lenOfnums - 2; indexOfFirstSwap >= 0; indexOfFirstSwap-- ) {
            if ( nums[ indexOfFirstSwap ] < nums[ indexOfFirstSwap + 1] ) {
                break;
            }
        }
        // we had found the index where we can swap our element now
        if( indexOfFirstSwap > -1 ) {
            // finding the index with which it can swap( i.e., indexOfFirstSwap ) (let's name as indexForNextgreaterElement) in this we iterate over variable as indexOfnextSwap
            for( indexOfnextSwap = lenOfnums - 1; indexOfnextSwap > indexOfFirstSwap; indexOfnextSwap-- ) {
                // finding the next maximum number out of that by using differnce concept i.e., any num's next will be nums + diff . and diff should be > 0 and minimized
                diff = nums[ indexOfnextSwap ] - nums[ indexOfFirstSwap ];
                if ( diff > 0 && diff < maxDiff ){
                    indexForNextgreaterElement = indexOfnextSwap;
                    maxDiff = diff;
                }
            }
            //now swapping indexes data at indexes indexOfFirstSwap and indexForNextgreaterElement
            swap( nums[ indexOfFirstSwap ] , nums[ indexForNextgreaterElement ] );
            // after   indexOfFirstSwap + 1 indexes we can sort for getting next permuation.
            sort( nums.begin() + indexOfFirstSwap + 1, nums.end() );
        }
        else {  // else if we did not found any first index where element can swap with i.e., when our array is increasing order from righ tto left.
            // sort in increasing order because such arrangement is not possible, the array must be rearranged as the lowest possible order
            sort( nums.begin(), nums.end() );
        }
    }
};
        