#include <stdio.h>

int main(){
    int a = 0;
    long b = 0;

    typedef struct testers {int i, j, k, l;} tester;
    typedef struct testerlongs {int i, j, k; long l;} testerlong;
    typedef struct withunions{union {int children; long beard;} u; } withunion;

    tester name;
    testerlong sname;
    withunion union_size;

    name.i = 0, name.j = 0, name.k = 0, name.l = 0;
    sname.i = 0, sname.j = 0, sname.k = 0, sname.l = 0;
    union_size.u.children = 0;

    printf("size of int: %lu\n", sizeof(a));
    printf("size of long: %lu\n", sizeof(b));
    printf("size of tester with int: %lu\n", sizeof(tester));
    printf("size of tester with one long: %lu\n", sizeof(testerlong));
    printf("size of union %ld\n", sizeof(withunion));

    return 0;
}