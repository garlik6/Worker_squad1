//
// Created by Grigory on 12.12.2020.
//

#include"../vector.h"
#include "../Units/Unit.h"
#include "../Units/Master.h"
#include"../Units/Worker.h"
#include "../Fields/Field.h"
#include "../crew/crew.h"
namespace dialog_2{
int dialog2();

const char *msgs[] = {"1 Master", "2 Worker"};
const int  N = sizeof(msgs) / sizeof(msgs[0]);
int getInt(int *a) {
    int n;
    do {
        fflush(stdin);
        n = scanf("%i", a);
        if (n < 0)
            return 0;
        if (n == 0) {
            printf("%s\n", "Error! Repeat input");
            scanf("%*[^\n]", 0);
        }
    } while (n == 0);
    scanf("%*c");
    return 1;
}

int dialog2()
{
    char *errmsg = "";
    int rc;
    int i,n;

    do{
        puts(errmsg);
        errmsg = "You are wrong, repeat please";
        fflush(stdin);
        for(i = 0;i < N;++i)
            puts(msgs[i]);
        puts("Make your choice: -->");
        n = getInt(&rc);
        if(n == 0)
            rc = 0;
    }while(rc < 1 || rc >= 3);
    return rc;

}

}