#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
    int ans = 1;
    int preIdx = 0;
    for(int i = 1; i<nums.size(); i++){
        if(nums[preIdx] != nums[i]){
            ans++;
            preIdx++;
            nums[preIdx] = nums[i];
        }
    }
    return ans;
}

int main() {
    int num[10] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> nums(num, num+10);
    int n = removeDuplicates(nums);
    cout<<n<<endl;
    for(int i =0; i < n; i++) {
        cout<<nums[i]<<" ";
    }
    return 0;
}