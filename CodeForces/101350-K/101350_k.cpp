#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
using namespace std;

#define LL long long
#define For(i, a, b) for(int i = (a), _##i = (b); i <= _##i; ++i)
#define Rof(i, a, b) for(int i = (a), _##i = (b); i >= _##i; --i)
#define Mem(a, b) memset(a, b, sizeof(a))
#define Cpy(a, b) memcpy(a, b, sizeof(b))

LL T;
LL a, b, N;
int tmz[20], ttt[20];

void add(LL tmp) {
    if(tmp == 0) ++tmz[0];
    else {
        Mem(ttt, 0);
        while(tmp != 0) {
            ++ttt[tmp % 10];
            tmp /= 10;
        }
        int ans = 0;
        For(i, 0, 9) {
            if(ttt[ans] < ttt[i]) {
                ans = i;
            }
        }
        For(i, 0, 9) {
            if(ttt[ans] == ttt[i]) {
                ++tmz[i];
            }
        }
    }
}

bool allzero() {
    For(i, 0, 9) {
        if(tmz[i] != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
    #endif // LOCAL
    ios::sync_with_stdio(true);

    scanf("%I64d", &T);
    while(T--) {
        Mem(tmz, 0);
        scanf("%I64d%I64d%I64d", &a, &b, &N);
        for(LL x = 1; a * x * x + b * x <= N; ++x) {
            LL tmp = a * x * x + b * x;
            add(tmp);
        }
        if(allzero()) {
            printf("-1\n");
        } else {
            int ans = 0;
            For(i, 0, 9) {
                if(tmz[ans] < tmz[i]) {
                    ans = i;
                }
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}