#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "list.h"
#include "mtf.h"
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
        pushValue(table, i);
    }

    // read data
    char buf[5];
    List *data = createList(1);
    while (fgets(buf, 5, rfp) != NULL) {
        pushValue(data, atoi(buf));
    }

    // encode
    moveToFrontEncode(2, data, table);

    // write data
    for (int i = 0; i < getListLength(data); i++) {
        int value = getValue(data, i);
        fprintf(wfp, "%d\n", value);
    }

    cleanList(table);
    cleanList(data);
    fclose(rfp);
    fclose(wfp);

    return 0;
}
