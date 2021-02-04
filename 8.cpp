#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

//if-else
int myAtoi(string s) {
    int ans = 0;
    bool pre = true;
    bool valid = false;
    int sgn = 0;
    for(char c : s){
        if(pre){
            if(c == ' ')
                continue;
            else if(sgn == 0 && (c == '+' || c == '-')){
                sgn = (c=='+') ? 1 : -1;
                pre = !pre;
                continue;
            }
        }
        if(c >= '0' && c <= '9'){
            if(sgn == 0){
                sgn = 1;
                pre = !pre;
            }
            int tail = c - '0';
            tail = sgn*tail;
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && tail > 7))
                return INT_MAX;
            else if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && tail < -8))
                return INT_MIN;
            ans = ans * 10 + tail;
        }else
            break;
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<myAtoi(s)<<endl;
    return 0;
}