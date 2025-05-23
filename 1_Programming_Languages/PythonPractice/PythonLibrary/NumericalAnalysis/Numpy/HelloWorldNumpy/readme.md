# 🧮 NumPy Basics: Examples and Explanations

This document provides a beginner-friendly introduction to using **NumPy**, Python’s popular numerical computing library.

---
## ✅ Installation

If you don't have NumPy installed, install it using pip:

```bash
pip install numpy
```
## 🔢 Import NumPy and Check Version
```Python
import numpy as np

print("NumPy version:", np.__version__)
```
🖥️ Output (my local computer):
`NumPy version: 2.2.4`

## 📌 1. Creating a 1D Array
```Python
arr = np.array([1, 2, 3, 4, 5])
print("Array:", arr)
```

Output:
`Array: [1 2 3 4 5]`

## 🧮 2. Basic Array Operations
```Python
print("Mean:", np.mean(arr))
print("Sum:", np.sum(arr))
print("Square root:", np.sqrt(arr))
```
🖥️ Output:
```Python
Mean: 3.0
Sum: 15
Square root: [1.         1.41421356 1.73205081 2.         2.23606798]
```

## 🧱 3. Creating and Manipulating a 2D Array (Matrix)
```Python
matrix = np.array([[1, 2], [3, 4]])
print("Matrix:\n", matrix)
```
Output:
```Python
Matrix:
 [[1 2]
  [3 4]]
```

## 🔁 4. Transpose of a Matrix

```Python
print("Transpose:\n", matrix.T)
```

Output:
```Python
Transpose:
 [[1 3]
  [2 4]]
```
## ✖️ 5. Element-wise Multiplication

```Python
print("Element-wise multiplication:\n", matrix * matrix)
```

Output:
```Python
Element-wise multiplication:
 [[ 1  4]
  [ 9 16]]
```

## 🔗 6. Dot Product (Matrix Multiplication)

```Python
print("Dot product:\n", np.dot(matrix, matrix))
```

Output:
```Python
Dot product:
 [[ 7 10]
  [15 22]]
```

## 📚 Summary
| **Operation**               | **Function**     | **Example**           |
|----------------------------|------------------|------------------------|
| Create array               | `np.array()`     | `np.array([1,2])`     |
| Mean                       | `np.mean()`      | `np.mean(arr)`        |
| Sum                        | `np.sum()`       | `np.sum(arr)`         |
| Square root                | `np.sqrt()`      | `np.sqrt(arr)`        |
| Transpose matrix           | `.T`             | `matrix.T`            |
| Element-wise multiplication| `*`              | `matrix * matrix`     |
| Matrix multiplication      | `np.dot()`       | `np.dot(A, B)`        |



