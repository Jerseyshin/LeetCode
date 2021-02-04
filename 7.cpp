#include<iostream>
#include<sstream>
using namespace std;

int reverse(int x) {
    int ans = 0;
    while(x!=0){
        int pop = x % 10;
        x = x / 10;
        if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && pop > 7))
            return 0;
        if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && pop < -8))
            return 0;
        ans = ans * 10 + pop;
    }
    return ans;
}

int main() {
    int x;
    cin>>x;
    cout<<reverse(x)<<endl;
    return 0;
}