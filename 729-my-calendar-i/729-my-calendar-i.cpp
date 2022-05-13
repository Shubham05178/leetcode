class MyCalendar {
public:
    set<pair<int,int>>st;
    MyCalendar() {
        st.clear();
    }
    
    bool book(int start, int end) {
        auto next = st.lower_bound({start,end});
        if( (next != st.end() && next->first < end ) || (next != st.begin() && (--next)->second > start))
            return false;
          st.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */