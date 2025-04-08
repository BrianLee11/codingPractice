# 🧪 Practice: Using JSON in Python

This mini project is a simple hands-on exercise for learning how to work with **JSON (JavaScript Object Notation)** using Python's built-in `json` module.

---

## 📌 What You'll Learn

- What JSON is and how it's structured
- How to load JSON strings and files into Python
- How to access, modify, and write JSON data
- How to convert between JSON and Python dictionaries

---

## 🧾 Sample JSON Data

Here's the sample data used in this exercise:

```json
{
  "name": "Alice",
  "age": 28,
  "is_student": false,
  "skills": ["Python", "Data Analysis", "Machine Learning"],
  "address": {
    "city": "New York",
    "zip": "10001"
  }
}
```

## 🐍 Basic Steps in Python
1. Load JSON from a string or file using `json.loads()` or `json.load()`

2. Access or modify data like a normal Python `dictionary`

3. Dump JSON back to a string or file using `json.dumps()` or `json.dump()`

```Python
import json

# Load JSON string
json_data = '''{ "name": "Alice", "age": 28 }'''
data = json.loads(json_data)

# Access and update
print(data['name'])
data['age'] += 1

# Convert back to JSON
new_json = json.dumps(data, indent=2)
print(new_json)
```

