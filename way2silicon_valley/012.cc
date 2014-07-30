#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<int> ivec;

void swap(ivec::iterator p, ivec::iterator q){
    int tmp = *p;
    *p =  *q;
    *q = tmp;
}

int three_partition(ivec& num, int p, int mid, int q){
    if (num[p] < num[mid])
        swap(num.begin() + p, num.begin() + mid);
    if (num[p] < num[q])
        swap(num.begin() + p, num.begin() + q);
    if (num[mid] < num[q])
        swap(num.begin() + mid, num.begin() + q);
    return mid;
}
        
    

int partition(ivec& num, int p, int q){
    if (p >= q)
        return p;

    if (p + 10 > q){
        sort(num.begin() + p, num.begin() + q + 1);
        return p;
    }

    int pivot_idx = three_partition(num, p, (p + q) >> 1, q);

    swap(num.begin() + pivot_idx, num.begin() + q);

    int pivot = num[q];

    int i = p, j = q - 1;
    while ( i < j){
        while (num[i] < pivot && i < q)
            ++i;
        while (num[j] >= pivot && j >= p)
            --j;

        if (i < j)
            swap(num.begin() + i, num.begin() + j);
    }
    swap(num.begin() + i, num.begin() + q);
    return i;
}

void topk(ivec& num, int k){
    int p = partition(num, 0, num.size() - 1);
    int left = 0, right  = num.size() - 1;
    while (p != k-1){
        if (p > k-1){
            right = p - 1;
            p = partition(num, left, right);
        }
        else{
            left = p + 1;
            p = partition(num, left, right);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    ivec num(n);
    for (auto& e : num)
        cin >> e;

    //topk(num, k);
    partial_sort(num.begin(), num.begin() + k, num.end());

    for (int i  = 0; i < k; i++)
        cout << num[i] << endl;
    cout << endl;

    return 0;
}

