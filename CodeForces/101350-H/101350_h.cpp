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
using namespace std;

#define LL long long
#define For(i, a, b) for(int i = (a), _##i = (b); i <= _##i; ++i)
#define Rof(i, a, b) for(int i = (a), _##i = (b); i >= _##i; --i)
#define Mem(a, b) memset(a, b, sizeof(a))
#define Cpy(a, b) memcpy(a, b, sizeof(b))

const int maxn = 1000 + 100;
char str[maxn];
int T;
bool flag;
bool mir[300];
char ch[11] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};

int main() {
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
    #endif // LOCAL
    ios::sync_with_stdio(false);

    For(i, 0, 10) {
        mir[(int)ch[i]] = true;
    }
    scanf("%d", &T);
    while(T--) {
        flag = true;
        scanf("%s", str);
        int len = strlen(str);
        For(i, 0, len - 1) {
            if(!mir[(int)str[i]]) {
                flag = false;
                break;
            }
            if(str[i] != str[len - i - 1]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}