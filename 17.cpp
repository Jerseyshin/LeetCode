#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<char, string> table;

void tableInit(){
    table['2'] = "abc";
    table['3'] = "def";
    table['4'] = "ghi";
    table['5'] = "jkl";
    table['6'] = "mno";
    table['7'] = "pqrs";
    table['8'] = "tuv";
    table['9'] = "wxyz";
}

void backtrack(vector<string>& coms, const string& digits, int idx, string& com){
    if(idx == digits.size())
        coms.push_back(com);
    else {
        for(int i = 0; i < table[digits[idx]].size(); i++){
            com.push_back(table[digits[idx]][i]);
            backtrack(coms, digits, idx+1, com);
            com.pop_back();
        }
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> coms;
    if(digits.size() == 0)
        return coms;
    tableInit();
    string com;
    backtrack(coms, digits, 0, com);
    return coms;
}

int main(){
    string digits;
    cin>>digits;
    vector<string> v = letterCombinations(digits);
    for(vector<string>::iterator it = v.begin(); it < v.end(); it++){
        cout<<*it<<" ";
    }
    return 0;
}