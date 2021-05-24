import numpy as np
import pandas as pd

from numpy.random import beta

n = 100
p = 5

A = np.random.randn(n, p)
x = np.random.randn(p)

b = A @ x + np.random.randn(n)

colnames = np.concatenate((["b"], ["a" + str(i) for i in range(1, p + 1)]))

data = pd.DataFrame(np.column_stack((b, A)), columns=colnames)

data.to_csv("data/dataset.csv", index=False)
