#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<functional> // greater?

using namespace std;

int topkii(vector<int>& num, int k){
    //sort(num.begin(), num.end(), greater<int>);
    int p = 0, q = num.size() - 1;
    int mid = partition(num.begin() + p, num.begin() + q, bind2nd(greater<int>(), num[(p + q) >> 1])) - num.begin();
    int sum = 0;
    for (int i = 0; i <= mid; i++)
        sum += num[i];

    while (sum != k){
        if (sum < k){
            p = mid + 1;
            k -= sum;
            mid = partition(num.begin() + p, num.begin() + q, bind2nd(greater<int>(), num[(p + q) >> 1])) - num.begin();
            sum = 0;
            for (int i = p; i <= mid; i++)
                sum += num[i];
        }
        else{
            q = mid - 1;
            mid = partition(num.begin() + p, num.begin() + q, bind2nd(greater<int>(), num[(p + q) >> 1])) - num.begin();
            sum = 0;
            for (int i = p; i <= mid; i++)
                sum += num[i];
        }
    }

    if (sum == k)
        return mid;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (auto& e : num)
        cin >> e;

    cout << topkii(num, k) + 1 << endl;

    return 0;
}


