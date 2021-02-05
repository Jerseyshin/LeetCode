#include<iostream>
using namespace std;

string intToRoman(int num) {
    string ans;
    //thousand:
    int m = num / 1000;
    num = num % 1000;
    for(int i = 0; i < m; i++){
        ans += "M";
    }
    //>5 hundred:
    if(num >= 900){
        num = num - 900;
        ans += "CM";
    }else if(num >= 500){
        num = num - 500;
        ans += "D";
    }
    //<5 hundred:
    if(num >= 400){
        num = num - 400;
        ans += "CD";
    }else{
        int h = num / 100;
        num = num % 100;
        for(int i = 0; i < h; i++){
            ans += 'C';
        }
    }
    //>50
    if(num >= 90){
        num = num - 90;
        ans += "XC";
    }else if(num >= 50){
        num = num - 50;
        ans += "L";
    }
    //<50
    if(num >= 40){
        num = num - 40;
        ans += "XL";
    }else{
        int t = num / 10;
        num = num % 10;
        for(int i =0; i < t; i++){
            ans += 'X';
        }
    }
    //5-9
    if(num == 9){
        ans += "IX";
        num = 0;
    }
    else if(num >= 5){
        ans += "V";
        num = num - 5;
    }
    //1-4
    if(num == 4){
        ans += "IV";
        num = 0;
    }else{
        for(int i=0; i < num; i++){
            ans += "I";
        }
    }
    return ans;
}

int main()
{
    int num;
    cin>>num;
    cout<<intToRoman(num)<<endl;
    return 0;
}