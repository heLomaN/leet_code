#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Itv{
    public:
    int start;
    int end;
    void set(int a, int b){
        start = a;
        end = b;
    }
};
struct point{
    int pos;
    int flag;
};

bool cmp(point a, point b){
    if (a.pos == b.pos)
        return a.flag > b.flag;
    else
        return a.pos < b.pos;
}

int overlap_cnt(vector<Itv>& sec){
    vector<point> pin_ary(sec.size() * 2);
    for (int i = 0; i < sec.size(); i++){
        pin_ary[2 * i].pos = sec[i].start;
        pin_ary[2 * i].flag = 1;
        pin_ary[2 * i + 1].pos = sec[i].end;
        pin_ary[2 * i + 1].flag = -1;
    }
    sort(pin_ary.begin(), pin_ary.end(), cmp);

    int cnt = 0, max = 0;
    for (int i = 0; i < pin_ary.size(); i++){
        cnt += pin_ary[i].flag;
        if (cnt > max)
            max = cnt;
    }

    return max;
}


int main(){
    int n;
    cin >> n;
    vector<Itv> sec(n);
    for (auto& e : sec){
        int a, b;
        cin >> a >> b;
        e.set(a,b);
    }
    cout << overlap_cnt(sec) << endl;
    return 0;
}


