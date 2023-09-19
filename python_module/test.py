# this is just so we can find the built module
import sys
import os
for path in os.listdir('./build/'):
    sys.path.append(os.path.join("build", path))
# end boilerplate

import euler # looks like a normal python package!

if __name__ == '__main__':
    import sys
    if len(sys.argv) != 2:
        print ("usage: python euler.py N")
        sys.exit(1)

    iter = int(sys.argv[1])
    print(f"e = {euler.euler(iter)}")
