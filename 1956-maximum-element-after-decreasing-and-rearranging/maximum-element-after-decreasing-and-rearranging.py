class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:

        if len(arr) == 1:
            return 1 

        #Sort to minimize their personal difference 
        arr.sort()

        #Do decrement first , if it is more than 1 
        if arr[0] > 1 : 
            arr[0] = 1 
        
        #Loop 
        for i in range(1, len(arr)):
            #If in condition do nothing 
            if abs(arr[i] - arr[i - 1])  <= 1 : 
                continue 
            #else just increment by one to meet the condition ! (We need to find the maximum possible value , and from the above condition we can do that only by incrementing each element on failed condition !Thats why we increment and not put 0 here !)
            else : 
                arr[i] = arr[i - 1] + 1
        return max(arr)
        