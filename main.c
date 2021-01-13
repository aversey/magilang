#include <magi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static char *scopy(const char *s)
{
    int   len = s ? strlen(s) : 0;
    char *res  = malloc(len + 1);
    if (s) memcpy(res, s, len);
    res[len] = 0;
    return res;
}

static char *scat(const char *a, const char *b)
{
    int   alen = a ? strlen(a) : 0;
    int   blen = b ? strlen(b) : 0;
    char *res  = malloc(alen + blen + 1);
    memcpy(res, a, alen);
    memcpy(res + alen, b, blen);
    res[alen + blen] = 0;
    return res;
}


static void response(struct magi_request *req)
{
    return;
}


int main()
{
    struct magi_request request;
    magi_request_init(&request);
    if (magi_parse(&request)) {
        response(&request);
    } else {
        magi_error_response(request.error);
    }
    magi_request_free(&request);
    return 0;
}
