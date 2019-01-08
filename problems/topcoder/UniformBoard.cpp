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
class UniformBoard {
public:
    int getBoard(vector <string> board, int K) {
        int res = 0;
        int cntA = 0;
        bool canmove = false;
        for(auto vec:board) for(auto c:vec){ cntA += c=='A'; if(c=='.') canmove = true; }
        
        int n = (int)board.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n;j++){
                for(int k = i; k < n;k++){
                    for(int l = j; l < n;l++){
                        
                        if((k-i+1)*(l-j+1)>cntA) break;
                        
                        int C = 0;
                        for(int u = i; u <= k; u++){
                            for(int v = j; v <= l; v++){
                                if(board[u][v] == 'A') continue;
                                if(board[u][v] == 'P') { if(canmove) C+=2; else C = INF; }
                                if(board[u][v] == '.') { C++; }
                            }
                        }
                        if(C <= K) res = max(res,(k-i+1)*(l-j+1));
                    }
                }
            }
        }
        
        return res;
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"AP",
        ".A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, getBoard(Arg0, Arg1)); }
    void test_case_1() { string Arr0[] = {"AP",
        ".A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, getBoard(Arg0, Arg1)); }
    void test_case_2() { string Arr0[] = {"PPP",
        "APA",
        "A.P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(2, Arg2, getBoard(Arg0, Arg1)); }
    void test_case_3() { string Arr0[] = {"AAA",
        "PPP",
        "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 3; verify_case(3, Arg2, getBoard(Arg0, Arg1)); }
    void test_case_4() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 0; verify_case(4, Arg2, getBoard(Arg0, Arg1)); }
    void test_case_5() { string Arr0[] = {"PPAAPA..AP",
        "PPA.APAP..",
        "..P.AA.PPP",
        "P.P..APAA.",
        "P.P..P.APA",
        "PPA..AP.AA",
        "APP..AAPAA",
        "P.P.AP...P",
        ".P.A.PAPPA",
        "..PAPAP..P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 15; verify_case(5, Arg2, getBoard(Arg0, Arg1)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    UniformBoard ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
