#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://arc086.contest.atcoder.jp/tasks/arc086_b>
 問題文============================================================
 すぬけ君は長さ N の数列 a を持っています。a の (1-indexedでの) i 番目の数は ai です。
 
 すぬけ君は以下の操作を何度でも行うことができます。
 
 操作：1 以上 N 以下の整数 x,y を選び、ay に ax を加算する。
 すぬけ君はこの操作を 0 回以上 2N 回以下行って a が下記の条件を満たすようにしたいです。
 そのような操作手順の一例を示してください。
 なお、この問題の制約下で、条件を満たすような操作の手順が必ず存在することが証明できます。
 
 条件：a1≤a2≤…≤aN
 制約
 2≤N≤50
 −10^6≤ai≤10^6
 与えられる入力は全て整数
 =================================================================
 解説=============================================================
 
 符号が統一されている場合を考える。
 符号が統一されている時、その符号が正ならば累積和を作るように前から順にい加算していけば
 条件を満たす。
 逆に、符号が負ならば後ろから順に加算していけばよい
 この操作はN-1回要する
 
 次に、符号を統一化させる方法を考える。
 これは、配列の中の最小値または最大値を書く値に足し合わせることによって 正 or 負の符号に
 統一することができる
 この操作は高々N回
 
 よって、2N - 1 回　で条件を満たすことができるので、上の操作に必要な出力を出せば良い
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<ll> a(N);
    for(auto &in:a) cin >> in;
    ll Max_Idx = max_element(a.begin(), a.end()) - a.begin();
    vector<pll> ans;
    vector<ll> T = a;
    bool f = true;
    for(int i = 0; i < N;i++){
        T[i] += T[Max_Idx];
        if(T[i] < 0){
            f = false; break;
        }
        ans.push_back({Max_Idx,i});
    }
    if(f){
        cout << 2*N - 1 << endl;
        for(auto p:ans){
            cout << p.first +1 << " " << p.second + 1 << endl;
        }
        for(int i = 1; i < N; i++){
            cout << i << " " << i + 1 << endl;
        }
        return 0;
    }
    ans.clear();
    T = a;
    ll Min_Idx = min_element(a.begin(), a.end()) - a.begin();
    cout << 2*N - 1 << endl;
    for(int i = 1; i <= N; i++){
        cout << Min_Idx + 1 << " " << i << endl;
    }
    for(int i = N; i > 1; i--){
        cout << i << " " << i-1 << endl;
    }
    return 0;
}
