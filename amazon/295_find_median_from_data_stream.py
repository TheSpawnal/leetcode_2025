class MedianFinder:

    def __init__(self):
        self.low = []
        self.high = []

    def addNum(self, num: int) -> None:
        heappush(self.low, - num)
        heappush(self.high, - self.low[0])
        heappop(self.low)
        
        if len(self.low) < len(self.high):
            heappush(self.low, -self.high[0])
            heappop(self.high)

    def findMedian(self) -> float:
        if len(self.low) > len(self.high):
            return -self.low[0]
        else:
            return (self.high[0] - self.low[0]) / 2 
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()

#very descent memory usage
class MedianFinder:

    def ___init__(self):
        self.array = []

    def addNum(self, num: int) -> None:
        self.array.append(num)
    def findMedian(self)->float:
        self.array.sort()
        n = len(self.array)
        if n % 2 == 1:
            return self.array[n//2]
        else:
            return (self.array[n//2] + self.array[(n//2)-1])/2
