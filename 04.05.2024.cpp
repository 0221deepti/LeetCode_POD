class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int start=0;
        int end=n-1;
        int res=0;
        while(start<=end){
          if(people[start]+people[end]<=limit){
            start++;
          }
          end--;
          res++;
        }
        return res;
    }
};
// also  if((start!=end) && (people[start]+people[end]<=limit))
