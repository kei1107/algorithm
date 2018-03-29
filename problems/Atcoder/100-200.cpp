#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LINF = 1e18;
template<class S,class T> ostream &operator << (ostream& out,const pair<S,T>& o){
    out << "(" << o.first << "," << o.second << ")"; return out;
}
/*
 Atcoder 100~200点代
 全部まとめる
*/
// https://abc042.contest.atcoder.jp/tasks/abc042_a
//void solve(){ ll A,B,C; cin >> A >> B >> C; if(A == 5 && B == 5 && C == 7){ cout << "YES" << endl; return;} if(A == 5 && B == 7 && C == 5){ cout << "YES" << endl; return;} if(A == 7 && B == 5 && C == 5){ cout << "YES" << endl; return;} cout << "NO" << endl; return ; }
// https://abc043.contest.atcoder.jp/tasks/abc043_a
//void solve(){ ll N; cin >> N; cout << N*(N+1)/2 << endl; }
// https://abc044.contest.atcoder.jp/tasks/abc044_a
//void solve(){ll N,K,X,Y;cin>>N>>K>>X>>Y; cout<<X*min(N,K)+Y*max(0LL,N-K)<<endl;}
// https://abc045.contest.atcoder.jp/tasks/abc045_a
//void solve(){ll a,b,h;cin>>a>>b>>h;cout<<(a+b)*h/2<<endl;}
// https://abc046.contest.atcoder.jp/tasks/abc046_a
//void solve(){ ll a,b,c; cin >> a >> b >> c; set<ll> s; s.insert(a); s.insert(b); s.insert(c); cout << s.size() << endl; }
// https://abc047.contest.atcoder.jp/tasks/abc047_a
//void solve(){ll a,b,c;cin>>a>>b>>c;if(a==b+c||b==a+c||c==a+b)cout<<"Yes"<<endl;else cout<<"No"<<endl;}
// https://abc048.contest.atcoder.jp/tasks/abc048_a
//void solve(){string s1,s2,s3;cin>>s1>>s2>>s3;cout<<"A"<<s2[0]<<"C"<<endl;}
// https://abc049.contest.atcoder.jp/tasks/abc049_a
//void solve(){char c;cin>>c;string s="aiueo";if(s.find(c)!=string::npos)cout<<"vowel"<<endl;else cout<<"consonant"<<endl;}
// https://abc050.contest.atcoder.jp/tasks/abc050_a
//void solve(){ll A,B;char op;cin>>A>>op>>B;if(op=='+')cout<<A+B<<endl;else cout<<A-B<<endl;}
// https://abc051.contest.atcoder.jp/tasks/abc051_a
//void solve(){string s;cin>> s;cout<<s.substr(0,5)<<" "<<s.substr(6,7)<<" "<<s.substr(14)<<endl;}
// https://abc052.contest.atcoder.jp/tasks/abc052_a
//void solve(){ll A,B,C,D;cin>>A>>B>>C>>D;cout<<max(A*B,C*D)<<endl;}
// https://abc053.contest.atcoder.jp/tasks/abc053_a
//void solve(){ll x;cin>>x;cout<<(x<1200?"ABC":"ARC")<<endl;}
// https://abc054.contest.atcoder.jp/tasks/abc054_a
//void solve(){ll A,B;cin>>A>>B;if(A==1)A=14;if(B==1)B=14;cout<<(A>B?"Alice":(A==B?"Draw":"Bob"))<<endl;}
// https://abc055.contest.atcoder.jp/tasks/abc055_a
//void solve(){ll N;cin>>N;cout<<800*N-200*(N/15)<<endl;}
// https://abc056.contest.atcoder.jp/tasks/abc056_a
//void solve(){char a,b;cin>>a>>b;if(a=='H')cout<<b<<endl;else if(b=='H')cout<<'D'<<endl;else cout<<'H'<<endl;}
// https://abc057.contest.atcoder.jp/tasks/abc057_a
//void solve(){ll A,B;cin>>A>>B;cout<<(A+B)%24<<endl;}
// https://abc058.contest.atcoder.jp/tasks/abc058_a
//void solve(){ll a,b,c;cin>>a>>b>>c;cout<<(b-a==c-b?"YES":"NO")<<endl;}
// https://abc059.contest.atcoder.jp/tasks/abc059_a
//void solve(){string s1,s2,s3;cin>>s1>>s2>>s3;cout<<(char)toupper(s1[0])<<(char)toupper(s2[0])<<(char)toupper(s3[0])<<endl;}
// https://abc060.contest.atcoder.jp/tasks/abc060_a
//void solve(){string A,B,C;cin>>A>>B>>C;cout<<(A[A.length()-1]==B[0]&&B[B.length()-1]==C[0]?"YES":"NO")<<endl;}
// https://abc061.contest.atcoder.jp/tasks/abc061_a
//void solve(){ll A,B,C;cin>>A>>B>>C;cout<<(C>=A&&C<=B?"Yes":"No")<<endl;}
// https://abc062.contest.atcoder.jp/tasks/abc062_a
//void solve(){ll x,y;cin>>x>>y;vector<vector<ll>> g={{1,3,5,7,8,10,12},{4,6,9,11},{2}}; ll gx,gy; for(int i=0;i<3;i++)for(auto v:g[i]){if(v==x) gx=i;if(v==y)gy=i;}cout<<(gx==gy?"Yes":"No")<<endl;}
// https://abc063.contest.atcoder.jp/tasks/abc063_a
//void solve(){ll A,B;cin>>A>>B;cout<<(A+B>=10?"error":to_string(A+B))<<endl;}
// https://abc064.contest.atcoder.jp/tasks/abc064_a
//void solve(){ll r,g,b;cin>>r>>g>>b;cout<<((100*r+10*g+b)%4==0?"YES":"NO")<<endl;}
// https://abc065.contest.atcoder.jp/tasks/abc065_a
//void solve(){ll X,A,B;cin>>X>>A>>B;cout<<(A>=B?"delicious":(X+A>=B?"safe":"dangerous"))<<endl;}
// https://abc066.contest.atcoder.jp/tasks/abc066_a
//void solve(){ll a,b,c;cin>>a>>b>>c;cout<<min({a+b,b+c,c+a})<<endl;}
// https://abc067.contest.atcoder.jp/tasks/abc067_a
//void solve(){ll A,B;cin>>A>>B;cout<<(A%3==0||B%3==0||(A+B)%3==0?"Possible":"Impossible")<<endl;}
// https://abc068.contest.atcoder.jp/tasks/abc068_a
//void solve(){ll N;cin>>N;cout<<"ABC"<<N<<endl;}
// https://abc069.contest.atcoder.jp/tasks/abc069_a
//void solve(){ll n,m;cin>>n>>m;cout<<(n-1)*(m-1)<<endl;}
// https://abc070.contest.atcoder.jp/tasks/abc070_a
//void solve(){ll N;cin>>N;cout<<(to_string(N)[0]==to_string(N)[2]?"Yes":"No")<<endl;}
// https://abc071.contest.atcoder.jp/tasks/abc071_a
//void solve(){ll x,a,b;cin>>x>>a>>b;cout<<(abs(x-a)<abs(x-b)?"A":"B")<<endl;}
// https://abc072.contest.atcoder.jp/tasks/abc072_a
//void solve(){ll X,t;cin>>X>>t;cout<<max(0LL,X-t)<<endl;}
// https://abc073.contest.atcoder.jp/tasks/abc073_a
//void solve(){ll N;cin>>N;cout<<(to_string(N).find('9')!=string::npos?"Yes":"No")<<endl;}
// https://abc074.contest.atcoder.jp/tasks/abc074_a
//void solve(){ll N,A;cin>>N>>A;cout<<N*N-A<<endl;}
// https://abc075.contest.atcoder.jp/tasks/abc075_a
//void solve(){ll A,B,C;cin>>A>>B>>C;cout<<(A==B?C:(B==C)?A:B)<<endl;}
// https://abc076.contest.atcoder.jp/tasks/abc076_a
//void solve(){ll R,G;cin>>R>>G;cout<<2*G-R<<endl;}
// https://abc077.contest.atcoder.jp/tasks/abc077_a
//void solve(){char C[2][3];for(int i=0;i<2;i++)for(int j=0;j<3;j++)cin>>C[i][j];for(int i=0;i<3;i++)if(C[0][i]!=C[1][2-i]){cout<<"NO"<<endl;return;}cout<<"YES"<<endl;}
// https://abc078.contest.atcoder.jp/tasks/abc078_a
//void solve(){string A,B;cin>>A>>B;ll a=stoi(A,nullptr,16),b=stoi(B,nullptr,16); cout<<(a>b?">":(a==b?"=":"<"))<<endl;}
// https://abc079.contest.atcoder.jp/tasks/abc079_a
//void solve(){ll N;cin>>N;string S=to_string(N);cout<<((S[0]==S[1]&&S[1]==S[2]&&S[2]==S[0])||(S[1]==S[2]&&S[2]==S[3]&&S[3]==S[1])?"Yes":"No")<<endl;}
// https://abc080.contest.atcoder.jp/tasks/abc080_a
//void solve(){ll N,A,B;cin>>N>>A>>B;cout<<min(A*N,B)<<endl;}
// https://abc081.contest.atcoder.jp/tasks/abc081_a
//void solve(){string s;cin>>s;int ans=0;for(auto c:s)if(c=='1')ans++;cout<<ans<<endl;}
// https://abc082.contest.atcoder.jp/tasks/abc082_a
//void solve(){ll a,b;cin>>a>>b;cout<<int((double)(a+b)/2.0 + 0.5)<<endl;}
// https://abc083.contest.atcoder.jp/tasks/abc083_a
//void solve(){ll A,B,C,D;cin>>A>>B>>C>>D;ll L=A+B,R=C+D;cout<<(L>R?"Left":(L==R)?"Balanced":"Right")<<endl;}
// https://abc084.contest.atcoder.jp/tasks/abc084_a
//void solve(){ll M;cin>>M;cout<<48-M<<endl;}
// https://abc085.contest.atcoder.jp/tasks/abc085_a
//void solve(){string S;cin>>S;S[3]='8';cout<<S<<endl;}
// https://abc086.contest.atcoder.jp/tasks/abc086_a
//void solve(){ll a,b;cin>>a>>b;cout<<(a*b&1?"Odd":"Even")<<endl;}
// https://abc087.contest.atcoder.jp/tasks/abc087_a
//void solve(){ll X,A,B;cin>>X>>A>>B;cout<<(X-A)-(X-A)/B*B<<endl;}
// https://abc088.contest.atcoder.jp/tasks/abc088_a
//void solve(){ll N,A;cin>>N>>A;cout<<(N%500<=A?"Yes":"No")<<endl;}
// https://abc089.contest.atcoder.jp/tasks/abc089_a
//void solve(){ll N;cin>>N;cout<<N/3<<endl;}
// https://abc090.contest.atcoder.jp/tasks/abc090_a
//void solve(){char c[3][3];for(int i = 0;i<3;i++)for(int j = 0;j<3;j++)cin>>c[i][j];cout<<c[0][0]<<c[1][1]<<c[2][2]<<endl;}
// https://abc091.contest.atcoder.jp/tasks/abc091_a
//void solve(){ll A,B,C;cin>>A>>B>>C;cout<<(A+B>=C?"Yes":"No")<<endl;}
// https://abc092.contest.atcoder.jp/tasks/abc092_a
// void solve(){ ll A,B,C,D; cin >> A >> B >> C >> D; cout << min(A,B)+min(C,D)<<endl;}
// https://apc001.contest.atcoder.jp/tasks/apc001_a
//void solve(){ll X,Y;cin>>X>>Y;cout<<(X%Y==0?-1:X*(Y-1))<<endl;}
// https://cf16-final-open.contest.atcoder.jp/tasks/codefestival_2016_final_a
//void solve(){ll H,W;cin>>H>>W;string S;for(int i = 0; i < H;i++)for(int j = 0; j < W;j++){cin>>S;if(S=="snuke")cout<<(char)('A'+j)<<i+1<<endl;}}
// https://code-festival-2016-quala.contest.atcoder.jp/tasks/codefestival_2016_qualA_a
//void solve(){string s;cin>>s;cout<<s.substr(0,4)<<" "<<s.substr(4)<<endl;}
// https://code-festival-2016-qualb.contest.atcoder.jp/tasks/codefestival_2016_qualB_a
//void solve(){string S;cin>>S;string s="CODEFESTIVAL2016";int ans = 0;for(int i=0;i<16;i++)if(S[i]!=s[i])ans++;cout<<ans<<endl;}
// https://code-festival-2016-qualc.contest.atcoder.jp/tasks/codefestival_2016_qualC_a
//void solve(){string s;cin>>s;bool f=false;for(int i = 0; i < s.length();i++) if(!f){if(s[i]=='C')f=true;}else{if(s[i]=='F'){cout<<"Yes"<<endl;return;}}cout<<"No"<<endl;}
// https://code-festival-2017-quala.contest.atcoder.jp/tasks/code_festival_2017_quala_a
//void solve(){string S;cin>>S;cout<<(S.substr(0,4)=="YAKI"?"Yes":"No")<<endl;}
// https://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_a
//void solve(){string S;cin>>S;cout<<S.substr(0,S.length()-8)<<endl;}
// https://code-festival-2017-qualc.contest.atcoder.jp/tasks/code_festival_2017_qualc_a
//void solve(){string S;cin>>S;for(int i = 0;i<S.length()-1;i++)if(S[i]=='A'&&S[i+1]=='C'){cout<< "Yes"<<endl; return;}cout<<"No"<<endl;}
// https://code-thanks-festival-2017-open.contest.atcoder.jp/tasks/code_thanks_festival_2017_a
//void solve(){ll t[8];for(int i = 0; i < 8;i++) cin >> t[i];cout<<*max_element(t,t+8)<<endl;}
// https://colopl2018-qual.contest.atcoder.jp/tasks/colopl2018_qual_a
//void solve(){ll A,B;cin>>A>>B;string S;cin>>S;cout<<(A<=S.length()&&S.length()<=B?"YES":"NO")<<endl;}
// https://ddcc2016-qual.contest.atcoder.jp/tasks/ddcc_2016_qual_a
//void solve(){double A,B,C;cin>>A>>B>>C;cout<<fixed<<setprecision(12)<<(B/A)*C<<endl;}
// https://ddcc2017-qual.contest.atcoder.jp/tasks/ddcc2017_qual_a
//void solve(){string S;cin>>S;cout<<(S[0]==S[1]&&S[1]!=S[2]&&S[2]==S[3]?"Yes":"No")<<endl;}
// https://soundhound2018.contest.atcoder.jp/tasks/soundhound2018_a
//void solve(){string X,Y;cin>>X>>Y;cout<<(X[0]=='S'&&Y[0]=='H'?"YES":"NO")<<endl;}
// https://tenka1-2017-beginner.contest.atcoder.jp/tasks/tenka1_2017_a
//void solve(){string S;cin>>S;int ans=0;for(int i=0;i<6;i++)if(S[i]=='1')ans++;cout<<ans<<endl;}
// https://yahoo-procon2018-qual.contest.atcoder.jp/tasks/yahoo_procon2018_qual_a
//void solve(){string S;cin>>S;cout<<(S.substr(0,3)=="yah"&&S[3]==S[4]?"YES":"NO")<<endl;}
// https://yahoo-procon2017-qual.contest.atcoder.jp/tasks/yahoo_procon2017_qual_a
//void solve(){string S,yahoo="yahoo";cin>>S;vector<int> a(5);iota(a.begin(),a.end(),0);do{string s;for(int i = 0; i < 5;i++)s+=yahoo[a[i]];if(s==S){cout << "YES"<<endl;return;}}while(next_permutation(a.begin(),a.end()));cout<<"NO"<<endl;}
// https://tenka1-2016-quala.contest.atcoder.jp/tasks/tenka1_2016_qualA_a
//void solve(){ll ans=0;for(int i=1;i<=100;i++)if(i%3!=0&&i%5!=0)ans+=i;cout<<ans<<endl;}
// https://tenka1-2016-qualb.contest.atcoder.jp/tasks/tenka1_2016_qualB_a
//void solve(){int n=3,ans=20;;while(n--){ans=(ans*ans+4)/8;}cout<<ans<<endl;}
// https://dwacon2017-prelims.contest.atcoder.jp/tasks/dwango2017qual_a
//void solve(){ll n,a,b;cin>>n>>a>>b;cout<<max(0LL,a+b-n)<<endl;}
// https://dwacon2018-prelims.contest.atcoder.jp/tasks/dwacon2018_prelims_a
//void solve(){string s;cin>>s;cout<<(s[0]==s[2]&&s[1]==s[3]?"Yes":"No")<<endl;}



