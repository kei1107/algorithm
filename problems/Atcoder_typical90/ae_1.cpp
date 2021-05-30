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
 <url:https://atcoder.jp/contests/typical90/tasks/typical90_ae>
 問題文============================================================
 =================================================================
 解説=============================================================
 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int N; cin >> N;

    auto grundy = make_v<int>(1500,1500);
    fill_v(grundy,-1);
    grundy[0][0] = grundy[0][1] = 0;

    auto calc_grundy = [&](auto self,int w,int b) -> int{
        int& ret = grundy[w][b];
        if(ret != -1) return ret;

        set<int> ng;
        if(w >= 1){
            // select w
            ng.emplace(self(self,w-1,b+w));
        }
        if(b >= 2){
            // select b
            for(int k = 1; k <= b/2; k++){
                ng.emplace(self(self,w,b-k));
            }
        }
        int cand = 0;
        while(ng.count(cand)) cand++;
        ret = cand;
        return ret;
    };

    vector<int> W(N),B(N);
    for(auto& in:W) cin >> in;
    for(auto& in:B) cin >> in;

    int XOR = 0;
    for(int i = 0; i < N;i++){
        XOR ^= calc_grundy(calc_grundy,W[i],B[i]);
    }
    if(XOR) return "First";
    else return "Second";
    return res;
}
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    //solve<ll>(0);
    cout << fixed << setprecision(12) << solve<string>() << endl;
    return 0;
}