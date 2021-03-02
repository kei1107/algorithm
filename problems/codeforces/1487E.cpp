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
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(size_t i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(size_t i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}
/*
 <url:https://codeforces.com/problemset/problem/1487/E>
 問題文============================================================
 E. Cheap Dinner
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    vector<int> ns(4); for(auto& in:ns) cin >> in;
    vector<vector<int>> cs(4);

    for(int i = 0; i < 4;i++){
        cs[i].resize(ns[i]);
        for(auto& in:cs[i]) cin >> in;
    }
    
    vector<int> ms(4);
    vector<vector<pii>> ps(4);

    for(int i = 0; i < 4; i++){
        cin >> ms[i];
        ps[i].resize(ms[i]);
        for(auto& in:ps[i]){
            cin >> in.first >> in.second; in.first--; in.second--;
        }
    }

    for(int t = 1; t < 4; t++){

        // 昇順に並べ替え
        vector<pii> ts;
        for(int i = 0; i < ns[t-1]; i++){
            ts.emplace_back(cs[t-1][i],i);
        }
        sort(ts.begin(),ts.end());
        // 併せて要素番号を修正
        map<int,int> mp;
        for(int i = 0; i < ns[t-1];i++){
            mp[ts[i].second] = i;
        }
        for(int i = 0; i < ms[t-1];i++){
            ps[t-1][i].first = mp[ps[t-1][i].first];
        }

        // t-1 -> t　へ最小コストとなるようにペア決め
        vector<vector<int>> tp(ns[t]);
        for(int i = 0; i < ms[t-1]; i++){
            tp[ps[t-1][i].second].emplace_back(ps[t-1][i].first);
        }
        for(int i = 0; i < ns[t]; i++){
            sort(tp[i].begin(),tp[i].end());
        }
        for(int i = 0; i < ns[t];i++){
            int id = 0;
            for(auto p:tp[i]){
                if(p == id){  id++; continue; } 
                break;
            }
            if(id == (int)ts.size()) cs[t][i] = INF;
            else { 
                cs[t][i] += ts[id].first;
                cs[t][i] = min(cs[t][i],INF);
            }
        }
    }

    res = *min_element(cs[3].begin(),cs[3].end());
    if(res == INF) res = -1;
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}