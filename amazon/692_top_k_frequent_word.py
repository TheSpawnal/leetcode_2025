import heapq
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        dic = {}
        for word in words:
            dic[word] = dic.get(word, 0) + 1
        p = []
        for key,val in dic.items():
            heapq.heappush(p, (-val,key))
        res = []
        for _ in range(k):
            res.append(heapq.heappop(p)[1])
        return res