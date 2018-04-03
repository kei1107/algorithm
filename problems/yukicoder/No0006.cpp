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
 <url:https://yukicoder.me/problems/no/6>
 問題文============================================================
 ハッシュに興味を持ったFrankは、ハッシュアルゴリズムに、このようなアルゴリズムを考えた。
 自然数の各桁を足した合計、それも二桁以上になる場合は、それを繰り返す。
 つまり、
 hash(4)=4,
 hash(17)=hash(1+7)=hash(8)=8,
 hash(119)=hash(1+1+9)=hash(11)=hash(2)=2のようになる。
 
 しかし実際使ってみるとコリジョン（計算値がかぶってしまうこと）が多く、あまり使い物にならなかった。
 
 それでも諦めきれないFrankに対して、あなたは「落ち着け、素数を数えるんだ」と言った。
 やけになったFrankは、自然数 [K,N]　(K≤i≤N の範囲ということ） の中の連続した素数列で上記のハッシュアルゴリズムを使用し、
 コリジョンが起こらない（値がかぶらない）最大の範囲を考えようとしている。
 言った手前、申し訳なくなったあなたは、Frankの代わりに求めてあげることにした。
 
 範囲[K,N] (K≤i≤N の範囲)に含まれる連続した素数列で上記のハッシュアルゴリズムを使用した時に、
 すべて異なる値になる最大の長さの素数列を求め、元の素数列の最初の素数を求めてください。
 (複数同じ長さの素数列がある場合は、数が大きい方を選択する）

 =================================================================
 解説=============================================================
 
 [K,N]での素数について、その値とhashについてのテーブルと作っておく
 
 あとは、区間[l,r]について同じhashが二つ存在しないように l = r = 0からシミュレーションすれば良い
 
 ================================================================
 */

ll Hash(ll x){
    if(x < 10) return x;
    string s = to_string(x);
    ll sum = 0; for(auto c:s) sum += (c-'0');
    return Hash(sum);
}

bool IsPrime(ll num)
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

ll solve(){
    ll res = 0;
    ll K,N; cin >> K >> N;
    vector<ll> primes;
    vector<ll> h;
    for(ll i = K; i <= N;i++){
        if(IsPrime(i)){
            primes.push_back(i);
            h.push_back(Hash(i));
        }
    }

//    for(auto v:primes) cout << setw(2) << v << " "; cout << endl;
//    for(auto v:h) cout << setw(2) << v << " "; cout << endl;
    
    ll maxlen = 0;
    vector<pll> hl(10,{0,-1});
    ll l = 0,r = 0;
    for(;r < (int)primes.size(); r++){
        if(hl[h[r]].first == 0){
            hl[h[r]].first = 1;
            hl[h[r]].second = r;
            if(r-l+1>=maxlen){
                maxlen = r-l+1;
                res = primes[l];
            }
        }else{
            while(l<=hl[h[r]].second){
                hl[h[l]].first = 0;
                l++;
            }
            hl[h[r]].first = 1;
            hl[h[r]].second = r;
            if(r-l+1>=maxlen){
                maxlen = r-l+1;
                res = primes[l];
            }
        }
    }
    return res;
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
