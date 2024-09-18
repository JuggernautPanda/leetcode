// Online C++ compiler to run C++ program online
/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
  */
#include <iostream>
#include <vector>
#include<algorithm>
class Solution {


    
public:
  
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        //std::cout<<"m = "<<m<<" n = "<<n<<"\n";
        if(m==0)
        {
           nums1 = nums2; 
        }
        else if(n==0)
        {
            // do nothing.
        }
        else
        {
        for(i=m;i<m+n;i++,j++)
        {
            nums1[i] = nums1[i] + nums2[j];
        }
        std::sort(nums1.begin(), nums1.end()); 
        }
        
    }
};
int main() {
    //std::vector<int> nums1 = {4,0,0,0,0,0};
    std::vector<int> nums1 = {1,2,3,0,0,0};
    //std::vector<int> nums1 = {1};
    //std::vector<int> nums1;
   int m = 3;
    std::vector<int> nums2 = {2,5,6};
    //std::vector<int> nums2;
    //std::vector<int> nums2 = {2};
int n = 3;
    Solution *sol = new Solution();
    int i = 0;
    std::cout<<"Output"<<"\n";
    
    sol->merge(nums1,m,nums2,n);
    
    for(i=0;i<m+n;i++)
    {
        std::cout<<nums1[i]<<"\t";
    }

    return 0;
}
