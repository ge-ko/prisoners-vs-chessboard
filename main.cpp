#include <cstdlib>
#include <cassert>
#include <time.h>

// 2nd prisoner algorithm
int find_key(bool s[64], int key = 0)
{
    for (int n = 1; n < 64; ++n)
        if (s[n])
            key ^= n;
    return key;
}

// 1st prisoner algorithm
void flip_coin(bool s[64], int key)
{
    key = find_key(s, key);
    s[key] = !s[key];
}

int main()
{
    srand(time(0));
    bool s[64];
    for (int n = 0; n < 64; ++n)
        s[n] = (rand() % 2 == 1);
    int key = rand() % 64;
    
    flip_coin(s, key);
    assert(key == find_key(s));

    return 0;
}
