import numpy as np
import pandas as pd
import example_module

data = pd.read_csv("data/dataset.csv")

b = data["b"]
A = data.iloc[:, 1:]

xhat = example_module.inv(A.T @ A) @ A.T @ b

bhat = np.dot(A, xhat)

results = pd.DataFrame({"b": b, "bhat": bhat})

results.to_csv("results/results.csv", index=False)
