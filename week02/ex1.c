#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

    int i;
    float f;
    double d;

    i = INT_MAX;
    f = FLT_MAX;
    d = DBL_MAX;

    printf("Integer: size %d bytes, value %d\n", sizeof(i), i);
    printf("Float: size %d bytes, value %e\n", sizeof(f), f);
    printf("Double: size %d bytes, value %e\n", sizeof(d), d);

    return 0;

}
