// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
class Solution {
public:
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
int main() {
    // Write C++ code here
    std::vector<int> ip = {2,2,11};
    int target = 13;
    Solution *sol = new Solution();
    std::vector<int> op = sol->twoSum(ip,target);
    
    std::cout<< op[0] << " & " << op[1] <<std::endl;

    return 0;
}
