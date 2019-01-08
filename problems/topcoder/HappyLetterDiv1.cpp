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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;


bool dp[27][51];
class HappyLetterDiv1 {
    public:
    string getHappyLetters(string letters) {
        string res;
        sort(letters.begin(),letters.end());
        vector<int> cnt(26); for(auto c:letters) cnt[c-'a']++;
        for(int i = 0; i < 26;i++){
            auto T = cnt;
            T[i] = 0;
            
            fill(*dp,*dp+27*51,false);
            dp[0][0] = true;
            for(int j = 0; j < 26;j++){
                for(int k = 0; k < 51;k++){
                    if(dp[j][k]){
                        for(int l = 0; l <= min(T[j],k); l++){
                            dp[j+1][T[j]+k-2*l] = true;
                        }
                    }
                }
            }
            
            bool ok = false;
            for(int k = 0; k < 51;k++){
                if(dp[26][k]){
                    if(cnt[i] > k) ok = true;
                }
            }
            if(ok) res += string(1,'a'+i);
        }
        return res;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aabbacccc"; string Arg1 = "abc"; verify_case(0, Arg1, getHappyLetters(Arg0)); }
	void test_case_1() { string Arg0 = "aaaaaaaccdd"; string Arg1 = "a"; verify_case(1, Arg1, getHappyLetters(Arg0)); }
	void test_case_2() { string Arg0 = "ddabccadb"; string Arg1 = "abcd"; verify_case(2, Arg1, getHappyLetters(Arg0)); }
	void test_case_3() { string Arg0 = "aaabbb"; string Arg1 = ""; verify_case(3, Arg1, getHappyLetters(Arg0)); }
	void test_case_4() { string Arg0 = "rdokcogscosn"; string Arg1 = "cos"; verify_case(4, Arg1, getHappyLetters(Arg0)); }

// END CUT HERE


};

// BEGIN CUT HERE
//int main(){
//    HappyLetterDiv1 ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
