# 📢 Printing "Hello World" on HTML using JavaScript

A beginner-friendly example that demonstrates how to print **"Hello World"** to a web page using plain **JavaScript** and **HTML** — no frameworks or build tools involved.

---

## 📄 What This Project Does

This mini-project:
- Renders the message `"Hello World from JavaScript!"` directly into a web page
- Demonstrates how JavaScript interacts with the **DOM** using `document.getElementById`
- Provides a simple starting point for exploring **frontend development**

---

## ⚙️ Why Use JavaScript?

JavaScript is the **language of the web**. While:
- **HTML** provides structure,
- and **CSS** provides style,  
  👉 **JavaScript adds interactivity and logic.**

---

### ✅ Key Benefits of JavaScript

- 🖱️ **Client-side interactivity** – respond to user actions like clicks and input
- ⚡ **No compilation needed** – runs directly in any browser
- 🌍 **Universally supported** – works across all modern browsers
- 🔁 **Dynamic DOM manipulation** – update or insert content in real time
- 🔌 **Foundation of modern frameworks** – like React, Vue, and Angular

---

## 🌐 What is the DOM?

The **DOM (Document Object Model)** is a tree-like structure that represents your HTML document in memory — allowing JavaScript to **access, modify, and interact** with the page dynamically.

When a browser loads an HTML file, it **creates the DOM**, which acts as a **live representation** of the document.

---

### 🔍 Why Is the DOM Important?

- JavaScript can use the DOM to:
    - Select elements (`getElementById`, `querySelector`)
    - Change content (`textContent`, `innerHTML`)
    - React to user input (clicks, typing, etc.)
    - Add or remove elements dynamically

---

### 🧱 Example: DOM Structure from HTML

Given this HTML:

```html
<html>
  <head>
    <title>Page</title>
  </head>
  <body>
    <h1>Hello World</h1>
    <p>This is the DOM</p>
  </body>
</html>
```

💡 Example: Accessing the DOM with JavaScript
`document.querySelector('h1').textContent = "Hello from JS!";`

This selects the first `<h1>` and changes its content — showing the power of the DOM + JavaScript.

---
## 🛠 Technologies Used

- **HTML5**
- **JavaScript (ES6+)**
- No frameworks, no libraries — just native browser features

---

## ▶️ How to Run

1. Open `index.html` in any modern web browser
2. You should see the message:

```text
Hello World from JavaScript!

