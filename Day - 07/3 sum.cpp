#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
    vector<vector<int>> result;
    sort(arr.begin() , arr.end());
    
    if(n<3) return result;
    
    for(int i = 0; i<n; i++)
    {
        int low = i+1 ;
        int high = n-1; 
        int sum = K - arr[i];
        
        while(low<high)
        {
            if(arr[low]+arr[high] == sum)
            {
                result.push_back({arr[i], arr[low], arr[high]});
                //skipping same elements
                while(low<high && arr[low]==arr[low+1])
                    low++;
                while(low<high && arr[high]==arr[high-1])
                    high--;
                low++;
                high--;
            }
            else if(arr[low]+arr[high] < sum)
                low++;
            else
                high--;
        }
        //skipping same ith element
        while(i+1<n && arr[i]==arr[i+1])
            i++;
    }
    return result;
}

class Solution {
public:
     vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        if(n<3) return result;

        for(int i=0 ; i<n-2 ; ++i) {
            if(i==0 || nums[i]!=nums[i-1]) {
                int low = i+1;
                int high = n-1;
                int sum = 0 - nums[i];

                while(low < high) {
                    if((nums[low] + nums[high]) == sum) {
                        result.push_back({nums[i],nums[low],nums[high]});
                        //skipping same elements
                        while(low<high && nums[low]==nums[low+1]) 
                            low++;
                        while(low<high && nums[high]==nums[high-1]) 
                            high--;
                        low++;
                        high--;
                    }
                    else if((nums[low] + nums[high]) > sum)
                        high--;
                    else 
                        low++;
                }
            }
        }
    return result;
    }
};

