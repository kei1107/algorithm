#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;

/*
<url:https://colopl2018-qual.contest.atcoder.jp/tasks/colopl2018_qual_d>
問題文============================================================
 あなたは、「すぬけそだて」を楽しんでいます。
 愛しのすぬけ君をできるだけ賢いねこにしたいあなたは、すぬけ君の知力トレーニングをすることにしました。
 
 「すぬけそだて」では、あなたは「スタミナ」を消費してすぬけ君の知力をトレーニングすることができます。
 スタミナを 1 消費するごとに、すぬけ君の知力は 1 だけ上がります。
 
 スタミナは、1 単位時間に 1 だけ、最大で X まで回復します。
 スタミナが上限 X に達している場合、時間経過でスタミナが回復することはありません。
 また、スタミナを 0 未満にすることはできません。
 初期状態、すなわち時刻 O において、スタミナは満タンに、すなわち X だけ溜まっています。
 
 もちろん、スタミナが溜まったらすぐに消費するのが最も効率的なのですが、
 残念なことにあなたには現実世界での用事があり、
 四六時中「すぬけそだて」を遊んでいるというわけにはいきません(現実の生活というのは、往々にして融通の利かないものです)。
 
 それでも、あなたは多忙な生活の合間を縫って、「すぬけそだて」を起動できる時間の候補を N 個ひねり出しました。
 i 個目の候補は時刻 Ti です。
 あなたは多忙なため、一度ゲームを起動したら、一瞬のうちにスタミナの消費を終えてゲームを終了しなければなりません。
 すなわち、時刻 Ti にスタミナが s だけ残っていた場合、あなたはスタミナを s 以下の任意の非負整数量消費し、
 消費した分だけすぬけ君の知力を上げる操作をすることができますが、 それ以外の操作はできません。
 
 現実の予定というのはなかなか決まらないもので、あなたは自分がこれから先しばらくどれほど忙しいのかを読み切れずにいます。
 そこで、各 K=1,2,…,N について、 N 個のゲームの起動時刻の候補のうち K 個以下を選んでゲームを起動する場合に、
 最終的にすぬけ君の知力が最大でいくつになるのかを計算することにしました。
 これらの N 個の値をすべて求めてください。
 
=================================================================

解説=============================================================

 dp[i][j] := i 番目の候補の時点で、 j 回ゲームを起動しているときの回数
 
 としてdp
 このままだと間に合わないが
 問題の本質より スタミナが満タンになる前であれば　、　なるべくゲーム起動を遅くした方がよく
             スタミナが満タンになった後であれば、　なるべくゲーム起動を早くした方が良い
 という条件を考えれば、分岐はその境目の２種類でよくなるので O(N^2)
================================================================
*/

ll dp[5005][5005];
void solve(){
    ll N,X; cin >> N >> X;
    vector<ll> T(N);
    for(auto &in:T) cin >> in;
    dp[0][1] = X;
    for(int i = 0; i < N-1;i++){
        ll l,r; l = r = i + 1;
        for(int j = i + 1; j < N;j++){
            if(T[j] - T[i] <= X) l = j;
            else { r = j; break;}
        }
        for(int j = 1; j <= N;j++){
            dp[l][j] = max(dp[l][j],dp[i][j-1] + min(X,T[l]-T[i]));
            dp[r][j] = max(dp[r][j],dp[i][j-1] + min(X,T[r]-T[i]));
        }
    }
    ll ans = 0;
    for(int i = 1; i <= N;i++){
        for(int j = 0; j <= N;j++){
            ans = max(ans,dp[j][i]);
        }
        cout << ans << endl;
    }
    return;
}
int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
    solve();
	return 0;
}
