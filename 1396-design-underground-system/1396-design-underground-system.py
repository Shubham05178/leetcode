class UndergroundSystem:
    def __init__(self):
        self.avgSumCountSrcDes={}
        self.checkin={}
    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.checkin[id]=list()
        self.checkin[id].append(stationName)
        self.checkin[id].append(t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        p = self.checkin[id]
        key = p[0]+"_"+stationName
        if key in self.avgSumCountSrcDes:
            self.avgSumCountSrcDes[key][1] += t-p[1]
            self.avgSumCountSrcDes[key][2] +=1
            self.avgSumCountSrcDes[key][0]= self.avgSumCountSrcDes[key][1]/self.avgSumCountSrcDes[key][2]
        else:
            self.avgSumCountSrcDes[key]=[t-p[1],t-p[1],1]
    
    def getAverageTime(self, startStation: str, endStation: str) -> float:
        key = startStation+"_"+endStation
        return self.avgSumCountSrcDes[key][0]


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)