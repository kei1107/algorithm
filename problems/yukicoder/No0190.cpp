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

/*
 <url:https://yukicoder.me/problems/no/190>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 WetとDryについては尺取り法を用いて
 ある値に対して、その値よりも絶対値が小さくかつ最大の符号が逆の物を貪欲に取っていけば良い
 
 また、Moistについても同様のことができるが、
 Moistはmap使って単純に値を数えた方が楽なので自分はこっちにした
 ================================================================
 */
vector<ll> solve(){
    vector<ll> res;
    ll N; cin >> N;
    vector<ll> A(2*N); for(auto& in:A) cin >> in;
    // Dry
    {
        ll Wet = 0;
        sort(A.begin(),A.end());
        ll l = 0,r = 2*N-1;
        while(l<r){
            while(l < r && A[l]+A[r]>=0) r--;
            if(l < r && A[l]+A[r]<0)Wet++;
            l++; r--;
        }
        res.push_back(Wet);
    }
    // Wet
    {
        ll Dry = 0;
        sort(A.rbegin(),A.rend());
        ll l = 0,r = 2*N-1;
        while(l<r){
            while(l < r && A[l]+A[r]<=0) r--;
            if(l < r && A[l]+A[r]>0)Dry++;
            l++; r--;
        }
        res.push_back(Dry);
    }
    // Moist
    {
        ll Moist = 0;
        sort(A.begin(),A.end());
        ll l = 0,r = 2*N-1;
        map<ll,ll> mp;
        for(auto a:A) mp[a]++;
        set<ll> s(A.begin(),A.end());
        for(auto a:s){
            Moist += min(mp[a],mp[-a]);
        }
        Moist/=2;
        res.push_back(Moist);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
