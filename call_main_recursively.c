#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int global = 0;
char * display_argv(int argc, char ** argv);

int main(int argc, char ** argv) {
    char * free_this = NULL;
    printf("main() called with %s; the value of global = %d\n",
        free_this = display_argv(argc, argv), ++global);
    free(free_this);
    if (argc > 1) {
        main(argc - 1, argv);
    }
    printf("returning from main(); global = %d\n", global);
    return EXIT_SUCCESS;
}

char * display_argv(int argc, char ** argv) {
    char * s = NULL;
    size_t total_length_of_arguments = 0;

    if (argc < 2) {
        char no_arguments[] = "no arguments";

        s = malloc(1 + strlen(no_arguments));
        strcpy(s, no_arguments);
    }
    else {
        // Figure out how much space we need to hold all the arguments in argv.
        for (int i=1; i<argc; i++) {
            total_length_of_arguments += strlen(argv[i]);
            if (i < argc - 1) {
                ++total_length_of_arguments; // Add room for a space between.
            }
        }
        ++total_length_of_arguments; // Add room for the null terminator.

        s = malloc(total_length_of_arguments);
        if (!s) {
            perror("malloc");
        }
        s[0] = '\0'; // Null terminate the new string.

        for(int i=1; i<argc; i++) {
            strcat(s, argv[i]);
            if (i < argc - 1) {
                strcat(s, " ");
            }
        }
    }
    return s;
}

