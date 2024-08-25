// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <unordered_map>


class Solution {
public:
std::vector<int> twoSumO1(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_map; // value -> index

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            // Check if the complement exists in the map
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }

            // Add the current number to the map
            num_map[nums[i]] = i;
        }

        return {}; // return an empty vector if no solution is found, though the problem guarantees one solution
    }
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int i = 0;
        int j = 0;
        std::vector<int> sum = {0,0};
        int k = nums.size(); 
       // std::cout<< k << ":size of vector"<<std::endl;
        for(i=0;i<=k;i++)
        {
            for (j = i+1; j<k;j++)
            {
           // std::cout<<nums[i] << " " <<nums[j] <<std::endl;
            if(target == nums[i]+nums[j])
            {
                sum[0] = i;
                sum[1] = j;
                //std::cout<<"found"<<std::endl;

                return sum;
            }
            }
        }
        return sum;
    }
};
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/
int main() {
    // Write C++ code here
    std::vector<int> ip = {2,2,11};
    int target = 13;
    Solution *sol = new Solution();
    std::vector<int> op = sol->twoSum(ip,target);
    
    std::cout<< op[0] << " & " << op[1] <<std::endl;

    return 0;
}
