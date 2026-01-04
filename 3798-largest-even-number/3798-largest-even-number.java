class Solution {
    public String largestEven(String s) {
        int lastTwoIndex = s.lastIndexOf('2');
        
        // If no '2' exists, no even number can be formed
        if (lastTwoIndex == -1) {
            return "";
        }
        
        // Keep everything up to and including the last '2'
        return s.substring(0, lastTwoIndex + 1);
    }
}

