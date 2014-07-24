#include<iostream>
#include<vector>
#include<unordered_map>
#include<ctime>
#include<cstdlib>
#include<utility>

using namespace std;

pair<int, int> sumk(vector<int>& num, int k){
    unordered_map<int, int> intmap;
    for (int i = 0; i < num.size(); i++){
        intmap[num[i]] = i;
    }

    for (int i = 0; i < num.size(); i++){
        if (intmap.count(k - num[i]) > 0)
            return pair<int, int> {i, intmap[k - num[i]]};
    }

    return make_pair(-1, -1);
}

int main(){
    int n = 5;
    int k = 10;
    vector<int> num(n);

    for (auto& e : num)
        cin >> e;

    pair<int, int> res = sumk(num, k);
    if (res.first  != -1)
        cout << res.first <<' ' << res.second << endl;

    return 0;

}
