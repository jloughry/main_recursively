call_main_recursively
=====================

This is an experiment to find out if I can call the main() function
recursively in C.

Results
-------

Interestingly, when I tried the most naïve possible implementation:

````
int main(void) {
    main();
}
````

I got the following warning message from clang:

````
call_main_recursively.c:4:17: warning: all paths through this function will
call itself
      [-Winfinite-recursion]
````

But it runs, with the expected results (infinite output).

TODO
----

Add a recursion predicate that yields a termination condition.

