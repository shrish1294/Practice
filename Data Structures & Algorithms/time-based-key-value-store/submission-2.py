from sortedcontainers import SortedList
class TimeMap:

    def __init__(self):
        self.mapper = defaultdict(SortedList)
        self.cntr = 0
        self.maps = defaultdict(str)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.cntr +=1
        self.mapper[key].add((timestamp, self.cntr))
        self.maps[self.cntr] = value
        

    def get(self, key: str, timestamp: int) -> str:
        
        if self.mapper.get(key):
            idx = self.mapper[key].bisect_right((timestamp, self.cntr + 1))
            idx-=1
            if idx >=0 :
                cntr =  self.mapper[key][idx][1]
                return self.maps[cntr]

        return ""
