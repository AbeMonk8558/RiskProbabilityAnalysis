#include <stdio.h>
#include <math.h>

#define MAX(x, y) (x > y ? x : y)
#define MAX3(x, y, z) (z > MAX(x, y) ? z : MAX(x, y))

#define MIN(x, y) ((x < y) ? x : y)
#define MIN3(x, y, z) (z < MIN(x, y) ? z : MIN(x, y))

int powi(int base, int exp)
{
    int res = 1;

    for (; exp > 0; exp--)
        res *= base;

    return res;
}

int main(int argc, char** argv)
{
    const int offenseDie = 3;
    const int defenseDie = 2;

    const int nOffense = powi(6, offenseDie);
    const int nDefense = powi(6, defenseDie);

    int totalDiff = 0;
    int total = 0;

    for (int o = 0; o < nOffense; o++)
    {
        int o1 = 1 + o % 6;
        int o2 = 1 + (o / 6) % 6;
        int o3 = 1 + o / 36;

        for (int d = 0; d < nDefense; d++)
        {
            int d1 = 1 + d % 6;
            int d2 = 1 + d / 6;

            int diff = (MAX3(o1, o2, o3) - MAX(d1, d2) + 
                MIN3(MAX(o1, o2), MAX(o2, o3), MAX(o3, o1)) - MIN(d1, d2)) / 2;

            total += abs(diff);
            totalDiff += diff;
        }
    }

    return 0;
}