
euler.so: euler.c euler.h
	$(CC) -shared -o euler.so -fPIC euler.c

test: test.c euler.h euler.so
	$(CC) -o test test.c euler.so -Wl,-rpath=.

.PHONY: clean
clean:
	$(RM) *.so test
