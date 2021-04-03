#include "bits/stdc++.h"
#include "atcoder/all"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
inline ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://atcoder.jp/contests/arc111/tasks/arc111_c>
 問題文============================================================
 C - Too Heavy 
 =================================================================
 解説=============================================================
 ================================================================
 */
template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;
    vector<int> a(N),b(N),p(N);
    for(auto& in:a) cin >> in;
    for(auto& in:b) cin >> in;
    for(auto& in:p) cin >> in;

    vector<pii> pos;
    vector<int> bpos(N);
    for(int i = 0; i < N;i++){
        p[i]--;
        if(i != p[i] && a[i] <= b[p[i]]){
            cout << -1 << endl;
            return res;
        }
        pos.emplace_back(a[i],i);
        bpos[p[i]] = i;
    }
    sort(pos.begin(),pos.end());
    
    // cout << a << endl;
    // cout << b << endl;
    // cout << p << endl;
    // cout << " ---- " << endl;
    // cout << bpos << endl;
    // cout << " ==== " << endl;

    vector<pii> ans;
    for(int i = 0; i < N;i++){
        auto [w,id] = pos[i];
        if(id == p[id]) continue;
        int next_id = bpos[id];

        // cout << id << " -> " << next_id << endl;
        ans.emplace_back(id+1,next_id+1);
        swap(p[id],p[next_id]);
        swap(bpos[id],bpos[p[next_id]]);

        // cout << p << endl;
    }

    cout << ans.size() << endl;
    for(auto p:ans) cout << p.first << " " << p.second << endl;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    solve<ll>(0);
    // cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}