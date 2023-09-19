
.PHONY: euler clean

euler: setup.py eulermodule.c ../C/euler.c
	python3 setup.py build --force

clean:
	$(RM) -r build
