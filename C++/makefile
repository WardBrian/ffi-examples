
euler.so: euler.cpp ../C/euler.c
	$(CXX) -shared -o euler.so -fPIC euler.cpp

test: euler.so test.cpp ../C/euler.h
	$(CXX) -o test test.cpp euler.so -Wl,-rpath=`pwd`

euler_mangle.so: euler_mangle.cpp ../C/euler.c
	$(CXX) -shared -o euler_mangle.so -fPIC euler_mangle.cpp

test_mangle: euler_mangle.so test.cpp ../C/euler.h
	$(CXX) -DMANGLE -o test_mangle test.cpp euler_mangle.so -Wl,-rpath=`pwd`

.PHONY: clean
clean:
	$(RM) *.so test test_mangle
