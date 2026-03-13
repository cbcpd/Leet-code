
class Solution {
public:
    int cal(int val, vector<long long > &pre, long long x){
        long long l=0;
        long long r=pre.size()-1;
        int ans=-1;

        while(l<=r){
            long long mid=l+(r-l)/2;
            if(pre[mid]*(long long )val<=x){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }

        return ans;

    }
    bool check(int m, vector<int> &w, long long x,vector<long long > &pre){
       
        // [2,1,1] //ith worker ne kitni h reduce kari x sec
        // 2,[1,3,6,10,,]
        // 2,6,12,12,..
        // ans = 3 sec possible hai  ? 
        for(int i=0;i<w.size();i++){
            int p=cal(w[i],pre,x);
            if(p!=-1){
                m-=(p+1);
            }
        }

        if(m<=0){
            return true;
        }
        return false;

    }
    long long minNumberOfSeconds(int m, vector<int>& w) {
        
        long long o=(long long )m*(long long )(m+1)/2;
        long long u=*max_element(w.begin(),w.end());
        
        long long r=o*u;
    
        long long l=0;
        long long ans=pow(10,16);

        vector<long long > pre;
        pre.push_back(1);
        long long t=2;
        while(1){
            if(pre.size()>m){
                break;
            }
            pre.push_back(pre[pre.size()-1]+t);
            t++;
        } 

        // pre = [1,3,6,10,15,21,...]

        while(l<=r){
            long long mid=l+(r-l)/2;
            if(check(m,w,mid,pre)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return ans;

    }
};