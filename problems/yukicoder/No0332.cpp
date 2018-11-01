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
 <url:https://yukicoder.me/problems/no/332>
 問題文============================================================
 =================================================================
 解説=============================================================
 
 制約が怪しくて適当に個数で分ければいいとは思ったが、、、詰め切れなかった。
 
 Aを大きい順に20個ほど撮っておけば、残りのAはせいぜい10^4程度で治るため
 dpで計算できる
 
 取り除いた20個についてはbit全探索が可能なため
 
 それぞれの結果を合わせる事でとける
 ================================================================
 */


string solve(){
    string res;
    ll N,X; cin >> N >> X;
    vector<pll> A(N);
    for(int i = 0; i < N;i++){
        cin >> A[i].first; A[i].second = i;
    }
    sort(A.rbegin(),A.rend());
    int K = min(20,(int)A.size());
    vector<pll> C(A.begin(),A.begin()+K),D(A.begin()+K,A.end());
    
    ll Csz = C.size();
    vector<ll> Cdp(1<<Csz);
    for(int i = 0; i < (1<<Csz); i++){
        for(int j = 0; j < Csz;j++){
            if((i>>j)&1){
                Cdp[i] += C[j].first;
            }
        }
    }
    ll Dsz = D.size();
    ll Dsum = accumulate(D.begin(),D.end(),0LL,[](ll sum,const pll& p){
        return sum + p.first;
    });
    vector<vector<int>> Ddp(Dsz+1,vector<int>(Dsum+1));
    Ddp[0][0] = true;
    for(int i = 0; i < Dsz;i++){
        for(int j = 0; j <= Dsum;j++){
            if(Ddp[i][j]){
                Ddp[i+1][j] |= Ddp[i][j];
                Ddp[i+1][D[i].first+j] |= Ddp[i][j];
            }
        }
    }
    
    vector<ll> ans;
    for(int b = 0; b < (1<<Csz);b++){
        if(Cdp[b] > X) continue;
        if(X-Cdp[b] > Dsum) continue;
        if(Ddp[Dsz][X-Cdp[b]]){
            for(int bb = 0; bb < Csz; bb++){
                if((b>>bb)&1) ans.push_back(C[bb].second);
            }
            ll now = Dsz;
            ll nowv = X - Cdp[b];
            while(now--){
                if(Ddp[now][nowv]) continue;
                if(Ddp[now][nowv-D[now].first]){
                    nowv -= D[now].first;
                    ans.push_back(D[now].second);
                }
            }
            break;
        }
    }
    if(ans.empty()) return "No";

    res = string(N,'x');
    for(auto v:ans) res[v] = 'o';
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
