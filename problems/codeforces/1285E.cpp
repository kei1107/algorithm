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
 <url:https://codeforces.com/problemset/problem/1285/E>
 問題文============================================================
 E. Delete a Segment
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int n; cin >> n;
    vector<ll> ls,rs,vs;
    for(int i = 0; i < n;i++){
        ll l,r; cin >> l >> r;
        ls.emplace_back(l); rs.emplace_back(r);
        vs.emplace_back(l); vs.emplace_back(r);
    }
    sort(vs.begin(),vs.end());
    vs.erase(unique(vs.begin(),vs.end()),vs.end());
    vector<pll> imos(2*(vs.size()+1)+1);
    for(int i = 0; i < n;i++){
        ls[i] = lower_bound(vs.begin(),vs.end(),ls[i]) - vs.begin() + 1;
        rs[i] = lower_bound(vs.begin(),vs.end(),rs[i]) - vs.begin() + 1;
        
        imos[2*ls[i]].first += 1;
        imos[2*ls[i]].second += (i+1);
        
        imos[2*rs[i]+1].first -= 1;
        imos[2*rs[i]+1].second -= (i+1);
    }
    ll pre_v = 0;
    for(int i = 1; i <= 2*((int)vs.size()+1); i++){
        imos[i].first += imos[i-1].first;
        imos[i].second += imos[i-1].second;

        if(imos[i-1].first == 0 && imos[i].first != 0){
            pre_v++;
        }
    }

    vector<ll> vals(n+1);
    ll target_id = -1;
    int left_state = -1;
    for(int i = 1; i <= 2*((int)vs.size()+1); i++){
        if(imos[i].first == 0){
            if(target_id != -1 && left_state == 0){
                vals[target_id] -= 1;
            }
            target_id = -1;
            left_state = -1;
            continue;
        }else if(imos[i].first != 1){
            if(target_id != -1 && left_state != 0){
                vals[target_id] += 1;
            }
            target_id = -1;
            left_state = -1;
            continue;
        }
        ll id = imos[i].second;
        if(imos[i-1].first == 0){
            target_id = id;
            left_state = 0;
            continue;
        }
        if(imos[i-1].first > 1){
            target_id = id;
            left_state = 1;
            continue;
        }
        if(imos[i-1].first == 1 && imos[i-1].second != id){
            if(left_state != 0){
                vals[target_id] += 1;
            }
            target_id = id;
            left_state = 1;
            continue;
        }
    }

    for(int i = 1; i <= n; i++){
        res = max(res,pre_v + vals[i]);
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    int t; cin >> t;
    while(t--){
        cout << fixed << setprecision(15) << solve<ll>() << endl;
    }
    return 0;
}
