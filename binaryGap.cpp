// Online C++ compiler to run C++ program online
#include <iostream>

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
