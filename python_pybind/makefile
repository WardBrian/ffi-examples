
.PHONY: euler clean

euler: setup.py euler_pybind.cpp ../C/euler.c
	python3 setup.py build --force

clean:
	$(RM) -r build
