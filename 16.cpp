#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int> &nums, int target){
    sort(nums.begin(), nums.end());
    int ans = 0x7ffffff;
    for(int i=0; i<nums.size(); i++){
        int j = i + 1;
        int k = nums.size() - 1;
        while(j < k){
            int add = nums[i] + nums[j] + nums[k];
            if(add < target){
                j++;
                while(j < nums.size() && nums[j-1] == nums[j])
                    j++;
            }else if(add > target){
                k--;
                while(k > i && nums[k+1] == nums[k])
                    k--;
            }else{
                ans = add;
                return ans;
            }
            if(abs(ans - target) > abs(add - target))
                ans = add;
        }
    }
    return ans;
}

int main(){
    int n;
    int tmp;
    vector<int> nums;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>tmp;
        nums.push_back(tmp);
    }
    int target;
    cin>>target;
    cout<<"finish input"<<endl;
    cout<<threeSumClosest(nums, target);
    return 0;
}