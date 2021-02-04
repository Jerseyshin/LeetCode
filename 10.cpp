#include<iostream>
using namespace std;
//dp mn mn
bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    bool **dp = new bool*[n + 1];
    for(int i=0; i<n + 1; i++){
        dp[i] = new bool[m + 1];
        for(int j=0; j<m+1; j++)
            dp[i][j] = false;
    }
    //base case: 0=>empty
    dp[0][0] = true;
    for(int j = 1; j < m+1; j++){
        if(p[j-1] == '*')
            dp[0][j] = dp[0][j-2];
        //else dp[0][j] = false;
    }
    //iteration:
    for(int i=1; i < n+1; i++){
        for(int j=1; j < m+1; j++){
            if(s[i-1] == p[j-1] || p[j-1] == '.')
                dp[i][j] = dp[i-1][j-1];
            else{
                if(p[j-1] == '*' && j-2>=0){
                    if(p[j-2] == s[i-1] || p[j-2] == '.'){
                        dp[i][j] = dp[i][j-2] || dp[i-1][j-2] || dp[i-1][j];
                    }else{
                        dp[i][j] = dp[i][j-2];
                    }
                }else{
                    dp[i][j] = false;
                }
            }
        }
    }
    return dp[n][m];
}

//dp mn 2n
bool isMatch_better(string s, string p) {
    int n = s.size();
    int m = p.size();
    bool **dp = new bool*[2];
    for(int i=0; i<2; i++){
        dp[i] = new bool[m + 1];
        for(int j=0; j<m+1; j++)
            dp[i][j] = false;
    }

    //base case: 0=>empty
    dp[0][0] = true;
    for(int j = 1; j < m+1; j++){
        if(p[j-1] == '*')
            dp[0][j] = dp[0][j-2];
        //else dp[0][j] = false;
    }
    //iteration:
    for(int i=1; i < n+1; i++){
        dp[i&1][0] = false;
        for(int j=1; j < m+1; j++){
            if(s[i-1] == p[j-1] || p[j-1] == '.')
                dp[i&1][j] = dp[(i-1)&1][j-1];
            else{
                if(p[j-1] == '*' && j-2>=0){
                    if(p[j-2] == s[i-1] || p[j-2] == '.'){
                        dp[i&1][j] = dp[i&1][j-2] || dp[(i-1)&1][j-2] || dp[(i-1)&1][j];
                    }else{
                        dp[i&1][j] = dp[i&1][j-2];
                    }
                }else{
                    dp[i&1][j] = false;
                }
            }
        }
    }
    return dp[n&1][m];
}

int main() {
    string s;
    string p;
    cin>>s;
    cin>>p;
    cout<<isMatch_better(s,p)<<endl;
    return 0;
}