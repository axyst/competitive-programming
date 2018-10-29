#include <bits/stdc++.h>
using namespace std;
typedef vector<int> lnum;
const int base = 1000 * 1000 * 1000;
void print(lnum a)
{
    printf("%d", a.empty() ? 0 : a.back());
    for (int i = (int)a.size() - 2; i >= 0; --i)
        printf("%09d", a[i]);
    printf("\n");
}
lnum input(string s)
{
    lnum a;
    for (int i = (int)s.length(); i > 0; i -= 9)
        if (i < 9)
            a.push_back(atoi(s.substr(0, i).c_str()));
        else
            a.push_back(atoi(s.substr(i - 9, 9).c_str()));
    // remove leading zeros
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    return a;
}
lnum input(char *s)
{
    lnum a;
    for (int i = (int)strlen(s); i > 0; i -= 9)
    {
        s[i] = 0;
        a.push_back(atoi(i >= 9 ? s + i - 9 : s));
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    return a;
}
lnum add(lnum a, lnum b)
{
    // bits/move.h
    lnum c = move(a);
    int carry = 0;
    for (size_t i = 0; i < max(c.size(), b.size()) || carry; ++i)
    {
        if (i == c.size())
            c.push_back(0);
        c[i] += carry + (i < b.size() ? b[i] : 0);
        carry = c[i] >= base;
        if (carry)
            c[i] -= base;
    }
    return c;
}
lnum sub(lnum a, lnum b)
{
    lnum c = move(a);
    int carry = 0;
    for (size_t i = 0; i < b.size() || carry; ++i)
    {
        c[i] -= carry + (i < b.size() ? b[i] : 0);
        carry = c[i] < 0;
        if (carry)
            c[i] += base;
    }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    return c;
}
lnum mul(lnum a, int b)
{
    lnum c = move(a);
    int carry = 0;
    for (size_t i = 0; i < c.size() || carry; ++i)
    {
        if (i == c.size())
            c.push_back(0);
        long long cur = carry + c[i] * 1ll * b;
        c[i] = int(cur % base);
        carry = int(cur / base);
    }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    return c;
}
lnum mul(lnum a, lnum b)
{
    lnum c(a.size() + b.size());
    for (size_t i = 0; i < a.size(); ++i)
        for (int j = 0, carry = 0; j < (int)b.size() || carry; ++j)
        {
            long long cur = c[i + j] + a[i] * 1ll * (j < (int)b.size() ? b[j] : 0) + carry;
            c[i + j] = int(cur % base);
            carry = int(cur / base);
        }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    return c;
}
lnum div(lnum a, int b)
{
    lnum c = move(a);
    int carry = 0;
    for (int i = (int)c.size() - 1; i >= 0; --i)
    {
        long long cur = c[i] + carry * 1ll * base;
        c[i] = int(cur / b);
        carry = int(cur % b);
    }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    return c;
}