/**
* Leetcode Problem - https://leetcode.com/problems/design-hashset/
* Author - Shubham Nagaria
* Date - 21st April 2022
Design HashSet
**/
class MyHashSet {
public:
    set<int>s;
    MyHashSet() {
        s.clear();
    }
    
    void add(int key) {
        s.insert(key);
    }
    
    void remove(int key) {
        if(s.find(key)!=s.end())
        s.erase(s.find(key));
    }
    
    bool contains(int key) {
        if(s.find(key)!= s.end())
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */