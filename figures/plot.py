import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

data = pd.read_csv("results/results.csv")

fig, ax = plt.subplots()

fig.set_size_inches(3, 2.6)

plt.rcParams["text.usetex"] = True

plt.scatter(data["b"], data["bhat"])
ax.set_xlabel("$y$")
ax.set_ylabel("$\\hat y$")

fig.savefig("paper/figures/plot.pdf", pad_inches=0, bbox_inches='tight')
