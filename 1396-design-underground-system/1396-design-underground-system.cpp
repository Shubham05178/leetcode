/**
* Leetcode Problem - https://leetcode.com/problems/design-underground-system/
* Author - Shubham Nagaria
* Date - 24th April 2022
Design Underground System
**/
class UndergroundSystem {
public: 
    unordered_map<string,vector<double>>avgSumcountSourceDestination;
    unordered_map<int,pair<string,int>>checkin;
    UndergroundSystem() {
        avgSumcountSourceDestination.clear();
        checkin.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        checkin[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
            auto idxCheckin = checkin[id];
            string key = idxCheckin.first +"_"+stationName;
            double time = t - idxCheckin.second;
            if(avgSumcountSourceDestination.find(key)!= avgSumcountSourceDestination.end()){
                avgSumcountSourceDestination[key][1] += time;
                avgSumcountSourceDestination[key][2]++;
                avgSumcountSourceDestination[key][0]= avgSumcountSourceDestination[key][1]/avgSumcountSourceDestination[key][2];
            }
            else{
                avgSumcountSourceDestination[key]={time,time,1};
            }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation +"_" + endStation;
        return avgSumcountSourceDestination[key][0];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */