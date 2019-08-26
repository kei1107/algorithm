#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

/*
 <url:https://www.ioi-jp.org/joi/2007/2008-yo-prob_and_sol/2008-yo-t4/2008-yo-t4.html>
 ��蕶============================================================
 ���Ȃ��͐���̎ʐ^�̒����琯����T���Ă���D
 �ʐ^�ɂ͕K���C�T�����������Ɠ����`�E�����E�傫���̐}�`�����傤�ǈ�܂܂�Ă���D
 �������C�ʐ^�̒��ɂ͐������\�����鐯�ȊO�ɗ]���Ȑ����ʂ��Ă���\��������D
 
 �}��
 
 �Ⴆ�΁C�} 1 �̐����͐} 2 �̎ʐ^�Ɋ܂܂�Ă���i�ۂň͂�Ŏ������j�D
 �^����ꂽ�����̐��̍��W�� x ������ 2�C y ������ �|3 �������s�ړ�����Ǝʐ^�̒��̈ʒu�ɂȂ�D
 
 �T�����������̌`�Ǝʐ^�Ɏʂ��Ă��鐯�̈ʒu���^����ꂽ�Ƃ��C
 �����̍��W���ʐ^�̒��̍��W�ɕϊ����邽�߂ɕ��s�ړ�����ׂ��ʂ𓚂���v���O�����������D
 =================================================================
 ���=============================================================
 
 �������\�����鐯�͍ő�m := 200�A�ʐ^�Ɏʂ��Ă��鐯�͍ő�n := 1000�A�����Đ����10s
 �ŏ��̈�_�̐������ߑł�����, ���ԂɒT�������������ŏ��̈�_�̐����瑊�ΓI�ȋ����ɑ��݂��邩�T���΂悢
 �T�����Ԃ�log n �ł���̂ő��v�Z�ʂ�O(mnlog n) �A��ΊԂɍ���
 
 ================================================================
 */
int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int m;
    while(cin >> m,m){
        vector<pii> ps1(m);
        for (int i = 0; i < m;i++) cin >> ps1[i].first >> ps1[i].second;
        int n; cin >> n;
        vector<pii> ps2(n);
        for (int i = 0; i < n;i++) cin >> ps2[i].first >> ps2[i].second;
        
        int idx;
        bool f = false;
        for (int i = 0; i < n;i++) {
            idx = i;
            for (int j = 1; j < m;j++) {
                int nx = ps2[idx].first + (ps1[j].first - ps1[j - 1].first);
                int ny = ps2[idx].second + (ps1[j].second - ps1[j - 1].second);
                auto next_it = find(ps2.begin(), ps2.end(), make_pair(nx, ny));
                if (next_it == ps2.end())break;
                idx = next_it - ps2.begin();
                if (j == m - 1) {
                    cout << ps2[i].first - ps1[0].first << " " << ps2[i].second - ps1[0].second << endl;
                    f = true;
                }
            }
            if (f)break;
        }
    }
    return 0;
}
