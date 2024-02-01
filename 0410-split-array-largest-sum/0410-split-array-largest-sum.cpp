class Solution {
public:
    bool isvalid(int mid,vector<int>&nums,int k)
    {
         int n=nums.size();
        int count=1;
        int time=mid;
        for(int i=0;i<n;i++)
        {
            if(count>k)
            {
                return 0;
            }
            if(nums[i]>mid) 
            {
                return 0;
            }
            time-=nums[i];

            if(time<0)
            {
                count++;
                time=mid-nums[i];
            }
        }
        return count<=k;
    }
    int splitArray(vector<int>& nums, int k) 
    {        
        int low=0;
        int high=1e9;
        int ans=1e9;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isvalid(mid,nums,k))
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }    
        }
        return ans;
        
    }
};