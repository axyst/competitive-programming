int n,m;
vector<vector<long long>>d;
void calc (int x = 0, int y = 0, int mask = 0, int next_mask = 0)
{
    if (x == n) // last row
        return;
    if (y >= m) // last col, maintain unfilled grid
        d[x+1][next_mask] += d[x][mask];
    else
    {
        int my_mask = 1 << y; // yth bit of current row is unfilled
        if (mask & my_mask) // yth bit of last row is also unfilled
            calc (x, y+1, mask, next_mask); // fill yth bit, next col
        else // yth bit of last row is filled
        {
            calc (x, y+1, mask, next_mask | my_mask);//(1) skip yth bit, next col
            if (y+1 < m && ! (mask & my_mask) && ! (mask & (my_mask << 1))) // (y+1)th bit of last row is unfilled
                calc (x, y+2, mask, next_mask); // (2) fill current and next col of current row with a lying grid
        }
    }
}