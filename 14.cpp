#include<iostream>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string ans;
    if(strs.size() == 0)
        return ans;
    if(strs.size() == 1)
        return strs[0];
    int j = 0;
    bool endFlag = false;
    while(j < strs[0].size() && !endFlag){
        for(int i = 1; i<strs.size(); i++){
            if(j >= strs[i].size() || strs[i][j] != strs[0][j]){
                endFlag = true;
                break;
            }
        }
        if(!endFlag)
            ans+=strs[0][j];
        j++;
    }
    return ans;
}


int main(){
    string st[3] = {"flower","flow","flight"};
    vector<string> strs(st, st+3);
    cout<<longestCommonPrefix(strs);
    return 0;
}