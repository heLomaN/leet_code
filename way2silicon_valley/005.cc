#include<iostream>
#include<vector>

using namespace std;

int max_distance(vector<int>& num){
    if (num.empty())
        return 0;
    vector<int> decent;
    int min = num[0];
    decent.push_back(0);
    for (int i = 0; i < num.size(); i++)
        if (num[i] < min){
            decent.push_back(i);
            min = num[i];
        }
    int dist = 0, i, j = num.size() - 1;
    for (int idx = decent.size() - 1; idx >= 0; idx--){
        i = decent[idx];
        while (j > i && num[j] <= num[i])
            --j;
        if ((j - i) > dist){
            dist = j - i;
            //j = i - 1;
        }
    }
    return dist;
}

int main(){
    int k;
    cin >> k;
    vector<int> num(k);
    for (auto& e : num)
        cin >> e;

    cout << max_distance(num) << endl;

    return 0;
}


