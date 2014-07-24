#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

bool sumk(vector<int>& num, int k){
    int p = 0, q = num.size() - 1;
    while (p < q){
        int tmp = num[p] + num[q];
        if (tmp == k)
            return true;
        else if (tmp > k)
            --q;
        else
            ++p;
    }
    return false;
}

int main(){
    srand( time(NULL) );
    const int n = 200;
    int k = 500;
    vector<int> num(n, 0);
    for (auto& e : num)
        e = rand() % n;

    sort(num.begin(), num.end());
    cout << sumk(num, k) << endl;

    return 0;
}

