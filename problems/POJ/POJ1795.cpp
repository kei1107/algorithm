#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <bitset>
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF (1<<30)
#define LINF (1LL<<60)

/*
 <url:>
 問題文============================================================
 
 =================================================================
 
 解説=============================================================
 与えられた文字列で他の文字列に既に含まれているものを削除し、
 
 残った文字列で、bitDP(順番に巡回セールマンのようにみていき、文字列の追加方法は後ろに追加していく）
 ================================================================
 */

int dp[1<<15][15];
bool ok[1<<15][15];
int s12len[15][15];

void init(){
    for(int i = 0; i < (1<<15);i++)for(int j = 0; j < 15;j++) {
        dp[i][j] = INF; ok[i][j] = false;
    }
    for(int i = 0; i < 15;i++) for(int j = 0; j < 15;j++) s12len[i][j] = 0;
}
// 他の文字に包括されている文字列をまとめる
vector<string> str_merge(vector<string>& S){
    vector<bool> flag(S.size());
    for (int i = 0; i < (int)S.size(); i++) {
        for (int j = 0; j < (int)S.size(); j++) {
            if (i != j) {
                if (!flag[i] && S[i].find(S[j]) != string::npos) {
                    flag[j] = true;
                }
            }
        }
    }
    vector<string> res;
    for (int i = 0; i < S.size(); i++) {
        if (!flag[i]) res.push_back(S[i]);
    }
    return res;
}

int check(string& s1,string&s2){
    for(int i = 0; i < (int)s1.length();i++){
        if(s1[i] != s2[0]) continue;
        string s = s1.substr(i);
        if(s2.find(s) == 0) return (int)s.size();
    }
    return 0;
}

void dfs(int S,int last,string rec,string& ans,vector<string>&str,int n){
    if(S == (1<<n)-1){
        ans = min(ans,rec);
        return ;
    }
    for(int i = 0; i < n;i++){
        if((S>>i)&1) continue;
        if(ok[S|(1<<i)][i]){
            if(dp[S][last] + str[i].length() - s12len[last][i] == dp[S|(1<<i)][i]){
                string s = rec + str[i].substr(s12len[last][i]);
                if(s < ans){
                    dfs(S|1<<i,i,s,ans,str,n);
                }
            }
        }
    }
    return ;
}

int main(void) {
    int kassa; scanf("%d",&kassa);
    for(int kinoGassa = 1; kinoGassa <= kassa;kinoGassa++){
        init();
        int n; scanf("%d",&n);
        vector<string> str(n);
        for(int i = 0; i <n;i++) cin >> str[i];
        str = str_merge(str);
        sort(str.begin(),str.end());
        n = (int)str.size();
        
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                if(i==j)continue;
                s12len[i][j] = check(str[i],str[j]);
            }
        }
        
        
        for(int i = 0; i < n;i++){
            dp[1<<i][i] = (int)str[i].length();
        }
        
        for(int i = 0; i < (1<<n);i++){
            for(int j = 0; j < n;j++){
                if(dp[i][j] == INF)continue;
                for(int k = 0; k < n;k++){
                    if((i>>k)&1)continue;
                    dp[i|(1<<k)][k] = min(dp[i|(1<<k)][k],dp[i][j] + (int)str[k].size() - s12len[j][k]);
                }
            }
        }
        
        int MinLen = INF;
        for(int i = 0; i < n;i++){
            MinLen = min(MinLen,dp[(1<<n)-1][i]);
        }
        for(int i = 0; i < n;i++){
            if(dp[(1<<n)-1][i] == MinLen) ok[(1<<n)-1][i] = true;
        }
        
        for(int i = (1<<n)-1;i >= 0; i--){
            for(int j = 0; j < n;j++){
                if(!ok[i][j])continue;
                for(int k = 0; k < n;k++){
                    if(j == k) continue;
                    if((i>>j)&1){
                        if(dp[i&~(1<<j)][k] + str[j].size() - s12len[k][j] == dp[i][j]){
                            ok[i&~(1<<j)][k] = true;
                        }
                    }
                }
            }
        }
        
        string ans = "Z";
        for(int i = 0; i < n;i++){
            if(ok[1<<i][i]) dfs(1<<i,i,str[i],ans,str,n);
        }
        cout << "Scenario #"  << kinoGassa << ":" << endl;
        cout << ans << endl << endl;
    }
    return 0;
}
