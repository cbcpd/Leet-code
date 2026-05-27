class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        first_upper={}
        last_lower={}

        dict1={}
        for i,val in enumerate(word):
            if val.islower():
                last_lower[val]=i
            else:
                if val not in first_upper:
                    first_upper[val]=i

        count=0

        for i in range(26):
            lower=chr(ord('a')+i)
            upper=chr(ord('A')+i)

            if lower in word and upper in word and last_lower[lower]<first_upper[upper]:
                count+=1

        return count
        