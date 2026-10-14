class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        string ans ="";

        int nine = sum/9;

        int rem = sum -(nine*9);

        if(rem>0){
            int minDigits = nine + 1;
            if(minDigits>num){
                return "";
            }

            for(int i=0;i<nine;i++){
                ans+='9';
            }

            ans+=rem+'0';

            while(ans.size()<num){
                ans+='0';
            }
        }else{

            if(nine>num){
                return "";
            }

             for(int i=0;i<nine;i++){
                ans+='9';
            }

            

            while(ans.size()<num){
                ans+='0';
            }
        }

        return ans;
    }
};