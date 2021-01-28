#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//n^2
vector< vector<int> > threeSum(vector<int> &nums){
    vector< vector<int> > ans;
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++){
        if(i > 0 && nums[i] == nums[i-1])   continue;
        int j = i+1;
        int k = nums.size() - 1;
        while(j<k){
            int target = nums[i] + nums[j] + nums[k];
            if(target < 0){
                j++;
                while(j<nums.size() && nums[j]==nums[j-1])
                    j++;
            }
            else if(target > 0){ 
                k--;
                while(k>i && nums[k] == nums[k+1])
                    k--;
            }
            else{
                vector<int> tmp;
                tmp.push_back(nums[i]);
                tmp.push_back(nums[j]);
                tmp.push_back(nums[k]);
                ans.push_back(tmp);
                j++; k--;
                while(j<nums.size()-1 && nums[j]==nums[j-1])
                    j++;
                while(k>i && nums[k] == nums[k+1])
                    k--;
            }
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
    cout<<"finish input"<<endl;
    vector< vector<int> > ans = threeSum(nums);
    for(int i = 0; i < ans.size(); i++){
        vector<int>::iterator iter = ans[i].begin();
        for(; iter!=ans[i].end(); iter++){
            cout<< *iter<<" ";
        }
        cout<<endl;
    }
    return 0;
}