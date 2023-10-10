
libfoo.so: wrapfoo.cpp wrapfoo.h foo.hpp
	$(CXX) -shared -fPIC -o libfoo.so wrapfoo.cpp

.PHONY: clean
clean:
	$(RM) libfoo.so
	$(RM) -r __pycache__
