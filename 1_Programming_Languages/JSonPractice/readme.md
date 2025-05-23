# 📄 JSON Practice

This repository is for practicing how to use **JSON (JavaScript Object Notation)** in Python. JSON is a lightweight, widely-used data format that's easy to read, write, and work with — both for humans and machines.

---

## ❓ What is JSON?

**JSON** (JavaScript Object Notation) is a text-based format for representing structured data. It's most commonly used to:

- Exchange data between a server and web application
- Store and transmit configuration settings
- Represent complex data structures (like nested lists and dictionaries)

A JSON object looks similar to a Python dictionary:

```json
{
  "name": "Alice",
  "age": 28,
  "skills": ["Python", "Data Analysis"],
  "address": {
    "city": "New York",
    "zip": "10001"
  }
}
```
## ✅ Why Use JSON?

| Feature                     | Benefit                                                           |
|-----------------------------|-------------------------------------------------------------------|
| 🌍 **Universal Format**     | Language-independent and supported everywhere                    |
| 🧠 **Human-Readable**       | Easy to read, write, and understand                               |
| 🔁 **Data Interchange**     | Commonly used in APIs, web services, and data sharing             |
| 🛠️ **Easy to Parse in Python** | Python’s `json` module makes working with JSON simple         |

## 🐍 JSON in Python

Python has a built-in `json` module that allows you to:

- Load JSON strings/files into Python dictionaries with `json.load()` or `json.loads()`
- Convert Python objects into JSON with `json.dump()` or `json.dumps()`
- Access and manipulate nested JSON like regular dictionaries

## ✏️ Practice Goals

- ✅ Read JSON from a string or file  
- ✅ Access and update values  
- ✅ Convert Python data to JSON  
- ✅ Save updated JSON to a file  
