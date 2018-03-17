#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
 <url:https://agc010.contest.atcoder.jp/tasks/agc010_a>
 問題文============================================================
 黒板に N 個の整数が書かれています。i 番目の整数は Ai です。
 
 これらの数に対して、高橋君は以下の操作を繰り返します。
 
 偶奇が等しい 2 つの数 Ai,Aj を一組選び、それらを黒板から消す。
 その後、二つの数の和 Ai+Aj を黒板に書く。
 
 最終的に黒板に数が 1 つだけ残るようにできるかどうか判定して下さい。
 
 =================================================================
 
 解説=============================================================
 
 even + even = even
 odd + odd = even
 より、
 
 oddはいずれevenに変わる
 ここで、数字が全て偶数であれば、黒板の数字は一つずつ減っていくだけなので、存在すればYES
 よって、oddの個数にだけ気をつければ良い
 
 odd is even then
 yes
 else then
 no
 
 ただし、evenが存在せず、初めからoddが唯一１個であればyes
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> A(N);
    int eo[2] = {0};
    for(auto& in:A) {
        cin >> in;
        eo[in%2]++;
    }
    if(eo[1]%2 == 0){
        cout << "YES" << endl;
    }else{
        if(eo[1] == 1 && eo[0] == 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
