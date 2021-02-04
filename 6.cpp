#include<iostream>
using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1)
        return s;
    string* rows = new string[numRows];
    int t = 2*numRows - 2;
    for(int i=0; i<s.size(); i++){
        if(i % t < numRows){
            rows[i%t] += s[i];
        }else{
            rows[t - i%t] += s[i];
        }
    }
    string ans;
    for(int i=0; i<numRows; i++)
        ans+= rows[i];
    return ans;
}

int main(){
    string s = "PAYPALISHIRING";
    int numRows = 4;
    cout<<convert(s, numRows)<<endl;
    return 0;
}