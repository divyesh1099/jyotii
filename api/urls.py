from django.urls import path, include
from rest_framework.routers import DefaultRouter
from .views import *

urlpatterns = [
    path('get_status/', GetFlameStatusView.as_view(), name='get_status'),
    path('update_status/', UpdateFlameStatusView.as_view(), name='update_status'),
]
