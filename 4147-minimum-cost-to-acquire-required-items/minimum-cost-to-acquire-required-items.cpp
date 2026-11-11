class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans =0;

        if(costBoth<cost1+cost2){
            ans+=(min(need1,need2)*1LL*costBoth);
            if(need1>need2){
            int extra = need1-need2;
            if(cost1>costBoth){
                ans+=extra*1LL*costBoth;
            }else{
                ans+=extra*1LL*cost1;
            }
        }else{
             int extra = need2-need1;
            if(cost2>costBoth){
                ans+=extra*1LL*costBoth;
            }else{
                ans+=extra*1LL*cost2;
            }
        }
        }else{
            ans+=cost1*1LL*need1;
            ans+=cost2*1LL*need2;
        }

        

        return ans;
    }
};