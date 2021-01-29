#include<iostream>
#include<unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int ans = 0;
    int rgtW = -1;
    for(int i=0; i<s.size(); i++){
        if(i != 0){
            set.erase(s[i-1]);
        }
        while(rgtW + 1 < s.size() && set.count(s[rgtW+1]) == 0){
            rgtW++;
            set.insert(s[rgtW]);
        }
        ans = ans > (rgtW - i + 1) ? ans : (rgtW - i + 1);
    }
    return ans;
}

int main() {
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s);
    return 0;
}