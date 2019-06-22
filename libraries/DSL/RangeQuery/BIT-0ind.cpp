#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

template<typename type>
struct BIT0 { // 0-index
    int N;
    int nn;
    vector<type> data;
    //動的はmap<int?,type>data
    BIT0(int n) {
        N = n + 1;
        data = vector<type>(n + 1, 0);
        nn = 1;
        while (nn * 2 <= N)nn *= 2;
    }
    void add(int i, type w) { // a[i] += w
        i++;
        for (int x = i; x < N; x += x & -x) {
            data[x] += w;
        }
    }
    type sum(int i) { // iまでの和 [0,i)
        type ret = 0;
        for (int x = i; x > 0; x -= x & -x) {
            ret += data[x];
        }
        return ret;
    }
    // [l, r)
    type sum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    /*    BIT 上で二分探索
     二分木の分かれ方に従って二分探索する
     左の子に進むか右の子に進むかを知るためには，左の子の範囲の和がわかればよい
     ちょうど BIT がもっている情報，O(1) 時間で得られる
     a[1] + a[2] + a[3] + ... a[x] >= w となる最小のxを返す、ただしa[i] >= 0    */
    
    int lower_bound(type w) {//  w≦[0,x]以上となる最小のindex,x
        if (w <= 0) return 0;
        int x = 0;
        for (int k = nn; k > 0; k /= 2) {
            if (x + k < N && data[x + k] < w) {
                w -= data[x + k];
                x += k;
            }
        }
        return x;
    }
};
