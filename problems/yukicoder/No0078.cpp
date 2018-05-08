#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream& operator << (ostream& out,const pair<S,T>& o){ out << "(" << o.first << "," << o.second << ")"; return out; }
template<class T> ostream& operator << (ostream& out,const vector<T> V){ for(int i = 0; i < V.size(); i++){ out << V[i]; if(i!=V.size()-1) out << " ";} return out; }
template<class T> ostream& operator << (ostream& out,const vector<vector<T> > Mat){ for(int i = 0; i < Mat.size(); i++) { if(i != 0) out << endl; out << Mat[i];} return out; }
template<class S,class T> ostream& operator << (ostream& out,const map<S,T> mp){ out << "{ "; for(auto it = mp.begin(); it != mp.end(); it++){ out << it->first << ":" << it->second; if(mp.size()-1 != distance(mp.begin(),it)) out << ", "; } out << " }"; return out; }

/*
 <url:https://yukicoder.me/problems/no/78>
 問題文============================================================
 A君は当たりクジ付きのアイスバーが大好きである。
 アイスバーには「ハズレ」と「1本当たり」と「2本当たり」がある。
 ハズレは何ももらえないが、当たりだとその本数をタダでもらえる。
 
 お店ではアイスバーが箱詰めされて売られている。
 1つの箱にはN本のアイスバーが入っている。
 A君は箱の先頭から順にしかアイスバーを取り出すことはできない。
 買う場合も当たりと引き換えの場合もこの箱からアイスバーを取り出す。
 1つの箱の中のハズレと当たりクジの配置はどの箱も同じである。
 お店には1つのアイスバーの箱があり、売り切れると1つの新しい箱を補充する。
 いまお店には新しい手つかずのアイスバーの箱がある。
 A君は最初は「当たり」クジを持っておらず予算は無限にある。
 K本のアイスバーを食べるためにはA君は最低何本のアイスを買う必要があるか？
 =================================================================
 解説=============================================================
 
 購入した本数の周期性を確認して、
 
 K本手に入れるための
 
 周期に入る前の最初の区間＋周期区間＋残りの区間
 
 の三つの区間に分けて計算する
 ================================================================
 */

ll solve(){
    ll res = 0;
    ll N,K; cin >> N >> K;
    string S; cin >> S;
    for(auto& c:S) c -= '0';
    
    ll sum = 0;
    ll a = 0;
    ll b = 0;
    vector<pll> memo(3*N);
    for(int i = 0; i < 3*N;i++){
        memo[i] = pll(a,b);
        if(a){
            a--;
        }else{
            b++;
        }
        a += S[i%N];
        sum++;
        if(sum >= K){ return res = b; }
    }
    if(a>=b) return res = b;
    
    for(int i = 1; i <= N;i++){
        if((memo[i].first + memo[i+N].first)!=0)continue;
        K -= i;
        res += memo[i].second;
        
        ll buy = memo[i+N].second - memo[i].second;
        res += K/N*buy;
        K -= K/N*N;
        
        res += memo[i+N+K].second - memo[i+N].second;
        break;
    }
    return res;
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
