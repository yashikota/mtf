#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "list.h"
#include "option.h"

#define TABLE_SIZE 256

int main(int argc, char *argv[]) {
    FILE *rfp, *wfp;

    char *outputFileName = parseOption(argc, argv, "mtf");

    rfp = fileOpen(argv[getOptind()], "r");
    wfp = fileOpen(outputFileName, "w");

    // initialize table
    List *table = createList(TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++) {
        pushList(table, i);
    }

    // create list
    char buf[5];
    List *list = createList(1);
    while (fgets(buf, 5, rfp) != NULL) {
        int value = atoi(buf);
        pushList(list, value);
    }

    // move to front 2
    int prev = 1;
    for (int i = 0; i < getListLength(list); i++) {
        int value = getListValue(list, i);
        int index = searchList(table, value);
        if (index == 1) {
            if (prev != 0) {
                table->data[1] = table->data[0];
                table->data[0] = value;
            }
        } else if (index > 1) {
            deleteValue(table, value);
            insertValue(table, 1, value);
        }
        list->data[i] = index;
        prev = index;
    }

    // write data
    for (int i = 0; i < getListLength(list); i++) {
        int value = getListValue(list, i);
        fprintf(wfp, "%d\n", value);
    }

    fclose(rfp);
    fclose(wfp);

    return 0;
}
