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

const int maxn = 100000 + 100;
LL T, n, tmp[maxn];
bool flag;

int main() {
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
    #endif // LOCAL
    ios::sync_with_stdio(true);

    scanf("%I64d", &T);
    while(T--) {
        flag = true;
        scanf("%I64d", &n);
        For(i, 0, n - 1) {
            scanf("%I64d", &tmp[i]);
        }
        For(i, 0, n - 1) {
            if((tmp[i] & 1) != (tmp[0] & 1)) {
                flag = false;
                break;
            }
        }

        if(flag) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}