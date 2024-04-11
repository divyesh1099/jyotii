from django.urls import path 
from . import views

app_nmae='home'

urlpatterns=[
    path('', views.index, name='index'),
]