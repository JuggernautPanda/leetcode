// Online C++ compiler to run C++ program online
/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
class Solution{
  private:
  int maxp = 0;
  std::unordered_map<float, int> umap;
  std::vector<std::vector<int>> umap2; // vector of all. later find unique points.
  float slope = 0;
  bool slope_valid = false;
  public:
  int maxPoints(std::vector<std::vector<int>>& points) {
        int numP = points.size();
        int i = 0;
        int j = 0;
        std::vector<int> a = {0,0};
        std::vector<int> b = {0,0};
        std::cout<<"Num of points = " << numP << std::endl;
        
        for(i=0;i<numP-1;i++)
        {
            a = points[i];
            std::cout<<"i = " << i << std::endl;
            for(j=i+1;j<numP;j++)
            {
                b = points[j];
                 std::cout<<"a = ["<< a[0] <<" , " << a[1] <<"] \t";
                 std::cout<<"b = ["<< b[0] <<" , " << b[1] <<"] \t";
                if((a[0]==b[0])&&(a[1]==b[1])) 
                {
                    slope_valid = false;
                    std::cout<<"Slope = "<<slope<<"\n";
                }
                else
                {
                if(b[0]-a[0] != 0) // avoid divide by zero
                {
                    slope = float(float(b[1]-a[1])/float(b[0]-a[0]));
                    std::cout<<"Slope = "<<slope<<"\n";
                    slope_valid = true;
                    
                }
                else 
                {
                    slope_valid = false;
                   std::cout<<"special set  "<<"\n";
                }
                
                }

              if(slope_valid == true)
              {
                  //handle the map
                  auto it = umap.find(slope);
                  if (it != umap.end()) {
        // Key found, access the corresponding value
       //std::cout << "Slope " << slope << " with value " << it->second << "\n";
        umap[slope] = it->second + 1;
        umap2.push_back(a);
        umap2.push_back(b);
        
      
  
    } else {
        // Key not found
       //std::cout << "Slope " << slope << " not found in the map. Add it to map\n";
        umap.insert(std::make_pair(slope, 1));
        umap2.push_back(a);
        umap2.push_back(b);
    }
              }
              else
              {
                 // std::cout<<"Slope = 0"<<std::endl;
              }
              
            }
        }
        for (const auto& pair : umap) {
        if (pair.second > maxp) {
            maxp = pair.second;
            slope = pair.first; // Keep track of the key for the max value
        }
    }
    
        std::cout<<"max slope" << slope << std::endl;
        std::cout<<"max points" << maxp << std::endl;
        numP = umap2.size();
        std::cout<<"size of umap2" << std::endl;
        /*for(i=0;i<numP-1;i++)
        {
            a = points[i];
            std::cout<<"i = " << i << std::endl;
            for(j=i+1;j<numP;j++)
            {
                b = points[j];
                 std::cout<<"a = ["<< a[0] <<" , " << a[1] <<"] \t";
                 std::cout<<"b = ["<< b[0] <<" , " << b[1] <<"] \t";
            }
        }*/
        return maxp;
    }
};
int main() {
    // Write C++ code here
    //std::vector<std::vector<int>> p = {{1,1},{2,2},{3,3}};
    std::vector<std::vector<int>> p = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    Solution *sol = new Solution();
    sol->maxPoints(p);

    return 0;
}
