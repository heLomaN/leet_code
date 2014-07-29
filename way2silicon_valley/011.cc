#include<unordered_set>
#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

int exclu_num(vector<int>& num, int min, int max){
    unordered_set<int> nset(num.begin(), num.end());
    srand(time(NULL));
    int rst = rand() % (max - min) + min;
    while (nset.count(rst) != 0 )
        rst = rand() % (max - min) + min;
    return rst;
}

int main(){
    int n, min, max;
    cin >> n >> min >> max;
    vector<int> num(n);
    for (auto& e: num)
        cin >> e;
    cout << exclu_num(num, min, max) << endl;

    return 0;
}

