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
 <url:https://dwacon2018-prelims.contest.atcoder.jp/tasks/dwacon2018_prelims_d>
 問題文============================================================
 dwango社員のニワンゴくんは、アプリ開発に携わるエンジニアです。
 ニワンゴくんは、開発したアプリのビルド・テスト・デプロイなどを毎日行っています。
 業務を効率化するために、ニワンゴくんはこういった依存関係のあるタスクを適切に実行するプログラムを書くことにしました。
 
 タスクは N 個あり、 i 番目のタスクを実行すると、その結果として xi MB のデータがディスクに書き込まれます。
 ただし、タスクは別のタスクに依存していることがあり、
 全ての依存先タスクの実行結果がディスク上に書き込まれていなければそのタスクは実行できません。
 i 番目 (2≤i≤N) のタスクを依存先に持つタスクは ai です。
 
 N 個のタスクの依存関係は、連結な有向木になることが分かっています。
 つまり、どのタスクについても、そのタスクを依存先として持つタスクはちょうど1つだけ存在します。
 ただし、例外となる1番目のタスクはどのタスクからも依存されません。
 1番目のタスクは、それ以外のすべてのタスクに直接的、あるいは間接的に依存しています。
 
 ニワンゴくんの目的は、1番目のタスクを実行し、その結果をディスク上に書き込むことです。
 さらにニワンゴくんは、計算資源をできるだけ節約したいと考えました。
 ニワンゴくんは、任意のタスクを実行した直後に、
 ディスク上に書き込まれている任意の 0 個以上のタスクの実行結果を選び、削除することができます。
 また、時間計算量も節約したいので、同じタスクを2回以上実行することはないようにしました。
 
 ニワンゴ君が1番目のタスクの実行結果を得るにはどれだけのディスクが必要でしょうか？
 適切な順番でタスクの実行および実行結果の削除を行い、
 その過程での最大のディスク使用量（ディスクに書き込まれている実行結果の量の総和）が最小になるようにしてください。
 その最小値 (MB) を出力してください。
 
 =================================================================
 解説=============================================================
 
 bitDP + メモ化再帰
 
 dp[S] := 状態Sのタスクが使用されている時の使用コスト最小パターンのうちの最大値
 
 とする。
 
 問題より、末端からタスクを使用して削除して行くのが最適だが
 初期状態をタスク１が実行されている状態から始めて、
 遷移の仕方を、現在使用されているタスクのうち一つに注目して、
 その子への遷移を行う。その時、注目したタスクを削除しておく。
 ================================================================
 */

#define MAX_N 21
ll dp[1<<MAX_N],sum[1<<MAX_N];
ll N;
ll dfs(ll S,vector<vector<ll>>& G){
    if(dp[S]>=0) return dp[S];
    ll& res = dp[S];
    res = LINF;
    for(int i = 0; i < N;i++){
        if(((S>>i)&1)==0) continue;
        ll nextS = S;
        for(auto next:G[i]) nextS |= (1<<next);
        res = min(res,max(sum[nextS],dfs(nextS^(1<<i),G)));
    }
    return res;
}

ll solve(){
    ll res = LINF;
    cin >> N;
    vector<ll> x(N),a(N);
    for(auto& in:x) cin >> in;
    
    vector<vector<ll>> G(N);
    for(int i = 1; i < N;i++){
        cin >> a[i]; a[i]--;
        G[a[i]].push_back(i);
    }
    
    fill(dp,dp+(1<<N),-1);
    dp[0] = 0;
    for(int i = 0; i < (1<<N);i++){
        for(int j = 0; j < N;j++){
            if((i>>j)&1) sum[i] += x[j];
        }
    }
    return res = dfs(1,G);
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
