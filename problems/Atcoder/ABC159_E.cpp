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
 <url:https://atcoder.jp/contests/abc159/tasks/abc159_e>
 問題文============================================================
 E - Dividing Chocolate
 =================================================================
 解説=============================================================

 実装をがんばる問題。
 まず、横に分割する全パターン(2^Hパターン)についてみる。
 各パターンに対して左から順にホワイトチョコレートがKマス以下に収まるぎりぎりの範囲で縦に分割していく。
 このときの最小操作回数が答えとなる。


 https://atcoder.jp/contests/abc159/submissions/11674578

 ================================================================
 */

template<class Type>
Type solve(Type res = Type()){
    int H,W,K; cin >> H >> W >> K;
    vector<vector<char>> S(H,vector<char>(W));
    for(auto& vec:S) for(auto& in:vec) cin >> in;

    res = INF;
    for(int b = 0; b < (1<<H); b++){
        vector<int> steps;
        int now = 0;
        int pre = -1;
        for(int i = 0; i < H;i++){
            if(((b>>i)&1)==pre){
                now++;
            }else{
                if(pre == -1){
                    now=1;
                }else{
                    steps.emplace_back(now);
                    now = 1;
                }
                pre = ((b>>i)&1);
            }
        }
        steps.emplace_back(now);

        int stepn = (int)steps.size();
        vector<int> Wcnt(stepn);
        bool ng = false;
        ll T = 1;
        for(int j = 0; j < W;j++){
            {
                int i = 0;
                for(int n = 0; n < stepn; n++){
                    for(int ii = 0; ii < steps[n]; ii++,i++){
                        if(S[i][j]=='1'){
                            Wcnt[n]++;
                        }
                    }
                }
            }
            if(*max_element(Wcnt.begin(),Wcnt.end()) > K){
                T++;
                fill(Wcnt.begin(),Wcnt.end(),0);
                {
                    int i = 0;
                    for(int n = 0; n < stepn; n++){
                        for(int ii = 0; ii < steps[n]; ii++,i++){
                            if(S[i][j]=='1'){
                                Wcnt[n]++;
                            }
                        }
                    }
                }
                if(*max_element(Wcnt.begin(),Wcnt.end()) > K){
                    ng = true;
                    break;
                }
            }
        }
        if(ng) continue;
        res = min(res,(stepn-1) + (T-1));
    }

    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    // solve(0);
    cout << fixed << setprecision(15) << solve<ll>() << endl;
    return 0;
}
