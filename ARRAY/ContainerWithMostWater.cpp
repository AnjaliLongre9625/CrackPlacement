#include <bits/stdc++.h>
using namespace std;
int maxArea(vector<int> &height){
    int n = height.size();
    int i = 0, j = n - 1;
    int maxWater = 0;

    while (i < j){

        int width=j-i;
        int currheight=min(height[i],height[j]);
        int area=width*currheight;
        maxWater=max(maxWater,area);

        if(height[i]<height[j]){
            i++;
        }
        else {
            j--;
        }
    }
    return maxWater;
}

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int ans = maxArea(height);
    cout << "Container With Most Water: " << ans << endl;
    return 0;
}