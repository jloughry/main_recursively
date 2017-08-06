#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int global = 0;
char * display_argv(int argc, char ** argv);

int main(int argc, char ** argv) {
    char * free_this = NULL;

    // All this extra complication just to cram all of argv into a string.
    printf("main() called with %s; the value of global = %d\n",
        free_this = display_argv(argc, argv), ++global);

    // The caller is responsible for freeing the string.
    free(free_this);

    // Try calling main() recursively (but not infinitely).
    if (argc > 1) {
        main(argc - 1, argv); // Yeah, yeah...technically it's too long.
    }

    printf("returning from main(); global = %d\n", global);
    return EXIT_SUCCESS;
}

// Return a string containing everything in argv (the caller must free it).
char * display_argv(int argc, char ** argv) {
    char * s = NULL;

    if (argc < 2) {
        char no_arguments[] = "no arguments";

        s = malloc(1 + strlen(no_arguments));
        if (!s) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(s, no_arguments);
    }
    else {
        s = malloc(1 + strlen(argv[1]));
        if (!s) {
            perror("malloc");
            exit(EXIT_SUCCESS);
        }
        strcpy(s, argv[1]);
        // All this extra complication just to avoid a single wasted space.
        for (int i=2; i<argc; i++) {
            s = realloc(s, 1 + strlen(s) + 1 + strlen(argv[i]));
            if (!s) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
            strcat(s, " ");
            strcat(s, argv[i]);
         }
    }
    return s;
}

