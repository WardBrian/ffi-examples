.PHONY: build clean

build:
	$(MAKE) -C C test
	$(MAKE) -C C++ test
	$(MAKE) -C C++-extern test
	$(MAKE) -C python_module
	$(MAKE) -C python_pybind
	$(MAKE) -C real_world_concerns

clean:
	$(MAKE) -C C clean
	$(MAKE) -C C++ clean
	$(MAKE) -C C++-extern clean
	$(MAKE) -C python_module clean
	$(MAKE) -C python_pybind clean
	$(MAKE) -C real_world_concerns clean
