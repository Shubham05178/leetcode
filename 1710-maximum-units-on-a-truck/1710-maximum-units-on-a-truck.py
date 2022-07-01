class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x: -x[1])
        noOfUnits = 0
        for boxType in boxTypes:
            if boxType[0] <= truckSize:
                truckSize -= boxType[0]
                noOfUnits += boxType[0] * boxType[1]
            else:
                noOfUnits += truckSize * boxType[1]
                break
        return noOfUnits
        
        
        