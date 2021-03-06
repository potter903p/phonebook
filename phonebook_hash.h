#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define HASH 1
#define TABLE_SIZE 10000
typedef struct __PHONE_BOOK_DETAIL {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} detail;

typedef struct __PHONE_BOOK_LAST_NAME {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_DETAIL *pDetail;
    struct __PHONE_BOOK_LAST_NAME *pNext;
} entry;


void init_table(entry *table[]);
unsigned int elf_hash(char *str);
unsigned int bkdr_hash(char *str);
entry *findName(char lastName[], entry *table[]);
void *append(char lastName[], entry *table[]);

#endif