/*
 *************************************************************************
 *************************** ここから　200 *********************************
 *************************************************************************
*/



// https://abc042.contest.atcoder.jp/tasks/abc042_b
//void solve(){ll N,L;cin>>N>>L;vector<string>S(N);for(auto&in:S)cin>>in;sort(S.begin(),S.end());for(auto s:S)cout<<s;cout<<endl;}
// https://abc043.contest.atcoder.jp/tasks/abc043_b
//void solve(){string s;cin>>s;stack<char> st;for(auto c:s)if(c=='B'){if(st.size()!=0)st.pop();}else st.push(c);string ans;while(st.size()){ans+=st.top();st.pop();}reverse(ans.begin(),ans.end());cout<<ans<<endl;}
// https://abc044.contest.atcoder.jp/tasks/abc044_b
//void solve(){string w;cin>>w;map<char,int> mp;for(auto c:w)mp[c]++;for(auto v:mp)if(v.second&1){cout<<"No"<<endl;return;}cout<<"Yes"<<endl;}
// https://abc045.contest.atcoder.jp/tasks/abc045_b
//void solve(){string S[3];int c[3]={};int at=0; cin>>S[0]>>S[1]>>S[2];do{if(c[at]==S[at].length()){if(at == 0){cout<<"A";}else if(at == 1){ cout << "B"; }else { cout << "C";}cout << endl; return;}char s = S[at][c[at]];if (s == 'a'){c[at]++;at = 0;}else if(s == 'b'){c[at]++;at = 1;}else if(s == 'c'){c[at]++;at = 2;}} while (1);}
// https://abc046.contest.atcoder.jp/tasks/abc046_b
//void solve(){ll N,K;cin>>N>>K;cout<<fixed<<K*(ll)pow(K-1,N-1)<<endl;}
// https://abc047.contest.atcoder.jp/tasks/abc047_b
//void solve(){ int W, H, N; cin >> W >> H >> N; vector<vector<int>>v(H+1,vector<int>(W+1));
//    for (int i = 0; i < N;i++){int x, y, a; cin >> x >> y >> a;
//        if (a == 1) for (int j = 1; j <= x;j++)for (int k = 1; k <= H;k++)v[k][j] = true;
//        if (a == 2) for (int j = x + 1; j <= W;j++)for (int k = 1; k <= H;k++) v[k][j] = true;
//        if (a == 3) for (int j = 1; j <= y;j++) for (int k = 1; k <= W;k++) v[j][k] = true;
//        if (a == 4) for (int j = y + 1; j <= H;j++) for (int k = 1; k <= W;k++) v[j][k] = true;
//    }
//    int Ans = 0; for (int i = 1; i <= H;i++)for (int j = 1; j <= W;j++)if(!v[i][j])Ans++; cout << Ans << endl;
//}
// https://abc048.contest.atcoder.jp/tasks/abc048_b
//void solve(){ll a,b,x;cin>>a>>b>>x; if(a==0)cout<<b/x+1<<endl;else cout<<b/x-(a-1)/x<<endl;}
// https://abc049.contest.atcoder.jp/tasks/abc049_b
//void solve(){ll H,W;cin>>H>>W;vector<string> S(H);for(auto&in:S)cin>>in;for(auto s:S)cout<<s<<endl<<s<<endl;}
// https://abc050.contest.atcoder.jp/tasks/abc050_b
//void solve(){ll N;cin>>N;vector<ll>T(N);for(auto&in:T)cin>>in;ll sum=accumulate(T.begin(),T.end(),0LL);ll M;cin>>M;for(int i = 0; i < M;i++){ll P,X;cin>>P>>X;cout<<sum-T[P-1]+X<<endl;}}
// https://abc051.contest.atcoder.jp/tasks/abc051_b
//void solve(){ll K,S;cin>>K>>S;int ans=0;for(int x=0;x<=K;x++)for(int y=0;y<=K;y++)if(S-x-y>=0&&S-x-y<=K)ans++;cout<<ans<<endl;}
// https://abc052.contest.atcoder.jp/tasks/abc052_b
//void solve(){ll N;string S;cin>>N>>S;int x=0,ans=0;for(auto c:S)if(c=='I')ans=max(ans,++x); else x--;cout<<ans<<endl;}
// https://abc053.contest.atcoder.jp/tasks/abc053_b
//void solve(){string s;cin>>s;cout<<s.rfind('Z')-s.find('A')+1<<endl;}
// https://abc054.contest.atcoder.jp/tasks/abc054_b
//void solve(){ll N,M;cin>>N>>M;vector<string> S(N+M);for(auto&in:S)cin>>in;for(int i=0;i<=N-M;i++)for(int j=0;j<=N-M;j++){auto f=[&]{for(int k=0;k<M;k++)if(S[i+k].substr(j,M)!=S[N+k])return false;return true;}();if(f){cout<<"Yes"<<endl;return;}}cout<<"No"<<endl;}
// https://abc055.contest.atcoder.jp/tasks/abc055_b
//void solve(){ll N;cin>>N;ll MOD=1e9+7;ll fact=1;for(ll i=1;i<=N;i++)fact=fact*i%MOD;cout<<fact<<endl;}
// https://abc056.contest.atcoder.jp/tasks/abc056_b
//void solve(){ll W,a,b;cin>>W>>a>>b;cout<<max(0LL,max(a,b)-min(a,b)-W)<<endl;}
// https://abc057.contest.atcoder.jp/tasks/abc057_b
//void solve(){ll N,M;cin>>N>>M;vector<ll>a(N),b(N),c(M),d(M);vector<vector<ll>>dist(N,vector<ll>(M));for(int i=0;i<N;i++)cin>>a[i]>>b[i];for(int i=0;i<M;i++)cin>>c[i]>>d[i];for(int i=0;i<N;i++)for(int j=0;j<M;j++)dist[i][j]=abs(a[i]-c[j])+abs(b[i]-d[j]);for(int i=0;i<N;i++)cout<<min_element(dist[i].begin(),dist[i].end())-dist[i].begin()+1<<endl;}
// https://abc058.contest.atcoder.jp/tasks/abc058_b
//void solve(){string O,E;cin>>O>>E;for(int i=0;i<O.length();i++){cout<<O[i];if(i<E.length())cout<<E[i];}cout<<endl;}
// https://abc059.contest.atcoder.jp/tasks/abc059_b
//void solve(){string A,B;cin>>A>>B;cout<<(A.length()>B.length()?"GREATER":(A.length()<B.length()?"LESS":(A>B?"GREATER":(A<B?"LESS":"EQUAL"))))<<endl;}
// https://abc060.contest.atcoder.jp/tasks/abc060_b
//void solve(){ll A,B,C;cin>>A>>B>>C;for(int i=0;i<1000;i++)if((B*i+C)%A==0){cout<<"YES"<<endl;return;}cout<<"NO"<<endl;}
// https://abc061.contest.atcoder.jp/tasks/abc061_b
//void solve(){ll N,M;cin>>N>>M;ll a,b;vector<ll> c(N);for(int i=0;i<M;i++){cin>>a>>b;c[a-1]++;c[b-1]++;}for(auto v:c)cout<<v<<endl;}
// https://abc062.contest.atcoder.jp/tasks/abc062_b
//void solve(){ll H,W;cin>>H>>W;vector<string>a(H);for(auto&in:a)cin>>in;cout<<string(W+2,'#')<<endl;for(auto s:a)cout<<"#"<<s<<"#"<<endl;cout<<string(W+2,'#')<<endl;}
// https://abc063.contest.atcoder.jp/tasks/abc063_b
//void solve(){string S;cin>>S;sort(S.begin(),S.end());ll l=S.length();S.erase(unique(S.begin(),S.end()),S.end());cout<<(l==S.length()?"yes":"no")<<endl;}
// https://abc064.contest.atcoder.jp/tasks/abc064_b
//void solve(){ll N;cin>>N;vector<ll>a(N);for(auto&in:a)cin>>in;cout<<*max_element(a.begin(),a.end())-*min_element(a.begin(),a.end())<<endl;}
// https://abc065.contest.atcoder.jp/tasks/abc065_b
//void solve(){ll N;cin>>N;vector<ll>a(N);for(auto&in:a)cin>>in;int n=1;for(int i=0;i<=N;i++){n=a[n-1];if(n==2){cout<<i+1<<endl;return;}}cout<<-1<<endl;}
// https://abc066.contest.atcoder.jp/tasks/abc066_b
//void solve(){string S;cin>>S;for(int i=(int)S.length()-2;i>=0;i--){if(i%2==0)continue;bool f=true;for(int j=0;j<=i/2;j++)if(S[j]!=S[j+(i+1)/2]){f=false;break;}if(f){cout<<i+1<<endl;break;}}}
// https://abc067.contest.atcoder.jp/tasks/abc067_b
//void solve(){ll N,K;cin>>N>>K;vector<ll>l(N);for(auto&in:l)cin>>in;sort(l.begin(),l.end(),greater<ll>());cout<<accumulate(l.begin(),l.begin()+K,0LL)<<endl;}
// https://abc068.contest.atcoder.jp/tasks/abc068_b
//void solve(){ll N;cin>>N;ll n=1;while(n*2<=N)n<<=1;cout<<n<<endl;}
// https://abc069.contest.atcoder.jp/tasks/abc069_b
// void solve(){string s;cin>>s;cout<<s[0]<<s.length()-2<<s[s.length()-1]<<endl;}
// https://abc070.contest.atcoder.jp/tasks/abc070_b
//void solve(){ll A,B,C,D;cin>>A>>B>>C>>D;cout<<max(0LL,min(B,D)-max(A,C))<<endl;}
// https://abc071.contest.atcoder.jp/tasks/aSbc071_b
//void solve(){string S;cin>>S;for(int i=0;i<26;i++)if(S.find(i+'a')==string::npos){cout<<(char)(i+'a')<<endl;return;}cout<<"None"<<endl;}
// https://abc072.contest.atcoder.jp/tasks/abc072_b
//void solve(){string s;cin>>s;for(int i=0;i<s.length();i+=2)cout<<s[i];cout<<endl;}
// https://abc073.contest.atcoder.jp/tasks/abc073_b
//void solve(){ll sum=0;ll N;cin>>N;for(int i=0;i<N;i++){ll l,r;cin>>l>>r;sum+=r-l+1;}cout<<sum<<endl;}
// https://abc074.contest.atcoder.jp/tasks/abc074_b
//void solve(){ll N,K;cin>>N>>K;ll ans=0;for(int i=1;i<=N;i++){ll x;cin>>x;ans+=min(2*abs(x),2*abs(K-x));}cout<<ans<<endl;}
// https://abc075.contest.atcoder.jp/tasks/abc075_b
//void solve(){ int H,W; cin >> H >>W; vector<vector<char>> m(H+2,vector<char>(W+2,'@')); for(int i = 1; i <= H;++i)for(int j =1 ; j<=W;j++)cin>>m[i][j]; int dx[8] = {0,1,1,1,0,-1,-1,-1},dy[8] = {-1,-1,0,1,1,1,0,-1}; vector<vector<int>> v(H+2,vector<int>(W+2,-1));for(int i = 1; i <= H;++i)for(int j =1 ; j<=W;j++){if(m[i][j]=='#')continue; int cnt=0;for(int k=0;k < 8;k++){int nx = i+dx[k],ny=j+dy[k];if(m[nx][ny]=='#')cnt++;}v[i][j]=cnt;}for(int i = 1; i <= H;++i){for(int j =1 ; j<=W;j++){if(v[i][j]==-1)cout<<'#';else cout<<v[i][j];}cout<<endl;}}
// https://abc076.contest.atcoder.jp/tasks/abc076_b
//void solve(){ll N,K;cin>>N>>K;ll x=1;for(int i=0;i<N;i++)x=min(2*x,x+K);cout<<x<<endl;}
// https://abc077.contest.atcoder.jp/tasks/abc077_b
//void solve(){ll N;cin>>N;ll x=1;while((x+1)*(x+1)<=N)x++;cout<<x*x<<endl;}
// https://abc078.contest.atcoder.jp/tasks/abc078_b
//void solve(){ll X,Y,Z;cin>>X>>Y>>Z;ll cnt=1;while(Y+2*Z+cnt*(Y+Z)<=X)cnt++;cout<<cnt<<endl;}
// https://abc079.contest.atcoder.jp/tasks/abc079_b
//void solve(){ll N;cin>>N;vector<ll>L(N+1);L[0]=2;L[1]=1;for(int i=2;i<=N;i++)L[i]=L[i-1]+L[i-2];cout<<L[N]<<endl;}
// https://abc080.contest.atcoder.jp/tasks/abc080_b
//void solve(){ll N;cin>>N;ll sum=0;for(auto c:to_string(N))sum+=c-'0';cout<<(N%sum==0?"Yes":"No")<<endl;}
// https://abc081.contest.atcoder.jp/tasks/abc081_b
//void solve(){ll N;cin>>N;vector<ll>A(N);for(auto&in:A)cin>>in;ll cnt=0;while(true){bool f=true;for(auto&v:A)if(v%2==1)f=false;if(!f)break;for(auto&v:A)v/=2;cnt++;}cout<<cnt<<endl;}
// https://abc082.contest.atcoder.jp/tasks/abc082_b
//void solve(){string s,t;cin>>s>>t;sort(s.begin(),s.end());sort(t.begin(),t.end(),greater<char>());cout<<(s<t?"Yes":"No")<<endl;}
// https://abc083.contest.atcoder.jp/tasks/abc083_b
//void solve(){ll N,A,B;cin>>N>>A>>B;ll ans=0;for(int i=1;i<=N;i++){string s=to_string(i);ll sum=accumulate(s.begin(),s.end(),0LL);sum-=s.length()*'0';if(sum>=A&&sum<=B)ans+=i;}cout<<ans<<endl;}
// https://abc084.contest.atcoder.jp/tasks/abc084_b
//void solve(){ll A,B;cin>>A>>B;string S;cin>>S;for(int i=0;i<A;i++)if(!isdigit(S[i])){cout<<"No"<<endl;return;}if(S[A]!='-'){cout<<"No"<<endl;return;}for(int i=A+1;i<A+B+1;i++)if(!isdigit(S[i])){cout<<"No"<<endl;return;}cout<<"Yes"<<endl;}
// https://abc085.contest.atcoder.jp/tasks/abc085_b
//void solve(){ll N;cin>>N;vector<ll>d(N);for(auto&in:d)cin>>in;sort(d.begin(),d.end());d.erase(unique(d.begin(),d.end()),d.end());cout<<d.size()<<endl;}
// https://abc086.contest.atcoder.jp/tasks/abc086_b
//void solve(){ll a,b;cin>>a>>b;string s=to_string(a)+to_string(b);ll x=atoll(s.c_str());cout<<(x==(ll)sqrt(x)*(ll)sqrt(x)?"Yes":"No")<<endl;}
// https://abc087.contest.atcoder.jp/tasks/abc087_b
//void solve(){ll A,B,C,X;cin>>A>>B>>C>>X;ll ans=0;for(int i=0;i<=A;i++)for(int j=0;j<=B;j++)for(int k=0;k<=C;k++)if(500*i+100*j+50*k==X)ans++;cout<<ans<<endl;}
// https://abc088.contest.atcoder.jp/tasks/abc088_b
//void solve(){ll N;cin>>N;vector<ll>a(N);for(auto&in:a)cin>>in;sort(a.begin(),a.end(),greater<ll>());ll A=0,B=0;for(int i=0;i<N;i++)if(i%2)B+=a[i];else A+=a[i];cout<<A-B<<endl;}
// https://abc089.contest.atcoder.jp/tasks/abc089_b
//void solve(){ll N;cin>>N;char c;for(int i=0;i<N;i++){cin>>c;if(c=='Y'){cout<<"Four"<<endl;return;}}cout<<"Three"<<endl;}
// https://abc090.contest.atcoder.jp/tasks/abc090_b
//bool check(string s){for(int i = 0;i<=s.length()/2;i++)if(s[i]!=s[s.length()-1-i])return false;return true;}
//void solve(){ll A,B;cin>>A>>B;ll ans=0;for(ll x=A;x<=B;x++){string s=to_string(x);if(check(s))ans++;}cout<<ans<<endl;}
// https://abc091.contest.atcoder.jp/tasks/abc091_b
//void solve(){set<string> s;map<string,ll> mp1,mp2;ll N,M;cin>>N;for(int i=0;i<N;i++){string str;cin>>str;s.insert(str);mp1[str]++;}cin>>M;for(int j=0;j<M;j++){string str;cin>>str;s.insert(str);mp2[str]++;}ll ans=0;for(auto it:s)ans=max(ans,mp1[it]-mp2[it]);cout<<ans<<endl;}
// https://abc092.contest.atcoder.jp/tasks/abc092_b
void solve(){ll N,D,X;cin>>N>>D>>X;vector<ll>A(N);for(auto& in:A)cin>>in;for(int i = 0; i < N;i++){ X+=(D-1)/A[i]+1;}cout<<X << endl;}
// https://arc059.contest.atcoder.jp/tasks/arc059_a
//void solve(){ll N;cin>>N;vector<ll>a(N);for(auto&in:a)cin>>in;ll ans=INF;ll t=0,ave=accumulate(a.begin(),a.end(),0LL)/N;for(int i=-1;i<=1;i++){t=0;for(auto v:a)t+=(ave+i-v)*(ave+i-v);ans=min(ans,t);}cout<<ans<<endl;}
// https://arc070.contest.atcoder.jp/tasks/arc070_a
//void solve(){ll X; cin >> X; vector<ll> Sum; Sum.push_back(0); int i = 0; while (true) { ll S = Sum[i]; if (S >= X) break;Sum.push_back(S + (++i));}cout<<(i>Sum[i]-X?i:Sum[i]-X)<<endl;}
// https://agc001.contest.atcoder.jp/tasks/agc001_a
//void solve(){ll N;cin>>N;vector<ll>L(2*N);for(auto&in:L)cin>>in;ll ans=0;sort(L.begin(),L.end());for(int i=0;i<2*N;i+=2)ans+=min(L[i],L[i+1]);cout<<ans<<endl;}
// https://agc002.contest.atcoder.jp/tasks/agc002_a
//void solve(){ll a,b;cin>>a>>b;cout<<(a<=0&&b>=0?"Zero":(a>0?"Positive":((b-a+1)%2?"Negative":"Positive")))<<endl;}
// https://agc003.contest.atcoder.jp/tasks/agc003_a
//void solve(){string S;cin>>S;bool s, e, n, w; s = e = n = w = false;for(int i=0;i<S.length();i++){if (S[i] == 'S')s = true; else if (S[i] == 'E') e = true; else if (S[i] == 'N') n = true; else w = true; } if (s == n && e == w)cout << "Yes" << endl; else cout << "No" << endl;}
// https://agc004.contest.atcoder.jp/tasks/agc004_a
//void solve(){ll A,B,C;cin>>A>>B>>C; ll ans = LINF; if ((A % 2 == 0) || (B % 2 == 0) || (C % 2 == 0)) ans = 0; else ans = min({ A*B,B*C,C*A }); cout << ans << endl;}
// https://agc006.contest.atcoder.jp/tasks/agc006_a
//void solve(){ll N;cin>>N;string s,t;cin>>s>>t;ll ans=2*N; for (int i = 0; i < N;i++){if(s[i]!=t[0])continue;bool f = false;for (int j = i; j < N;j++){if (s[j] != t[j - i]) {f = true;break;}}if (f) continue;ans = min(ans, N + i);}cout << ans << endl;}
// https://agc007.contest.atcoder.jp/tasks/agc007_a
//char S[10][10];ll f[10][10]; void solve(){ll N,M;cin>>N>>M;for(int i=0;i<N;i++)cin>>S[i];f[0][0]=1;ll c=0;for(int i=0;i<N;i++)for(int j=0;j<M;j++)if(S[i][j]=='#'){c++;if(i)f[i][j]+=f[i-1][j];if(j)f[i][j]+=f[i][j-1];}if(c!=N+M-1){cout<<"Impossible"<<endl;return;}for(int i=0;i<N;i++)for(int j=0;j<M;j++){if((S[i][j]=='#')^(f[i][j]==1)){cout<<"Impossible"<<endl;return;}}cout<<"Possible"<<endl;}
// https://agc015.contest.atcoder.jp/tasks/agc015_a
//void solve(){ll N,A,B;cin>>N>>A>>B;cout<<(B<A?0:(B==A?1:(N<=1?0:((B-A)*(N-2)+1))))<<endl;}
// https://agc017.contest.atcoder.jp/tasks/agc017_a
//void solve(){ll N,P;cin>>N>>P;vector<ll>A(N);bool f = false;for(auto&in:A){cin>>in;if(in&1)f=true;}cout<<(f?(1LL<<(N-1)):(P==0?(1LL<<N):0))<<endl;}
// https://code-festival-2016-quala.contest.atcoder.jp/tasks/codefestival_2016_qualA_b
//void solve(){ll N;cin>>N;vector<ll>a(N);for(auto&in:a)cin>>in;ll ans=0;for(int i=0;i<N;i++)if(i+1==a[a[i]-1])ans++;cout<<ans/2<<endl;}
// https://code-festival-2016-qualb.contest.atcoder.jp/tasks/codefestival_2016_qualB_b
//void solve(){int N,A,B;cin>>N>>A>>B;string S;cin>>S;int x=0,y=0;for(int i = 0; i <= S.length(); i++) {if (S[i] == 'a') {if (x < A + B) {x++;cout << "Yes" << endl;}else {cout << "No" << endl;}}if (S[i] == 'b') {if (x < A + B&& y < B) {x++;y++;cout << "Yes" << endl;}else {cout << "No" << endl;}}if (S[i] == 'c') {cout << "No" << endl;}}}
// https://code-festival-2016-qualc.contest.atcoder.jp/tasks/codefestival_2016_qualC_b
//void solve(){ll K,T;cin>>K>>T;vector<ll>a(T);for(auto&in:a)cin>>in;ll ans=0;for(int i=0;i<T;i++)ans=max(ans,a[i]-1-K+a[i]);cout<<ans<<endl;}
// https://code-festival-2017-quala.contest.atcoder.jp/tasks/code_festival_2017_quala_b
//void solve(){ll N,M,K;cin>>N>>M>>K;for(int i=0;i<=N;i++)for(int j=0;j<=M;j++)if(i*(M-j)+j*(N-i)==K){cout<<"Yes"<<endl;return;}cout<<"No"<<endl;}
// https://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_b
//void solve(){ll N;cin>>N;map<ll,ll>D;for(int i=0;i<N;i++){ll d;cin>>d;D[d]++;}ll M; cin >> M;vector<ll> T(M);bool f = false;for (int i = 0; i < M;i++) {cin >> T[i];D[T[i]]--;if (D[T[i]] < 0) f = true;}if (f) {cout << "NO" << endl;}else {cout << "YES" << endl;}}
// https://code-festival-2017-qualc.contest.atcoder.jp/tasks/code_festival_2017_qualc_b
//ll N;ll ans = 0;void dfs(ll n, vector<ll>& A,bool f) {if (n == N){if (f)ans++;return;}for (int i = -1; i <= 1;i++) {if ((A[n] + i) % 2 == 0)dfs(n + 1, A, true);else dfs(n + 1, A, f);}}void solve(){cin >> N;vector<ll> A(N);for (int i = 0; i < N;i++) cin >> A[i];dfs(0, A, false);cout << ans << endl;}
// https://code-thanks-festival-2017-open.contest.atcoder.jp/tasks/code_thanks_festival_2017_b
//bool f(string S){for(int i=0;i<=S.length()/2;i++)if(S[i]!=S[S.length()-1-i])return false;return true;}void solve(){string S;cin>>S;ll ans=0;string T;while(true){if(f(S+T))break;T.insert(T.begin(),S[ans++]);if(ans>=S.length())break;}cout<<ans<<endl;}
// https://colopl2018-qual.contest.atcoder.jp/tasks/colopl2018_qual_b
//void solve(){ll N,X;cin>>N>>X;string S;cin>>S;ll ans=0;vector<ll>T(N);for(auto&in:T)cin>>in;for(int i=0;i<N;i++)if(S[i]=='0')ans+=T[i];else ans+=min(T[i],X);cout<<ans<<endl;}
// https://ddcc2016-qual.contest.atcoder.jp/tasks/ddcc_2016_qual_b
//double R,N,M;double f(double y){if(y<0||y>N)return 0;y-=N/2.0;y=y*2*R/N;return 2*sqrt(R*R-y*y);}void solve(){cin>>R>>N>>M;double ans=0;for(int i=1;i<N+M;i++)ans+=max(f(i),f(i-M));cout<<fixed<<setprecision(12)<<ans<<endl;}
// https://ddcc2017-qual.contest.atcoder.jp/tasks/ddcc2017_qual_b
//void solve(){ll Sum=0;ll A,B,C,D;cin>>A>>B>>C>>D;Sum=1728*A+144*B+12*C+D;cout<<Sum<<endl;}
// https://soundhound2018.contest.atcoder.jp/tasks/soundhound2018_b
//void solve(){ll n,L,R;cin>>n>>L>>R;vector<ll> a(n);for(auto& in:a) cin >> in;for(int i = 0; i < n;i++){cout << min(max(L,a[i]),R);if(i != n-1)cout << " ";else cout << endl;}}
// https://tenka1-2017-beginner.contest.atcoder.jp/tasks/tenka1_2017_b
//void solve(){ll N;cin>>N;ll Min=LINF;ll ans=0;for(int i=0;i<N;i++){ll A,B;cin>>A>>B;if(B<Min){Min = B;ans = A + B;}}cout << ans << endl;}
// https://yahoo-procon2018-qual.contest.atcoder.jp/tasks/yahoo_procon2018_qual_b
//void solve(){ll X,K;cin>>X>>K;ll key=pow(10,K);ll ans=X+1;if(ans%key==0)cout << ans << endl; else cout << (ans/key + 1)*key << endl;}
// https://yahoo-procon2017-qual.contest.atcoder.jp/tasks/yahoo_procon2017_qual_b
//void solve(){ll N,K;cin>>N>>K;vector<ll>A(N);for(auto&in:A)cin>>in;sort(A.begin(),A.end());cout<<accumulate(A.begin(),A.begin()+K,0LL)+K*(K-1)/2<<endl;}


// Main function
int main(void) {cin.tie(0); ios::sync_with_stdio(false); solve(); return 0; }
