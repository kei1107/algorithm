#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://abc079.contest.atcoder.jp/tasks/abc079_c>
問題文============================================================
 駅の待合室に座っているjoisinoお姉ちゃんは、切符を眺めています。
 
 切符には 4 つの 0 以上 9 以下の整数 A,B,C,D が整理番号としてこの順に書かれています。
 
 A op1 B op2 C op3 D = 7 となるように、op1,op2,op3 に + か - を入れて式を作って下さい。
 
 なお、答えが存在しない入力は与えられず、また答えが複数存在する場合はどれを出力してもよいものとします。
 
=================================================================

解説=============================================================
貪欲全探索
================================================================
*/
bool f = false;

void solve(int dep,const string& S,string op,int sum) {
    if (f)return;
    if (dep == 4) {
        if (sum == 7) {
            f = true;
            cout << (char)S[0] << (char)op[0] << (char)S[1] <<(char)op[1]
                <<(char)S[2] << (char)op[2] <<(char) S[3] << "=7" << endl;
        }
        return;
    }
    string temp1 = op;
    string temp2 = op;
    
    temp1 += '+'; solve(dep + 1, S, temp1, sum + (S[dep] - '0'));
    temp2 += '-'; solve(dep + 1, S, temp2, sum - (S[dep] - '0'));
}

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    string ABCD; cin >> ABCD;
    string op;
    solve(1,ABCD,op,ABCD[0] - '0');
    return 0;
}
