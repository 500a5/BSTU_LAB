from . import views
from django.urls import path, include

urlpatterns = (
    path('', views.index, name='news'),
    path('events/', views.events, name='events'),
    path('workers/', views.workers, name='workers'),
    path('references/', views.create, name='references'),
    path('<int:pk>/', views.NewsDetailView.as_view(), name='news-detail'),
    path('events/<int:pk>/', views.EventsDetailView.as_view(), name='events-detail'),
    path('workers/<int:pk>/', views.WorkersDetailView.as_view(), name='workers-detail'),
    path('register', views.RegisterFormView.as_view(), name='register'),
    path('login', views.LoginFormView.as_view(), name='login'),
    path('logout', views.LogoutView.as_view(), name='logout'),
)
