#include "header.h"
#include <string.h>
#include <math.h>

static size_t		hash(char *jesus)
{
	size_t	res;
    int     i;

	res = 0;
    i = 0;
	while(jesus && jesus[i])
	{
		res += jesus[i] * (size_t)pow(31, i);
        i++;
	}
	return (res);
}

static size_t		new_hash(size_t old, char j, int j_len)
{
	return (old + pow(31, j_len - 1) * j);
}

int     howManyJesus(char *bible, char *jesus)
{
    int         count;
    size_t      j_hash;
    size_t      n_hash;
    size_t      len;
    size_t      j_len;

    count = 0;
    if (!bible || !jesus)
        return (0);
    j_len = strlen(jesus);
    len = strlen(bible);
    if (j_len == 0 || len == 0)
        return (0);
    j_hash = hash(jesus);
    n_hash = hash(strndup(bible, j_len));
    while (len-- >= j_len)
    {
        if (j_hash == n_hash)
            count++;
        n_hash = new_hash(((n_hash - bible[0]) / 31), bible[j_len], j_len);
        bible++;
    }
    return (count);
}