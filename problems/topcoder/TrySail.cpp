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

bool dp[2][256][256][2][2];
class TrySail {
public:
    int get(vector <int> strength) {
        int res = 0;
        int N = (int)strength.size();
        int XOR = 0; for(auto v:strength) XOR ^= v;
        
        for(int i = 0; i < N;i++){
            int cur = 0,next = 1;
            fill(****dp,****dp+2*256*256*2*2,false);
            dp[cur][0][0][0][0] = true;
            
            for(int j = 0; j < N;j++){
                for(int k = 0; k < 256; k++){
                    for(int l = 0; l < 256; l++){
                        for(int m = 0; m < 2;m++){
                            for(int n = 0; n < 2;n++){
                                if(!dp[cur][k][l][m][n])continue;
                                dp[next][k][l][m][n] = true;
                                if(i!=j){
                                    dp[next][k^strength[j]][l][1][n] = true;
                                    dp[next][k][l^strength[j]][m][1] = true;
                                }
                                dp[cur][k][l][m][n] = false;
                                
                                if(j==N-1 && m && n){
                                    res = max(res,k+l+(XOR^k^l));
                                }
                            }
                        }
                    }
                }
                swap(cur,next);
            }
        }
        
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { int Arr0[] = {2,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(0, Arg1, get(Arg0)); }
    void test_case_1() { int Arr0[] = {7,3,5,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 17; verify_case(1, Arg1, get(Arg0)); }
    void test_case_2() { int Arr0[] = {13,13,13,13,13,13,13,13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; verify_case(2, Arg1, get(Arg0)); }
    void test_case_3() { int Arr0[] = {114,51,4,191,9,81,0,89,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 470; verify_case(3, Arg1, get(Arg0)); }
    void test_case_4() { int Arr0[] = {108,66,45,82,163,30,83,244,200,216,241,249,89,128,36,28,250,190,70,95,117,196,19,160,255,129,10,109,189,24,22,25,134,144,110,15,235,205,186,103,116,191,119,183,45,217,156,44,97,197}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 567; verify_case(4, Arg1, get(Arg0)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    TrySail ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
