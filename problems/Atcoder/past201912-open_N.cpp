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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    ll N,W,C; cin >> N >> W >> C;
    vector<ll> lr;
    vector<ll> ls(N),rs(N),ps(N);
    for(int i = 0; i < N;i++){
        cin >> ls[i] >> rs[i] >> ps[i];
        
        ls[i]; rs[i];
        for(int j = -1; j <= 1; j++){
            lr.emplace_back(min(max(0LL,ls[i]+j),W));
            lr.emplace_back(min(max(0LL,rs[i]+j),W));
        }
    }
    lr.emplace_back(0);
    lr.emplace_back(W);
    
    sort(lr.begin(),lr.end());
    lr.erase(unique(lr.begin(),lr.end()),lr.end());
    
    
    int n = (int)lr.size();
    using Item = tuple<ll,int>;
    vector<vector<Item>> events(n);
    
    for(int i = 0; i < N;i++){
        ls[i] = lower_bound(lr.begin(),lr.end(),ls[i]) - lr.begin();
        rs[i] = lower_bound(lr.begin(),lr.end(),rs[i]) - lr.begin();
        
        events[ls[i]].emplace_back(ps[i],0); // 設置
        events[rs[i]].emplace_back(ps[i],1); // 撤去
    }
    int l = 0, r = 0;
    ll sump = 0;
    res = numeric_limits<ll>::max();
    
    while(true){
        while(r < n-1 && lr[r] - lr[l] < C){
            for(auto event : events[r]){
                ll p; int status;
                tie(p,status) = event;
                if(status == 0){
                    sump += p;
                }
            }
            r++;
        }
        while(l <= r && lr[r] - lr[l] >= C){
            for(auto event : events[l]){
                ll p; int status;
                tie(p,status) = event;
                if(status == 1) sump -= p;
            }
            res = min(res,sump);
            l++;
        }
        if(r == n-1){ break; }
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
