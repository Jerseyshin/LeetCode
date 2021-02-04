#include <iostream>
#include <vector>
using namespace std;

//dp : n2 n2
string longestPalindrome(string s){
    int n = s.size();
    string ans;
    vector<vector<int> > dp(n, vector<int>(n));
    for (int len = 0; len < n; len++){
        for (int i = 0; i + len < n; i++){
            int j = i + len;
            if (len == 0){
                dp[i][j] = 1;
            }else if (len == 1){
                dp[i][j] = (s[i] == s[j]);
            }else{
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
            if (dp[i][j] && len + 1 > ans.size())
                ans = s.substr(i, len + 1);
        }
    }
    return ans;
}

//expandAroundCenter n2 1
string longestPalindrome_eac(string s){
    int start = 0, end = 0;
    int n = s.size();
    for (int i = 0; i < n; i++){
        //base1 : i -> oddLine
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]){
            l--; r++;
        }
        l++; r--;
        if (r - l + 1 > end - start + 1){
            start = l;
            end = r;
        }
        //base2 : i i+1 -> evenLine
        l = i;
        r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]){
            l--;
            r++;
        }
        l++;r--;
        if (r - l + 1 > end - start + 1){
            start = l;
            end = r;
        }
    }
    return s.substr(start, end - start + 1);
}

//Manacher n n
string manacherInit(string s) {
    string t = "#";
    for(char c : s){
        t = t + c + "#";
    }
    return t;
}
int expandArmFromCenter(string s, int l, int r){
    while(l >= 0 && r < s.size() && s[l] == s[r]){
        l--; r++;
    }
    l++; r--;
    return (r - l) / 2;
}
string longestPalindrome_manacher(string s) {
    s = manacherInit(s);
    vector<int> arm_len;
    //core: 最远臂长的核心  rgt: 右臂所在处
    int start = 0, end = 0;
    int ctr = -1;
    int rgt = -1;
    for(int i=0; i<s.size(); i++){
        int cur_arm_len = 0;
        if(i > rgt){
            cur_arm_len = expandArmFromCenter(s, i, i);
        }else{
            int sym_i = 2*ctr - i;
            int sym_arm_len = arm_len[sym_i];
            int init_arm_len = (sym_arm_len < rgt - i) ? sym_arm_len : rgt - i;
            cur_arm_len = expandArmFromCenter(s, i - init_arm_len , i + init_arm_len);
        }
        arm_len.push_back(cur_arm_len);
        //cout<<s[i]<<cur_arm_len<<endl;
        if(cur_arm_len*2 + 1 > end - start){
            start = i - cur_arm_len;
            end = i + cur_arm_len;
        }
        if(i + cur_arm_len > rgt){
            ctr = i;
            rgt = i + cur_arm_len;
        }
        if(rgt == s.size())
            break;
    }

    //cout<<start<<" "<<end<<endl;
    string ans;
    for(int i = start; i<=end; i++){
        if(s[i] != '#')
            ans += s[i];
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout<<manacherInit(s)<<endl;
    cout << longestPalindrome_manacher(s) << endl;
    return 0;
}