 #include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
<url:https://www.ioi-jp.org/joi/2008/2009-yo-prob_and_sol/2009-yo-t4/2009-yo-t4.html>
��蕶============================================================
�~�̊���������CJOI���Y�N�͍L��ɂ͂������X�������ėV�Ԃ��Ƃɂ����D
�L��͒����`�ŁC ���������� m �C ��k������ n �C �܂�C m �~ n �̋��ɋ�؂��Ă���D
�܂��C ���X���L����Ɩ�����悪����D JOI���Y�N�́C���̃��[���ɂ��������āC���X������Ȃ�������ړ����邱�Ƃɂ����D
���X������ǂ̋�悩������X������n�߂邱�Ƃ��ł���D
������k�̂����ꂩ�̕����ɗאڂ��C �܂������Ă��Ȃ����X�̂�����Ɉړ��ł���D�ړ�������̋��̔��X�����Ȃ炸����D
JOI���Y�N�����X������Ȃ���ړ��ł����搔�̍ő�l�����߂�v���O�������쐬����D
�������C 1 �� m �� 90�C1 �� n �� 90 �ł���D �^��������̓f�[�^�ł́C �ړ����@��20���ʂ�𒴂��Ȃ��D
=================================================================
���=============================================================
��蕶�ɂ�����悤�Ɉړ����@��20���ʂ�(2*10^6)�𒴂��Ȃ��炵���̂�,�×~�ɐ����グ��
���B�ς̃t���O�Ǘ��z��́A���܂��g���΂P�őS�Ďg���܂킷���Ƃ��\
================================================================
*/
vector<vector<int>> masu;
vector<vector<int>> checked;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
ll dfs(ll x, ll y, ll dep) {
	ll res = dep;
	for (int i = 0; i < 4;i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (masu[nx][ny] == 0) continue;
		if (checked[nx][ny] == 1)continue;
		checked[nx][ny] = 1;
		res = max(res, dfs(nx, ny, dep + 1));
		checked[nx][ny] = 0;
	}
	return res;
}

int main(void) {
	cin.tie(0); ios::sync_with_stdio(false);
	ll m, n;
    while(cin >> m >> n,m){
	masu.assign(n + 2, vector<int>(m + 2, 0));
	checked.assign(n + 2, vector<int>(m + 2, 0));
	for (int i = 1; i <= n;i++) for (int j = 1; j <= m;j++) cin >> masu[i][j];
	ll res = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1; j <= m;j++) {
			if (masu[i][j] == 0)continue;
			checked[i][j] = 1;
			res = max(res, dfs(i, j, 1));
			checked[i][j] = 0;
		}
	}
	cout << res << endl;
    }
	return 0;
}
