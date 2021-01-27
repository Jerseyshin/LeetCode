#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//Brute Force:
vector<int> twoSum(vector<int>& nums, int target){
    vector<int> ans;
    for(int i=0; i<nums.size(); i++){
        for(int j = i+1; j<nums.size(); j++){
            if(nums[i]+nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
    }
    return ans;
}

//Hash Table:
vector<int> twoSum_ht(vector<int>& nums, int target){
    unordered_map<int, int> hash;
    for(int i=0; i<nums.size(); i++){
        auto it = hash.find(target - nums[i]);
        if(it != hash.end()){
            return {it->second, i};
        }
        hash[nums[i]] = i;
    }
    return {};
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
    vector<int> ans = twoSum(nums, target);
    vector<int> :: iterator iter = ans.begin();
    for(;iter!=ans.end();iter++){
        cout<<*iter<<endl;
    }
    return 0;
}
