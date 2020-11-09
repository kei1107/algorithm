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
 <url:https://atcoder.jp/contests/indeednow-quala/tasks/indeednow_2015_quala_4>
 問題文============================================================
 D - パズル 
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int H,W; cin >> H >> W;
    vector<int> c(H*W); for(auto& in:c) cin >> in;
    vector<int> target(H*W);
    iota(target.begin(),target.end(),1); 
    target[H*W-1] = 0;

    int zero_pos = -1;
    int need_num = 0;
    for(int i = 0; i < H*W; i++){
        if(c[i] == 0) zero_pos = i;
        need_num += c[i] != target[i];
    }
    assert(zero_pos >= 0);

    map<pair<vector<int>,int>,int> mp;
    for(int dep = 0; dep <= 24; dep++) mp[{target,dep}] = 0;
    // mp[target] = 0;

    int dir[4] = {1,0,-1,0};
    function<int(vector<int>&,int,int,int)> dfs = [&](vector<int>& state,int id,int num,int dep){
        auto key = make_pair(state,dep);
        if(mp.count(key)){
            return mp[key];
        }
        int& ret = mp[key];
        ret = INF;
        //if(dep == 24) return ret;
        if(num > (24-dep)+1) return ret;

        int x = id/W,y = id%W;
        for(int k = 0; k < 4;k++){
            int nx = x + dir[k];
            int ny = y + dir[k^1];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

            int next_id = nx*W + ny;

            int next_num = num;
            
            next_num += state[id]==target[id];
            next_num += state[next_id]==target[next_id];

            next_num -= state[id]==target[next_id];
            next_num -= state[next_id]==target[id];

            swap(state[id],state[next_id]);
            ret = min(ret,dfs(state,next_id,next_num,dep+1)+1);
            swap(state[id],state[next_id]);
        }
        return ret;
    };
    res = dfs(c,zero_pos,need_num,0);
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<ll>() << endl;
    return 0;
}