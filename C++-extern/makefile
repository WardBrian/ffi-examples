euler.so: euler.cpp ../C/euler.c
	$(CXX) -shared -o euler.so -fPIC euler.cpp

test: euler.so test.cpp ../C/euler.h
	$(CXX) -o test test.cpp euler.so -Wl,-rpath=`pwd`

.PHONY: clean
clean:
	$(RM) euler.so test
