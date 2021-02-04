#include<iostream>
#include<vector>
#include<numeric>
#include<unordered_set>
using namespace std;

//Hash
vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    vector<int> ans;
    int sumA = accumulate(A.begin(), A.end(), 0);
    int sumB = accumulate(B.begin(), B.end(), 0);
    int b_a = (sumB - sumA) / 2;
    unordered_set<int> record(A.begin(), A.end());
    for(int i=0; i<B.size(); i++){
        if(record.count(B[i]-b_a)){
            ans.push_back(B[i]-b_a);
            ans.push_back(B[i]);
            return ans;
        }
    }
    return ans;
}

int main()
{
    vector<int> A;
    //.push_back(1);
    A.push_back(2);
    vector<int> B;
    B.push_back(1);
    B.push_back(3);
    vector<int> C = fairCandySwap(A, B);
    cout<<C[0]<<endl;
    cout<<C[1]<<endl;
    return 0;
}