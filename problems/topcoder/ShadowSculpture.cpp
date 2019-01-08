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

int state[10][10][10];
int g[10][10][10];
int test[10][10][10];

class ShadowSculpture {
public:
    
    void rec(int x,int y,int z,int n,int group){
        if(g[x][y][z]!=-1) return;
        if(state[x][y][z]) return;
        g[x][y][z] = group;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                for(int k = -1; k <= 1; k++){
                    if(abs(i)+abs(j)+abs(k)!=1) continue;
                    int nx = x + i;
                    int ny = y + j;
                    int nz = z + k;
                    if(nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= n || nz >= n) continue;
                    rec(nx,ny,nz,n,group);
                }
            }
        }
    }
    bool check(int n,vector <string>& XY, vector <string>& YZ, vector <string>& ZX){
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                int cnt = 0;
                for(int k = 0; k < n;k++){ cnt += test[i][j][k]==0; }
                if(XY[i][j] == 'Y' && !cnt) return false;
                if(XY[i][j] == 'N' && cnt) return false;
            }
        }
   
        for(int j = 0; j < n;j++){
            for(int k = 0;k < n;k++){
                int cnt = 0;
                for(int i = 0; i < n;i++){
                    cnt+=test[i][j][k]==0;
                }
                if(YZ[j][k] == 'Y' && !cnt) return false;
                if(YZ[j][k] == 'N' && cnt) return false;
            }
        }
        
        for(int k = 0;k < n;k++){
            for(int i = 0; i < n;i++){
                int cnt = 0;
                for(int j = 0; j < n;j++){
                    cnt += test[i][j][k]==0;
                }
                if(ZX[k][i] == 'Y' && !cnt) return false;
                if(ZX[k][i] == 'N' && cnt) return false;
            }
        }
        return true;
    }
    
    string possible(vector <string> XY, vector <string> YZ, vector <string> ZX) {
        int n = (int)XY.size();
        
        fill(**state,**state+1000,0);
        fill(**g,**g+1000,-1);
        
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                if(XY[i][j] == 'N'){
                    for(int k = 0; k < n;k++){
                        state[i][j][k] = 1;
                    }
                }
            }
        }
        
        for(int j = 0; j < n;j++){
            for(int k = 0;k < n;k++){
                if(YZ[j][k] == 'N'){
                    for(int i = 0; i < n;i++){
                        state[i][j][k] = 1;
                    }
                }
            }
        }
        
        for(int k = 0;k < n;k++){
            for(int i = 0; i < n;i++){
                if(ZX[k][i] == 'N'){
                    for(int j = 0; j < n;j++){
                        state[i][j][k] = 1;
                    }
                }
            }
        }
        
        // ===
        
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                int cnt = 0;
                for(int k = 0; k < n;k++){
                    cnt += state[i][j][k]==0;
                }
                if(XY[i][j] == 'Y' && !cnt) return "Impossible";
            }
        }
        
        for(int j = 0; j < n;j++){
            for(int k = 0;k < n;k++){
                int cnt = 0;
                for(int i = 0; i < n;i++){
                    cnt+=state[i][j][k]==0;
                }
                if(YZ[j][k] == 'Y' && !cnt) return "Impossible";
            }
        }
        
        for(int k = 0;k < n;k++){
            for(int i = 0; i < n;i++){
                int cnt = 0;
                for(int j = 0; j < n;j++){
                    cnt += state[i][j][k]==0;
                }
                if(ZX[k][i] == 'Y' && !cnt) return "Impossible";
            }
        }
        
        // ===
        
        int group = 0;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                for(int k = 0; k < n;k++){
                    if(state[i][j][k]==0){
                        if(g[i][j][k]!=-1)continue;
                        rec(i,j,k,n,group++);
                    }
                }
            }
        }
        if(group == 0) return "Possible";
        
        for(int _g = 0; _g < group; _g++){
            fill(**test,**test+1000,0);
            for(int i = 0; i < n;i++){
                for(int j = 0; j < n;j++){
                    for(int k = 0; k < n;k++){
                        test[i][j][k] = g[i][j][k]!=_g;
                    }
                }
            }
            if(check(n,XY,YZ,ZX)) return "Possible";
        }
        
        return "Impossible";
    }
    
    
    // BEGIN CUT HERE
public:
    void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
    template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
    void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
    void test_case_0() { string Arr0[] = {"YN","NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN","NN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","NN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(0, Arg3, possible(Arg0, Arg1, Arg2)); }
    void test_case_1() { string Arr0[] = {"YN","NY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YN","NY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YN","NY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(1, Arg3, possible(Arg0, Arg1, Arg2)); }
    void test_case_2() { string Arr0[] = {"YYY","YNY","YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"YYY","YNY","YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYY","YNY","YYY"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(2, Arg3, possible(Arg0, Arg1, Arg2)); }
    void test_case_3() { string Arr0[] = {"YYY","YNY","YYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYY","YNY","YYY"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"YYY","YNY","YYN"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Impossible"; verify_case(3, Arg3, possible(Arg0, Arg1, Arg2)); }
    void test_case_4() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"N"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"N"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Possible"; verify_case(4, Arg3, possible(Arg0, Arg1, Arg2)); }
    
    // END CUT HERE
    
    
};

// BEGIN CUT HERE
//int main(){
//    ShadowSculpture ___test;
//    ___test.run_test(-1);
//    return 0;
//}
// END CUT HERE
