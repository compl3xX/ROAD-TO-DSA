class Solution {
public:
    bool isPossible(vector<int>& piles, int h,int mid)
    {   
        int eats=0;
        for(int i=0;i<piles.size();i++)
        {
         
        int x=(piles[i]/mid)+(piles[i]%mid!=0);
            
          if(eats+x<=h){
              eats+=x;
          }
            else {
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int s=1;
        sort(piles.begin(),piles.end());
        int e=piles[piles.size()-1];
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e)
        {
            if(isPossible(piles,h,mid))
            {   
                ans=mid;
                e=mid-1;
            }
            else
            {
                s=mid+1;
                
            }
            mid=s+(e-s)/2;
        }
        return ans;
        
    }
};
