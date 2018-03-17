#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
 <url:https://arc059.contest.atcoder.jp/tasks/arc059_b>
 問題文============================================================
 文字列 t について、t の長さが 2 以上であり、かつ t の中の文字のうち過半数が同じ文字であるとき、
 t をアンバランスであると呼ぶことにします。
 例えば、voodoo や melee はアンバランスであり、noon や a はアンバランスではありません。
 
 小文字のアルファベットからなる文字列 s が与えられます。
 s にアンバランスな (連続する) 部分文字列が存在するか判定してください。
 存在する場合は、s の中でそのような部分文字列が存在する位置を一つ示してください。
 =================================================================
 
 解説=============================================================
 アンバランスな文字には必ず ”XX” or "XYX" といったアンバランスな文字が含まれる。
 よって、この２パターンだけを確認すれば良い
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    string s; cin >> s;
    int l = -1, r = -1;
    
    for(int i = 0; i < (int)s.length()-1;i++){
        if(s[i] == s[i+1]){
            l = i; r = i+1;
            break;
        }
    }
    if(l != -1){
        cout << l + 1 << " " << r + 1 << endl; return 0;
    }
    for(int i = 0; i < (int)s.length()-2;i++){
        if(s[i] == s[i+1] || s[i] == s[i+2] || s[i+1] == s[i+2]){
            l = i; r = i+2; break;
        }
    }
    if(l != -1){
        cout << l+1 << " " << r+1 << endl;
    }else{
        cout << -1 << " " << -1 << endl;
    }
    return 0;
}
