
class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        // Initialize a StringBuilder to store the result
        StringBuilder result = new StringBuilder();
        
        // Determine the sign of the result
        String sign = (numerator < 0 == denominator < 0 || numerator == 0) ? "" : "-";
        
        // Convert numerator and denominator to absolute values
        long num = Math.abs((long) numerator);
        long den = Math.abs((long) denominator);
        
        // Append the sign to the result
        result.append(sign);
        
        // Append the quotient to the result
        result.append(num / den);
        
        // Calculate the remainder
        long remainder = num % den;
        
        // If there is no remainder, return the result
        if (remainder == 0)
            return result.toString();
        
        // Append the decimal point
        result.append(".");
        
        // Create a HashMap to store the remainder and its position in the result
        HashMap<Long, Integer> remainderMap = new HashMap<Long, Integer>();
        
        // Keep track of the remainders
        while (!remainderMap.containsKey(remainder)) {
            remainderMap.put(remainder, result.length());
            result.append(10 * remainder / den);
            remainder = 10 * remainder % den;
        }
        
        // Get the position of the repeating remainder
        int repeatingRemainderIndex = remainderMap.get(remainder);
        
        // Insert the opening parenthesis at the repeating remainder's position
        result.insert(repeatingRemainderIndex, "(");
        
        // Append the closing parenthesis
        result.append(")");
        
        // Return the final result, with any "(0)" removed
        return result.toString().replace("(0)", "");
    }
}