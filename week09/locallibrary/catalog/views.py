from django.shortcuts import render
from django.http import HttpResponse #自己加的

# Create your views here.
def index(requests):
    return HttpResponse("server test")