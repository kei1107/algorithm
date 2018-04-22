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
 <url:https://beta.atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_d>
 問題文============================================================
 ある日 S 君は環状の道路をドライブすることにした。
 
 この環状道路には等間隔に休憩所があり、0 から M-1 までの番号が振られている。
 S 君は 0 番の休憩所からスタートし、
 0 → 1 → 2 → … → ( M − 2 ) → ( M − 1 ) → 0 → 1 → 2 → … と巡回する。
 
 S 君の車は，燃料 1 リットルで休憩所を 1 つ進むことができる。
 しかし燃料の補充の際は、あらかじめ用意した、補充量が
 a1 , a2 , a3 , … , aN−1 , aN である
 N 個の燃料タンクから 1 つ以上選んで補充しなけらばならない。
 燃料タンクは補充を行うと空になるため、同じ燃料タンクを 2 回以上選ぶことはできない。
 この車は走り出すと燃料を使い切るまで止まらないため、ある特定の休憩所に停まりたい場合は、
 ぴったりそこで燃料が尽きるように補充する燃料タンクを選ばなければならない。
 
 S 君は番号 L の休憩所で友人と待ち合わせをしており、
 車の燃料が 0 の状態で燃料タンクを複数選んで補充し、番号 0 の休憩所からスタートして番号 L の休憩所に停まりたい。
 しかし環状道路を X 周以上すると市の交通条例違反になってしまう。
 
 S 君が X 周以内に番号 L の休憩所に停まることができるような燃料タンクの選び方は存在するかどうかを判定せよ。
 
 燃料の補充は最初の 1 回のみである。また、スタート直後は 1 周目と定義し、
 再び番号 0 の休憩所にたどり着いた時点で次の周回とする。
 
 =================================================================
 解説=============================================================
 
 適切に選んだ燃料タンクの合計が M*x+L となれば良い ( 0 <= x < X-1)
 ここで、休憩所は円環状にループするため　M*x+LからMの剰余をとって L としてしまっても問題無く、
 これはすべての休憩所にいえる
 よって、 問題は休憩所LにX周未満で到達できるかいなかという問題に言い換えることができる。
 したがって
 dp[i][j] := i番目の燃料タンクを見たとき、休憩所jに到達できる最小周回数
 として計算することができる。
 計算量はO(NM)となり、間に合う
 
 ================================================================
 */

string solve(){
    string res = "";
    ll N,M,L,X; cin >> N >> M >> L >> X;
    vector<ll> a(N); for(auto& in:a) cin >> in;
    vector<vector<ll>> dp(N+1,vector<ll>(M,LINF));
    dp[0][0] = 1;
    for(int i = 0; i < N;i++){
        for(int j = 0; j < M;j++){
            if(dp[i][j] == LINF) continue;
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
            dp[i+1][(j+a[i])%M] = min(dp[i+1][(j+a[i])%M],dp[i][j] + (j+a[i])/M);
        }
    }
    if(dp[N][L] < X) return "Yes";
    return "No";
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}
