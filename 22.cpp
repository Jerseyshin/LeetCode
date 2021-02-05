#include<iostream>
#include<vector>
using namespace std;

void backtrack(int psum, int nsum, int idx, const int n, vector<string>& pars, string par){
    if(idx == 2*n)
        pars.push_back(par);
    else{
        par.push_back('(');
        if(psum + 1 <= n){
            backtrack(psum+1, nsum, idx+1, n, pars, par);
        }
        par.pop_back();
        par.push_back(')');
        if(psum - nsum -1 >= 0){
            backtrack(psum, nsum+1, idx+1, n, pars, par);
        }
        par.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> pars;
    string par;
    backtrack(0, 0, 0, n, pars, par);
    return pars;
}

int main() {
    int n;
    cin>>n;
    vector<string> v = generateParenthesis(n);
    for(vector<string>::iterator it = v.begin(); it<v.end(); it++)
        cout<<*it<<"  ";
    return 0;
}