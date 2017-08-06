target = call_main_recursively

source = $(target).c

all: $(target)

$(target): $(source) Makefile
	clang -Wall -Wextra -o $@ $<

clean:
	rm -fv a.out *.o

allclean: clean
	rm -fv $(target)

test: $(target)
	./$(target) A B C

vi:
	vi $(source)

