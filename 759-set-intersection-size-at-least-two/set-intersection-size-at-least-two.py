class Solution:
    def intersectionSizeTwo(self, intervals):
        intervals.sort(key=lambda x: (x[1], -x[0]))
        
        res = 0
        a, b = -1, -1  # last two selected numbers
        
        for l, r in intervals:
            count = (a >= l) + (b >= l)
            
            if count == 2:
                continue
            if count == 1:
                res += 1
                if a >= l:
                    b = r
                else:
                    a = b
                    b = r
            else:
                res += 2
                a = r - 1
                b = r
        
        return res
