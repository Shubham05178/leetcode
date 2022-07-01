class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x: -x[1])
        noOfUnits = 0
        for box,Unit in boxTypes:
            take = min(box, truckSize)
            truckSize -= take
            noOfUnits += take * Unit
        return noOfUnits
        
        
        