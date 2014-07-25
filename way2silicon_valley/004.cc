#include<iostream>
#include<algorithm>

using namespace std;

void rotate( int* num, int k, int n){
    reverse(num, num + k);
    reverse(num + k, num + n);
    reverse(num, num + n);
}
int main(){
    int n = 5;
    int k; cin >> k;
    int num[5];
    for (int i = 0; i < n; i++){
        num[i] = i;
    }

    rotate(num, k, n);

    for (int i = 0; i < n; i++)
        cout << num[i] << ' ';
    cout << endl;

    return 0;
}

