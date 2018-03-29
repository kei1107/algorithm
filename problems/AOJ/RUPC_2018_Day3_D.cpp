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
<url:https://onlinejudge.u-aizu.ac.jp/services/room.html#RitsCamp18Day3/problems/D>
問題文============================================================

 えびちゃんは素因数分解マシンの不良品を持っています。
 この機械は、2 以上の自然数 M を与えると O(logM) でその素因数分解を行ってくれますが、
 困ったことに数字以外を表示できないバグがありました。
 
 一般に、M の素因数分解が p1e1×p2e2×…×pKeK (ただし i<j ならば pi<pj、また各 pi は素数) の場合を考えます。
 M を与えると、この機械は i=1 から順に以下のように出力を行います。全ての数字はスペース区切りで表示されます。
 
 ei=1 ならば pi を出力する
 ei>1 ならば pi ei を出力する
 
 たとえば、22 や 2048 を与えると 2 11 と表示され、24 や 54 を与えると 2 3 3 と表示されます。
 
 さて、えびちゃんは表示された素因数分解をメモしておいたのですが、
 与えた自然数をメモしておくのを忘れていたことに気づきました。
 素因数分解のメモが与えられるので、元の自然数としてありえるものがいくつあるかを求めてください。
 ただし、メモが間違っていて、条件を満たす自然数が一つも存在しないこともあります。
 
 また、その個数は非常に大きくなる場合があるので、109+7 (素数) で割ったあまりを出力してください。
 
=================================================================

解説=============================================================
 
 x y z
 と素数(x<y<z)が並んでいるとすると
 直接zに繋がる遷移としては
 y^1 z
 x^y z
 の二通りが考えられる
 
 ここで dp[i] := i番目にある素数を見たときの場合の数とすると
 
 q[i] is prime という条件のもとで
     if q[i+1] is prime  && q[i] < q[i+1] then
         dp[i+1] += dp[i] ( x^y )
     if q[i+2] is prime && q[i] < q[i+2] then
         dp[i+2] += dp[i] ( x^y z )
 
 と遷移できる
 
 出力は dp[N-1] + dp[N-2]    ( y^1 z のパターン と x^y z のパターン)
================================================================
*/

#define MAX_N 1000005
bool is_prime[MAX_N];
const ll MOD = 1e9+7;

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

void init(){
    for(int i = 1; i < MAX_N;i++){
        is_prime[i] = IsPrime(i);
    }
}
ll solve(){
    ll N; cin >> N;
    vector<ll> q(N);
    for(auto& in:q)cin >> in;

    if(!is_prime[q[0]]) return 0;
    if(N == 1) return 1;
    
    int cnt = 0;
    for(int i = 0; i < N;i++){
        if(!is_prime[q[i]]) cnt++;
        else cnt = 0;
        if(cnt == 2) return 0;
    }

    vector<ll> dp(N+1,0);
    dp[0] = 1;
    for(int i = 0; i < N;i++){
        if(is_prime[q[i]]){
            if( i+1 < N && is_prime[q[i+1]] && (q[i] < q[i+1])){
                (dp[i+1] += dp[i])%=MOD;
            }
            if( i+2 < N && is_prime[q[i+2]] && (q[i] < q[i+2])){
                (dp[i+2] += dp[i])%=MOD;
            }
        }
    }
    return (dp[N-1]+dp[N-2])%MOD;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    init();
    cout << solve() << endl;
	return 0;
}
