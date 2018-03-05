#include <iostream>
#include <algorithm>
using namespace std;

struct room
{
    int ith;
    int num;
};

bool operator<(const room &a, const room & b)
{
    return a.num < b.num;
}

int main()
{
    int n, total;
    room r[35];
    while(cin >> n)
    {
        total = 0;
        for(int i = 0; i < n; ++i)
        {
            cin >> r[i].num;
            r[i].ith = i + 1;
        }
        sort(r, r + n);
        for(int i = 0; i < n - 1; ++i)
            total += r[i].num;
        if(total < r[n - 1].num)
            cout << "impossible" << endl;
        else
        {
            for(int i = n - 1; i >= 0; --i)
                cout << r[i].ith << " ";
            cout << endl;
        }
    }
    return 0;
}
close