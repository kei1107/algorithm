#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60
/*
 <url:https://cf17-relay-open.contest.atcoder.jp//tasks/relay2_g>
 問題文============================================================
 英小文字からなる二つの文字列 s, t と整数 L が与えられます。
 s, t を任意の順に一個以上並べて長さ L の文字列を生成することを考えます。
 このとき、同じ文字列を複数回用いることもできます。
 
 例えば、s= at, t= code, L=6 のとき、文字列 atatat, atcode, codeat を生成することができます。
 
 このようにして生成される長さ L の文字列のうち、辞書順最小のものを求めてください。
 なお、入力として与えられるケースでは、長さ L の文字列を生成することは必ず可能です。
 =================================================================
 解説=============================================================
 単純に s と tを見たとき、辞書順で小さい方を優先的に連結してLを作ればよい
 
 一点、コーナーケースとして
 s = ab
 t = aba
 のような場合
 s < t に対して
 s + t = ababa < t + s = abaab
 のような例がある。これはt優先で連結しなければならない
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int L; cin >> L;
    string s,t;cin >> s >> t;
    if(t + s < s + t) swap(s,t);
    string ans;
    for(int i = L; i >= 0; i--){
        ll len = s.length() * i;
        if(L - len >= 0 && (L - len)%t.length() == 0){
            for(int j = 0; j < i;j++){
                ans += s;
            }
            for(int j = 0; j < (L-len)/t.length();j++){
                ans += t;
            }
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
