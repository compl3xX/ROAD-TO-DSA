bool isPossible(vector<int> &stalls, int k,int mid)
{
	int cowCount=1;
	int lastPst=stalls[0];
	for(int i=0;i<stalls.size();i++)
	{ 
		if(stalls[i]-lastPst>=mid) {
			cowCount++;
		
		if(cowCount==k)
		{
			return true;
		}
		lastPst=stalls[i];
		}
	}
	return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{  
	sort(stalls.begin(),stalls.end());
    int s=0;
	int e=stalls[stalls.size()-1];
	int ans=-1;
	int mid=s+(e-s)/2;
	while(s<=e)
	{
		if(isPossible(stalls,k,mid))
		{
			ans=mid;
			s=mid+1;
		}
		else
		{
			e=mid-1;
		}
	mid=s+(e-s)/2;
		
	}
 return ans;
}
