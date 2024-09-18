#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
class Solution {
public:
    std::vector<int> grayCode(int n) {
        int r = std::pow(2,n);
        int i = 0;
        int state = 0;
        std::vector<int> gc;
       // std::cout<<r<<"\n";
        //auto print = [](const int& n) { std::cout << n << ' '; };
        for(i=0;i<r;i++)
        {
            gc.push_back(i ^ (i >> 1));
        }
         //std::for_each(gc.begin(), gc.end(), [](int &n) { n++; });
      /*  for(i=0;i<r;i++)
        {
            std::cout<< gc[i] <<"\t";
        }*/
        
        
        return gc;
    }
};

int main()
{
    Solution *sol = new Solution();
    std::vector<int> a = sol->grayCode(2);
    return 0;
}
