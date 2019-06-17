#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T>& V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> >& Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T>& mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }
template<typename T>vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));}
template<typename T,typename V> typename enable_if<is_class<T>::value==0>::type fill_v(T &t,const V &v){t=v;}
template<typename T,typename V> typename enable_if<is_class<T>::value!=0>::type fill_v(T &t,const V &v){for(auto &e:t) fill_v(e,v);}

int solution(vector<int> &A, int X) {
    ll ret = 0;
    map<int,int> mp; for(auto& a:A) mp[a]++;
    vector<pii> vals;
    for(auto p:mp){
        if(p.second < 2) continue;
        vals.push_back({p.first,p.second/2});
    }
    sort(vals.begin(),vals.end());
    
    int N = (int)vals.size();
    
    ll cnt = 0;
    for(auto p:vals){
        int Y = (X + p.first - 1)/p.first;
        int idx = (int)((lower_bound(vals.begin(),vals.end(),pii(Y,0))-vals.begin()));
        ret += N - idx;
        if(Y <= p.first){
            ret--;
            if(p.second >= 2){
                cnt++;
            }
        }
    }
    ret /= 2;
    ret += cnt;
    if(ret > INF) ret = -1;
    return (int)ret;
}
