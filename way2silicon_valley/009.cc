#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool all_pair(vector<int>& num, int k){
    if (num.size() & 1 > 0)
        return false;

    unordered_map<int, int> imap;
    for (auto& e : num){
        int t = e % k;
        if (imap.count(t) == 0)
            imap[t] = 1;
        else
            imap[t] += 1;
    }

    if (imap.count(0)  && imap[0] & 1 > 0)
        return false;
    if ((k & 1) > 0 && imap.count(k / 2) & 1 > 0)
        return false;
    for (auto& e :imap){
        if (e.first == 0)
            continue;

        if (imap.count(k - e.first) && imap[k - e.first] == imap[e.first])
            ;
        else
            return false;
    }

    return true;

}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (auto& e : num)
        cin >> e;

    cout << all_pair(num, k) << endl;

    return 0;
}




