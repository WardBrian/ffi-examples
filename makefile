.PHONY: build clean

build:
	$(MAKE) -C C test
	$(MAKE) -C C++ test test_mangle
	$(MAKE) -C python_module

clean:
	$(MAKE) -C C clean
	$(MAKE) -C C++ clean
	$(MAKE) -C python_module clean
