# 📊 Numerical Analysis with Python Libraries

This repository provides an introduction
to essential Python libraries for numerical analysis and data manipulation.

- **NumPy** 
- **Pandas**.
- etc 

---

## 🔢 NumPy

### 📌 What is NumPy?

[NumPy](https://numpy.org/) (Numerical Python) is a powerful library that provides support for:

- Multi-dimensional arrays and matrices
- Mathematical functions and operations
- Fast numerical computation using vectorization

### ❓ Why Use NumPy over Base Python?

| Feature              | Base Python      | NumPy                   |
|----------------------|------------------|--------------------------|
| Performance          | Slower loops     | Vectorized (much faster)|
| Multi-dimensional support | Limited       | Full n-dimensional arrays |
| Broadcasting         | Manual handling  | Built-in                 |
| Math functions       | Basic support    | Extensive & optimized    |

NumPy is ideal for scientific computing, simulations, and situations where performance matters.

---

## 🐼 Pandas

### 📌 What is Pandas?

[Pandas](https://pandas.pydata.org/) is a high-level library built on top of NumPy. It provides powerful tools for:

- Data manipulation and wrangling
- Handling labeled/tabular data (like Excel or SQL tables)
- Time series analysis

The core data structures in Pandas are:

- `Series`: One-dimensional labeled array
- `DataFrame`: Two-dimensional table with labeled axes (rows and columns)

### ❓ Why Use Pandas over Base Python?

| Feature              | Base Python               | Pandas                         |
|----------------------|---------------------------|--------------------------------|
| Tabular data support | Lists/dicts (manual work) | Native DataFrame support       |
| File I/O             | Manual parsing            | Built-in support (CSV, Excel)  |
| Filtering            | Verbose                   | Elegant & readable             |
| Grouping/Aggregation | Complex                   | `groupby()` and other methods  |

Pandas is perfect for real-world data tasks such as cleaning, transforming, filtering, and analyzing datasets.

---

## 🤜 NumPy vs Pandas

| Feature                | NumPy                          | Pandas                          |
|------------------------|--------------------------------|----------------------------------|
| Data Structure         | n-dimensional arrays           | Labeled Series and DataFrames   |
| Performance            | Generally faster (low-level)   | Slightly slower (high-level)    |
| Usability              | Low-level API                  | High-level, user-friendly       |
| Ideal Use Case         | Scientific computation         | Tabular data analysis           |
| Built on               | Native C (very fast)           | Built on NumPy                  |

> ✅ Use **NumPy** for fast mathematical computations.  
> ✅ Use **Pandas** for analyzing and manipulating structured data.

---

## 📂 Contents

- `numpy_examples.ipynb` – Intro to NumPy with examples
- `pandas_examples.ipynb` – Intro to Pandas with examples
- `README.md` – This documentation file

---

## 📌 Requirements

Install the required packages with:

```bash
pip install numpy pandas
```

---
Happy analyzing! 📈🐍