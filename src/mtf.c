#include "mtf.h"

#include "list.h"

void moveToFront0Encode(List *data, List *table) {
    for (int i = 0; i < getListLength(data); i++) {
        int value = getValue(data, i);
        int index = searchValue(table, value);
        if (index > 0) {
            deleteValue(table, value);
            insertValue(table, 0, value);
        }
        data->data[i] = index;
    }
}

void moveToFront2Encode(List *data, List *table) {
    int prev = 1;
    for (int i = 0; i < getListLength(data); i++) {
        int value = getValue(data, i);
        int index = searchValue(table, value);
        if (index == 1) {
            if (prev != 0) {
                table->data[1] = table->data[0];
                table->data[0] = value;
            }
        } else if (index > 1) {
            deleteValue(table, value);
            insertValue(table, 1, value);
        }
        data->data[i] = index;
        prev = index;
    }
}

void moveToFrontEncode(int version, List *data, List *table) {
    return version == 0 ? moveToFront0Encode(data, table)
                        : moveToFront2Encode(data, table);
}

void moveToFront0Decode(List *data, List *table) {
    for (int i = 0; i < getListLength(data); i++) {
        int index = data->data[i];
        int value = getValue(table, index);
        if (index > 0) {
            deleteValue(table, value);
            insertValue(table, 0, value);
        }
        data->data[i] = value;
    }
}

void moveToFront2Decode(List *data, List *table) {
    int prev = 1;
    for (int i = 0; i < getListLength(data); i++) {
        int index = getValue(data, i);
        int value = table->data[index];
        if (index == 1) {
            if (prev != 0) {
                table->data[1] = table->data[0];
                table->data[0] = value;
            }
        } else if (index > 1) {
            deleteValue(table, value);
            insertValue(table, 1, value);
        }
        data->data[i] = value;
        prev = index;
    }
}

void moveToFrontDecode(int version, List *data, List *table) {
    return version == 0 ? moveToFront0Decode(data, table)
                        : moveToFront2Decode(data, table);
}
