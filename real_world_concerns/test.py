import numpy as np
import foo

frob = foo.Frobulator(1, 2)
data = np.ones(10)
out = frob.compute(data)
print(out)

data2 = np.ones(3)
# will raise an error
out2 = frob.compute(data2)
