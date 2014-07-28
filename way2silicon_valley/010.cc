#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool near_rcs(vector<int>& a, vector<int>& b, vector<int>& flag, vector<int>& res){
    int i = 0;
    while (k


int near(vector<int>& a, vector<int>& b){
    sort(a.begin(), a.end());
    vector<int> res;
    vector<bool> not_used(a.size(), true);
    near_rcs(a, b, not_used, res);
    int t = 0;
    for (auto e : res)
        t = t * 10 + e;
    return t;
}


int main(){
    int k;
    cin >> k;
    vector<int> a(k), b(k);
    for (auto& e : a)
        cin >> e;
    for (auto& e : b)
        cin >> b;

    cout << near(a, b) << endl;

    return 0;
}

