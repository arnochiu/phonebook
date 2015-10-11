#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_opt.h"

int same(char *c1, char *c2){
    int i = 0;
    while(c1[i]==c2[i]){
        if(c1[i]=='\0' || c2[i]=='\0')
            break;
        i++;
    }
    if(c1[i]=='\0' && c2[i]=='\0')
        return 1;
    else
        return 0;
}

entry *findName(char lastname[], entry *pHead)
{
    while (pHead != NULL) {
        if(same(lastname, pHead->lastName))
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{

    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    e->pDetail = NULL;

    return e;
}
