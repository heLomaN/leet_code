#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class sumK{
    unordered_map<int, int> intmap;
    public:
    sumK(){};
    ~sumK(){};
    void Save(int in){
        if (intmap.count(in) == 0)
            intmap[in] = 1;
        else
            intmap[in] += 1;
    }
    bool Test(int in){
        for (auto e : intmap)
            if (intmap.count(in - e.first) > 0)
                if (e.first * 2 != in || e.second >= 2)
                    return true;
        return false;
    }

};

int main(){
    sumK sumk;
    int k;
    char s;
    while (cin >> s >> k, k){
        if (s == 's' )
            sumk.Save(k);
        else if (s == 't')
            cout << sumk.Test(k) << endl;
    }

    return 0;
}

