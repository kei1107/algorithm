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
 <url:https://yukicoder.me/problems/no/270>
 問題文============================================================
 =================================================================
 解説=============================================================
 next_permutationhは後ろから見れば、
 20個ほどで10^5を超えるので、
 愚直にnext_permutationを実装しながら、差分を計算していけば高速で終わる
 ================================================================
 */


ll My_next_permutation(vector<ll>& p,vector<ll>& B,ll sum){
    if(p.size() == 1) return sum;
    ll i = p.size()-1;
    for(;;){
        ll ii = i; i--;
        if(p[i] < p[ii]){
            ll j = p.size();
            while(!(p[i] < p[--j]));
            
            sum -= abs(p[i] - B[i]);
            sum -= abs(p[j] - B[j]);
            swap(p[i],p[j]);
            sum += abs(p[i] - B[i]);
            sum += abs(p[j] - B[j]);
            
            for(ll k = ii; k < p.size();k++) sum -= abs(p[k] - B[k]);
            reverse(p.begin()+ii, p.end());
            for(ll k = ii; k < p.size();k++) sum += abs(p[k] - B[k]);
            return sum;
        }
        if(i == 0){
            for(ll k = 0; k < p.size();k++) sum -= abs(p[k] - B[k]);
            reverse(p.begin(), p.end());
            for(ll k = 0; k < p.size();k++) sum += abs(p[k] - B[k]);
            return sum;
        }
    }
    return sum;
}
ll solve(){
    ll res = 0;
    ll N,K; cin >> N >> K;
    if(K == 0) return res;
    vector<ll> p(N); for(auto& in:p) cin >> in;
    vector<ll> B(N); for(auto& in:B) cin >> in;
    ll sum = 0;
    for(int i = 0; i < N;i++) sum += abs(B[i]-p[i]);
    res += sum;
    for(int i = 1; i < K;i++){
        sum = My_next_permutation(p,B,sum);
        res += sum;
    }
    
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
