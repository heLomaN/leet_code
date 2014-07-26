#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.first == b.first)
        return a.second <= b.second;
    else
        return a.first <= b.first;
}

vector<pair<int, int> > merge(vector<pair<int, int> > sec){
    vector<pair<int, int> > res;
    if (sec.size() < 1)
        return res;
    sort(sec.begin(), sec.end(), cmp);

    res.push_back(sec[0]);
    for (int i = 1; i < sec.size(); i++){
        if (sec[i].first <= res.back().second){
            if (sec[i].second > res.back().second)
                res.back().second = sec[i].second;
        }
        else
            res.push_back(sec[i]);
    }
    return res;
}

int main(){
    int n; cin >> n;
    vector<pair<int, int> > sec(n);
    for (auto& e : sec){
        int a,b;
        cin >> a >> b;
        e.first = a;
        e.second = b;
    }

    auto res = merge(sec);

    for (auto e : res)
        cout << '[' << e.first << " , " << e.second << endl;

    return 0;
}

