import euler # looks like a normal python package!

if __name__ == '__main__':
    import sys
    if len(sys.argv) != 2:
        print ("usage: python test.py N")
        sys.exit(1)

    iter = int(sys.argv[1])
    e = euler.euler(iter)

    print(f"{e = }")
