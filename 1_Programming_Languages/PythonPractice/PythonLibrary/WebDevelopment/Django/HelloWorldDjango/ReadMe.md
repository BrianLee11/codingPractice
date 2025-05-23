# 🐍 Print "Hello World" using Django

This guide shows you how to print a simple "Hello World" in your browser using Django.

---

## Step 1: Install Django

Install Django in your virtual environment (or globally if needed):

```bash
pip install django
```

📦 My Django version is 5.2

To verify the version:
`python -m django --version`

## Step 2: Create a Django Project

Use the `django-admin` tool to create a new Django project:

`django-admin startproject HelloWorldDjango`

### 📁 After this, your project folder will look like:
```aiignore
HelloWorldDjango/
├── manage.py
└── HelloWorldDjango/
    ├── __init__.py
    ├── asgi.py
    ├── settings.py
    ├── urls.py
    └── wsgi.py
```
-  manage.py is the command-line utility

- Inner HelloWorldDjango/ contains the settings and main project config

## Step 3: Navigate into Your Project Folder

`cd HelloWorldDjango`
Make sure you see `manage.py` in this directory.

## Step 4: Create a Django App
Now, let’s create an app called `hello`:

`python manage.py startapp hello`

This will create a new `hello/` folder with the following structure:

```aiignore
hello/
├── admin.py
├── apps.py
├── models.py
├── tests.py
├── views.py  👈 We'll write our "Hello World" here!
├── __init__.py
```

## Step 5: Add the App to Settings
Open `HelloWorldDjango/settings.py` and add `'hello'` to the `INSTALLED_APPS` list:
```aiignore
INSTALLED_APPS = [
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
    'hello',  # 👈 Add this line
]
```

## Step 6: Create a Simple View
Edit `hello/views.py` and add the following:
```Python
from django.http import HttpResponse
import django

def hello_world(request):
    return HttpResponse(f"Hello World from Django version {django.get_version()}")
```

## Step 7: Map the URL
Create a new file called `hello/urls.py` and add:
```Python
from django.urls import path
from . import views

urlpatterns = [
    path('', views.hello_world),
]
```
Then open `HelloWorldDjango/urls.py` and include your app:
```Python
from django.contrib import admin
from django.urls import path, include

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', include('hello.urls')),  # 👈 Route root URL to your app
]
```
## Step 8: Run the Development Server
`python manage.py runserver`

Visit in your browser:
👉 http://127.0.0.1:8000/

You should see:
`"Hello World from Django version (your Django version)"`

In my computer, I see:
`"Hello World from Django version 5.2"`
---

## Done!
Now you're running a live Django app! 🎉



