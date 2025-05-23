# import library
from flask import Flask
import flask  # needed to access the version

# print the version of flask
print(flask.__version__) # as of now, version is 3.1.0

# create a flask object called app
app = Flask(__name__)

# designate the root directory
@app.route('/')
# launches this function when called the root directory
def HelloWorld():
    return f"Hello World!<br>The Flask version is: {flaskVersion()}"
# <br> is a HTML code to break the line. Similar to \n

# this function is not automatically run when app.route is visited
def flaskVersion():
    return flask.__version__

# When this file (app.py) is run, app is automatically run
if __name__ == '__main__':
    app.run(debug=True)

#When you run the app, the console will show the Flask version (e.g., 2.3.3), and visiting http://127.0.0.1:5000/ will show:
# Hello World!