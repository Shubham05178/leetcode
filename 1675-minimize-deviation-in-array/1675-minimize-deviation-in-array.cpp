class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int> s;
        for(int &i : nums)
            s.insert( i % 2 ? i * 2 : i);
    int minDeviation = *s.rbegin() - *s.begin();
    while(((*s.rbegin()) % 2) == 0) {
            s.insert(*s.rbegin()/2);
            s.erase(*s.rbegin());
            minDeviation = min(minDeviation, *s.rbegin() - *s.begin());
        }
        return minDeviation;
    }
};

// insert in set so that our element will maintain order and unique
//insert in this way(change every odd to even by multiplying by 2 and even will be the same element)
// now try to reduce to last element(i.e greater element) if it is even by insert half of that element and removing that element.
// we will maintain minDeviation by min difference by last element and first element of set. 