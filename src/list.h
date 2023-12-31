#ifndef LIST_H
#define LIST_H

typedef struct {
    int size;
    int length;
    int *data;
} List;

List *createList(int size);
void pushValue(List *list, int value);
int searchValue(List *list, int value);
void deleteValue(List *list, int value);
void insertValue(List *list, int index, int value);
int getListLength(List *list);
void cleanList(List *list);
int getValue(List *list, int index);
int *getAllListValue(List *list);

#endif
