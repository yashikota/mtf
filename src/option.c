#include <getopt.h>

#include "file.h"
#include "usage.h"

char *parseOption(int argc, char *argv[], const char *extension) {
    int opt;
    char *fileName = NULL;

    while ((opt = getopt(argc, argv, "o:")) != -1) {
        switch (opt) {
            case 'o':
                fileName = optarg;
                break;
            default:
                usage(argv);
        }
    }

    if (argc - optind != 1) {
        usage(argv);
    }

    if (fileName == NULL) {
        fileName = outputFileName(argv[optind], extension);
    }

    return fileName;
}

int getOptind(void) {
    return optind;
}
