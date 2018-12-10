#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/404>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 難しい
 
 >> http://kmjp.hatenablog.jp/entry/2016/07/23/0930
 ================================================================
 */

struct BIT {
    ll N;
    vector<ll> bit;
    BIT(ll N):N(N) {
        /* BITは[1..N]で扱う */
        bit.resize(N + 1, 0);
    }
    
    void add(int x, ll val){
        while (x <= N) {
            bit[x] += val;
            x += x & -x;
        }
    }
    
    ll sum(int x){
        ll ret = 0;
        while (x) {
            ret += bit[x];
            x &= (x - 1);
        }
        return (ret);
    }
};

bool isKadomatsu(int a,int b,int c){
    if(a == b || b == c || c == a) return false;
    if(b > a && b > c) return true;
    if(b < a && b < c) return true;
    return false;
}
void solve(){
    int N; cin >> N;
    
    vector<int> compv;
    vector<int> a(N);
    for(auto& in:a){
        cin >> in;
        compv.push_back(in);
    }
    int Q; cin >> Q;
    vector<int> L(Q),H(Q);
    for(int i = 0; i < Q;i++){
        cin >> L[i] >> H[i];
        compv.push_back(L[i]);
        compv.push_back(H[i]);
    }
    
    compv.push_back(0); compv.push_back(INF);
    sort(compv.begin(),compv.end());
    compv.erase(unique(compv.begin(),compv.end()),compv.end());
    for(auto &v:a) v = (int)(lower_bound(compv.begin(), compv.end(), v) - compv.begin());
    for(auto &v:L) v = (int)(lower_bound(compv.begin(), compv.end(), v) - compv.begin());
    for(auto &v:H) v = (int)(lower_bound(compv.begin(), compv.end(), v) - compv.begin());
    
    BIT bitL(compv.size()), bitR(compv.size()),F(compv.size());
    vector<ll> LU(N),LD(N),RU(N),RD(N);
    for(int i = 0; i < N;i++){
        LU[i] = bitL.sum((int)compv.size()) - bitL.sum(a[i]);
        LD[i] = bitL.sum(a[i]-1);
        bitL.add(a[i],1);
    }
    
    for(int i = N-1; i >= 0; i--){
        RU[i] = bitR.sum((int)compv.size()) - bitR.sum(a[i]);
        RD[i] = bitR.sum(a[i]-1);
        bitR.add(a[i],1);
    }
    for(int i = 0; i < N;i++) F.add(a[i],LU[i]*RU[i]+LD[i]*RD[i]);
    map<ll,ll> sL,sR;
    for(int i = 0; i < N;i++) sR[a[i]]++;
    ll same = 0;
    for(int i = 0; i < N;i++){
        same -= sL[a[i]]*sR[a[i]];
        F.add(a[i],-same);
        sR[a[i]]--;
        sL[a[i]]++;
        same += sL[a[i]]*sR[a[i]];
    }
    
    for(int i = 0; i < Q;i++){
        cout << F.sum(H[i]) - F.sum(L[i]-1) << endl;
    }
    
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
