#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 最長共通部分文字列(longest common substring)
 互いの文字列で連続して一致する最大の文字列を取得
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    string s1, s2; cin >> s1 >> s2;
    int res = 0;
    for(int j = -(int)s1.length();j <= (int)s2.length();j++){
        int len = 0;
        for(int i = max(j,0); i < min(s1.length()+j,s2.length()); i++){
            if(s1[i - j] == s2[i]){
                len++;
                res = max(res,len);
            }else{
                len = 0;
            }
        }
    }
    cout << res << endl;
    return 0;
}
