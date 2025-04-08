# 🐼 Simple Examples Using Pandas

This repository/notebook provides simple and intuitive examples to help you get started with the **Pandas** library in Python.

---

## 📦 What is Pandas?

[Pandas](https://pandas.pydata.org/) is a powerful Python library used for data manipulation and analysis. It provides data structures like **DataFrames** and **Series** that are ideal for handling structured data.

---

## ✅ What You'll Learn

This notebook includes:

- ✅ Checking the installed version of Pandas
- ✅ Creating a DataFrame from a dictionary
- ✅ Exploring data (head, info, describe)
- ✅ Selecting and filtering data
- ✅ Adding new columns

---

## 📌 Quick Preview

```python
import pandas as pd

# Check version
print("Pandas version:", pd.__version__)

# Create a simple DataFrame
data = {
    'Name': ['Alice', 'Bob', 'Charlie'],
    'Age': [25, 30, 35],
    'City': ['New York', 'Los Angeles', 'Chicago']
}

df = pd.DataFrame(data)

# Filter rows where Age > 28
filtered_df = df[df['Age'] > 28]
print(filtered_df)
```