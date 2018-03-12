#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"

/* TODO: FILL YOUR OWN IMPLEMENTATION HERE! */
void init_table(entry *table[])
{
    for(int i = 0; i < TABLE_SIZE; i++)
        table[i] = NULL;
}

unsigned int elf_hash(char *str)
{
    unsigned int g, h = 0;
    int ch;

    while ((ch = *str++) != '\0') {
        h = (h << 4) + ch;
        if ((g = (h & 0xf0000000)) != 0) {
            h ^= g >> 24;
            h ^= g;
        }
    }
    return h % TABLE_SIZE;
}

unsigned int bkdr_hash(char *str)
{

    unsigned int seed = 13;
    unsigned int hash = 0;

    while (*str) {
        hash = hash * seed + (*str++);
    }
    return hash % TABLE_SIZE;
}

entry *findName(char lastName[], entry *table[])
{
    /* TODO: implement */
    unsigned int num;
    num = bkdr_hash(lastName);
    while(table[num] != NULL) {
        if(strcasecmp(lastName,table[num]->lastName) == 0)
            return table[num];
        table[num] = table[num]->pNext;
    }
    return NULL;
}

void *append(char lastName[], entry *table[])
{
    /* TODO: implement */
    unsigned int index = bkdr_hash(lastName);

    entry *e = (entry *)malloc(sizeof(entry));
    e->pNext = NULL;
    if (!table[index]) {
        table[index] = e;
        strcpy(e->lastName, lastName);
    } else {
        e->pNext = table[index]->pNext;
        table[index]->pNext = e;
        strcpy(e->lastName, lastName);
    }
    return NULL;
}
