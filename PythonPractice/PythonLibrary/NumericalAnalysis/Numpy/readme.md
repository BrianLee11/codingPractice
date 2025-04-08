# 🧮 NumPy: Numerical Python

## 📘 What is NumPy?

**NumPy** (Numerical Python) is a powerful Python library used for **numerical computing**, particularly efficient operations on large, multi-dimensional arrays and matrices. It also provides a vast collection of **mathematical functions** to operate on these arrays.

NumPy is the foundation for many other scientific libraries in Python like:
- `pandas` (data analysis)
- `matplotlib` (data visualization)
- `scikit-learn` (machine learning)
- `tensorflow` and `pytorch` (deep learning)

---

## ❓ Why Use NumPy Instead of Base Python?

| Feature                        | Base Python (`list`)         | NumPy (`ndarray`)                      |
|-------------------------------|------------------------------|----------------------------------------|
| 🧠 Speed                       | Slower                       | Much faster (internally C-optimized)   |
| 🧮 Vectorized Operations       | Manual `for` loops required  | Vectorized (no explicit loops needed)  |
| 🔢 Multi-dimensional Arrays    | Complicated, not native      | Built-in and easy to use               |
| 📏 Broadcasting                | Not supported                | Powerful broadcasting support          |
| 📊 Scientific Computing Tools  | Limited                      | Extensive (e.g. linear algebra, FFT)   |

### 🆚 Example: Sum of Squares

**Using base Python:**
```python
nums = [1, 2, 3, 4]
squares = [x**2 for x in nums]
print(sum(squares))  # Output: 30
```

**Using NumPy:**
```python
import numpy as np

arr = np.array([1, 2, 3, 4])
print(np.sum(arr ** 2))  # Output: 30
```
✅ Cleaner syntax, faster performance, and better scalability.


