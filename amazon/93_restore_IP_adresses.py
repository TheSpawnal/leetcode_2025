
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        result=[]
        self.backtrack(s, 0,0, "", result)
        return result

    def backtrack(self, s, start, dots, path, result):
        if dots == 4 and start == len(s):
            result.append(path[:-1]) # remove trailling dot
            return
        if dots > 4 or start >= len(s):
            return
        for length in range(1,4):
            if start + length > len(s):
                break
            segment = s[start:start+ length]
            if self.isValid(segment):
                self.backtrack(s, start+length, dots+1, path+segment+'.', result)
            
    def isValid(self, segment):
        if len(segment) > 3 or (segment.startswith('0') and len(segment) > 1):
            return False
        val = int(segment)
        return 0 <= val <= 255



#iterative approach using nested loops
class Solution:
    def restoreIpAddresses(self, s:str) -> List[str]:
        result = []
        n = len(s)
        for i in range(1, min(n, 4)):
            for j in range(i+1, min(n, i+4)):
                for k in range(j+1, min(n, j+4)):
                    s1 = s[:i]
                    s2 = s[i:j]
                    s3 = s[j:k]
                    s4 = s[k:]
                    if all(map(self.isValid, [s1,s2,s3,s4])):
                        result.append(f"{s1}.{s2}.{s3}.{s4}")
        return result

    def isValid(self, segment):
        if len(segment) == 0 or len(segment) >3:
            return False
        if segment.startswith('0') and len(segment) >1:
            return False
        val = int(segment)
        return 0 <= val <= 255