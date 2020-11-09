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
 <url:https://atcoder.jp/contests/arc013/tasks/arc013_3>
 問題文============================================================
 C - 笑いをとれるかな？ 
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;

    vector<int> xors;
    for(int i = 0; i < N;i++){
        vector<int> XYZ(3);
        for(auto& in:XYZ) cin >> in;
        int M; cin >> M;

        vector<pii> mm(3,pii(INF,0));
        for(int j = 0; j < M;j++){
            vector<int> xyz(3);
            for(auto& in:xyz) cin >> in;

            for(int k = 0; k < 3;k++){
                mm[k].first  = min(mm[k].first,xyz[k]);
                mm[k].second = max(mm[k].second,xyz[k]);
            }
        }

        // cout << mm << endl;
        for(int k = 0; k < 3;k++){
            xors.emplace_back(mm[k].first);
            xors.emplace_back(XYZ[k]-mm[k].second-1);
        }
    }
    
    int XOR = 0;
    // cout << xors << endl;
    for(auto val:xors){
        // cout << XOR << " -> " << (XOR^val) << endl;
        XOR ^= val;
    }
    
    if(XOR) return "WIN";
    else return "LOSE";
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<string>() << endl;
    return 0;
}