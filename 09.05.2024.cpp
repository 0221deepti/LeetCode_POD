class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        long long count=0;
        long long sum=0;
        sort(happiness.begin(),happiness.end());
             for(int i=n-1;i>=0;i--){
                int x=happiness[i]-count;
              sum=sum+max(x,0);
               count++;
               if(count>=k){
                break;
               }
             
           
        }
        return sum;
        
    }
};
