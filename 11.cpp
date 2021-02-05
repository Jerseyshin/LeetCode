#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
    int ans = 0;
    int l = 0;
    int r = height.size() - 1;
    while(l < r){
        int h = (height[l] < height[r]) ? height[l] : height[r];
        int S = h * (r - l);
        ans = (ans < S) ? S : ans;
        if(height[l] < height[r])
            l++;
        else
            r--;
    }
    return ans;
}

int main() {
    int h[9] = {1,8,6,2,5,4,8,3,7};
    vector<int> height(h, h+9);
    cout<<maxArea(height);
    return 0;
}