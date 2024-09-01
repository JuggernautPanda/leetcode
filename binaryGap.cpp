// Online C++ compiler to run C++ program online
#include <iostream>
/*
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].
    */
class Solution{
    private: 
    int bG = 0;
    int bG_max = 0;
    public: 
    int binGap(int N)
    {
        int arr[32] = {0};
        int n_size = 32;
        int temp = N;
        int i = 0;
        int hash[n_size] = {0};
        int one_found_start = false;
        std::cout<<"Number = "<<N<<"\n binary=";
        for(i=0;i<n_size;i++)
        {
            if(temp%2==0) arr[i] = 0;
            else arr[i] = 1;
            temp /= 2; // convert to bin
            //std::cout<<temp<<"\t";
            if(temp==0) break;
        }
        
        for(i=n_size-1;i>=0;i--)
        {
            std::cout<<arr[i]<<" ";
        }
        
        for(i=n_size-1;i>=0;i--)
        {
            if((arr[i]==1) && (one_found_start == false))
            {
                one_found_start = true;
                std::cout<<"found start at"<<i<<"\t";
            }
            else if(one_found_start == true)
            {
                if(arr[i] == 1) 
                {
                    std::cout<<"found end at"<<i<<"\t";
                    //one_found_start = false;
                    if(bG > bG_max ) bG_max = bG; 
                    bG = 0; // reset
                }
                else bG++;
            }
        }
        std::cout<<"bG_max = "<<bG_max<<"\n";
        return bG_max;
    }
    
};

int main() {
    Solution *sol = new Solution();
    
    sol->binGap(1610612737);

    return 0;
}
