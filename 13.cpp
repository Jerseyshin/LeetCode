#include<iostream>
#include<unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<string, int> rom;
    rom["I"] = 1;
    rom["IV"] = 4;
    rom["V"] = 5;
    rom["IX"] = 9;
    rom["X"] = 10;
    rom["XL"] = 40;
    rom["L"] = 50;
    rom["XC"] = 90;
    rom["C"] = 100;
    rom["CD"] = 400;
    rom["D"] = 500;
    rom["CM"] = 900;
    rom["M"] = 1000;
    int ans = 0;
    for(int i=0; i<s.size(); i++){
        string s1 = s.substr(i, 1);
        if(i+1 < s.size()){
            string s2 = s.substr(i+1, 1);
            string s3 = s.substr(i, 2);
            if(rom[s1] < rom[s2]){
                i++;
                ans += rom[s3];
            }else
                ans += rom[s1];
        }else
            ans += rom[s1];
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;
    cout<<romanToInt(s)<<endl;
    return 0;
}