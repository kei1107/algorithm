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
 <url:https://yukicoder.me/problems/no/2>
 問題文============================================================
 最近素因数を習ったばかりのAliceとBobが数字に関するゲームをします。
 
 ゲームの内容は以下のとおりです。
 ・まず初めに、先攻のプレイヤーに2以上の自然数Nが与えられます。
 ・その番のプレイヤーは、Nに対して、「Nの素因数」のどれかで割り、相手にその商になる数を渡します。
 ・この時、同じ数であれば、割り切れる限り１回以上であれば何回割ってもいいこととします。
 
 例えば、24の素因数は 2,3 (24=2×2×2×3) であるため 24を2で2回わった数6を相手に渡すことが出来ます。
 ・次のプレイヤーは渡された数を新たなNとし、以上の手順を繰り返します。
 ・渡された数が1になったプレイヤーが負けです。
 
 まずAliceが先攻となりゲームを始めます。
 この時、どちらも最善を尽くすと考えたとき、自然数Nが与えられた時の勝者を求めてください。
 =================================================================
 解説=============================================================
 
 問題を言い換えると、各素因数の個数に対応した 高さi の山がある
 この山からの石とりゲームとみなせるので Nim
 
 ================================================================
 */

/* 素因数分解 */
vector<ll> PrimeFact(ll n){
    vector<ll> res;
    while(n!=1){
        if(n == 2 || n == 3){
            res.emplace_back(n); n/=n;
            continue;
        }
        bool prime_flag = false;
        for(int i = 2;i*i <= n;i++){
            if(n%i==0){
                res.emplace_back(i); n/=i;
                prime_flag = true;
                break;
            }
        }
        if(!prime_flag){res.emplace_back(n); n/= n;}
    }
    return res;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    auto primes = PrimeFact(N);
    map<ll,int> mp;
    for(auto prime:primes) mp[prime]++;
    ll x = 0;
    for(auto c:mp){
        x ^= c.second;
    }
    if(x) cout << "Alice" << endl;
    else cout << "Bob" << endl;
    return 0;
}
