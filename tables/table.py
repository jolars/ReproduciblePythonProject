import pandas as pd

results = pd.read_csv("results/results.csv")

table = results.describe()

table.to_csv("paper/tables/table.csv")
