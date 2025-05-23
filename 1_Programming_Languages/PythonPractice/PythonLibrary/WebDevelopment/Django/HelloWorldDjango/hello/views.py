from django.http import HttpResponse
import django  # ✅ Import the Django module

def hello_world(request):
    return HttpResponse(f"Hello World! <br> Django version is: {django.get_version()}")
