#include "euler.h"


double euler(int iter)
{
    double e = 1;
    double f = 1;

    for (int i = 1; i < iter; i++)
    {
        f *= (1.0 / i);
        if (f == 0)
        {
            break;
        }
        e += f;
    }
    return e;
}
