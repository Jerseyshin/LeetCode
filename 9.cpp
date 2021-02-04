#include<iostream>
using namespace std;

//number
bool isPalindrome(int x) {
    if(x < 0)
        return false;
    long long x_ = x;
    long long ans = 0;
    while(x_ != 0){
        ans = ans * 10 + x_%10;
        x_ = x_/10;
    }
    if(ans == x)
        return true;
    return false;
}
//string
bool isPalindrome_2(int x) {
    string s = to_string(x);
    for(int i=0; i<s.size(); i++){
        int j = s.size() - 1 - i;
        if(s[i] != s[j])
            return false;
        if(i >= j)
            break;
    }
    return true;
}

int main(){
    int x;
    cin>>x;
    cout<<isPalindrome_2(x);
    return 0;
}