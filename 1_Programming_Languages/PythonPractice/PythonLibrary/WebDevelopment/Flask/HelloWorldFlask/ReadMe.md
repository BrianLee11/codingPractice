# Print "Hello World" using Flask

A minimal Flask app that prints "Hello World" and displays the current Flask version.

## 🧪 What It Does

When you run the app and visit `http://127.0.0.1:5000/` (by default) in your browser, you'll see:

```Hello World!```<br>
```The Flask version is: (your Flask version)```

Example: 
```Hello World!```<br> 
```The Flask version is: 3.1.0```


## 🚀 How to Run

1. Make sure you have Flask installed:
   `bash   pip install flask`

2. Run the app.py `python app.py`

3. On your console, open your browser and go to:
`http://127.0.0.1:5000/` (in my local computer)

- `127.0.0.1` is the `loopback address (localhost)`, meaning the app runs on your own computer.
- `5000` is the `default port` that Flask uses.
- So the URL means: `“Run this app on my own computer using port 5000.”`


## 📁 File Structure
```aiignore
HelloWorldFlask/
├── app.py
└── README.md
```

## 🧾 Code Overview (app.py)
```Python
from flask import Flask
import flask

print(flask.__version__)  # Print version in terminal

app = Flask(__name__)

def flaskVersion():
    return flask.__version__

@app.route('/')
def HelloWorld():
    return f"Hello World!<br>The Flask version is: {flaskVersion()}"

if __name__ == '__main__':
    app.run(debug=True)
```

## 🧠 Notes
- Use `<br>` instead of `\n` for new lines in HTML.
- The version is retrieved dynamically using flask.__version__.

---
Happy Flasking! 🔥