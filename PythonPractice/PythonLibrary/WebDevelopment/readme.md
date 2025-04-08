# 🌐 Python Libraries for Web Development

This section introduces Python web development frameworks:
- **Flask** 
- **Django**
- etc

You’ll find simple examples and project templates.

---

## 🚀 Flask

> A lightweight, flexible, and minimalist web framework.

### 🔧 Features:
- Micro-framework with minimal setup
- Great for beginners and small to medium apps
- Explicit routing and configuration
- Easy to integrate with other tools

### 📂 Example:
Check the [`Flask/HelloWorldFlask`](./Flask/HelloWorldFlask) folder for a minimal "Hello World" example.

```python
from flask import Flask

app = Flask(__name__)

@app.route('/')
def hello():
    return "Hello World!"

if __name__ == '__main__':
    app.run(debug=True)
```
## 🚀 Django

> A high-level web framework that includes everything you need to build robust, production-ready web apps.

## 🔧 Features:
- Full-stack framework with ORM, templating, admin, authentication, etc.
- Encourages convention over configuration
- Built-in security features and scalability
- Ideal for large, complex projects

## Object-relational mapping

ORM stands for Object-Relational Mapping.

In the context of Django (and other frameworks), ORM is a feature that allows developers to interact with a database using Python objects and classes instead of writing raw SQL queries.

**In simpler terms:**
- ORM "maps" database tables to Python classes.
- Rows become instances (objects), and columns become attributes.

**For example, in Django:**
```Python
# models.py
from django.db import models

class Book(models.Model):
    title = models.CharField(max_length=100)
    author = models.CharField(max_length=100)
```

This will automatically:
- Create a `Book` table in the database.
- Allow you to do things like:

```Python
# Create a new book
Book.objects.create(title="1984", author="George Orwell")

# Query books
books = Book.objects.filter(author="George Orwell")
```

So, when someone says "Django is a full-stack framework with ORM," 
it means Django comes with this powerful database layer built-in—so 
**you don’t need to manually write most of the SQL queries.**

### 📂 Example:
(Django example or starter app folder can be added here later)

---
## ⚖️ Flask vs. Django

| Feature          | Flask                                    | Django                                |
|------------------|-------------------------------------------|----------------------------------------|
| **Type**         | Micro-framework                          | Full-stack framework                   |
| **Project Structure** | Minimal                               | Structured, batteries-included         |
| **Flexibility**  | Very flexible                            | Convention-driven                      |
| **ORM**          | Optional (e.g., SQLAlchemy)              | Built-in (Django ORM)                  |
| **Admin Panel**  | Manual (or extensions)                   | Comes built-in                         |
| **Learning Curve** | Easier for beginners                    | Steeper, but powerful                  |
| **Use Case**     | Small to medium apps                     | Medium to large apps                   |


--- 
Happy Web Developing! ✨