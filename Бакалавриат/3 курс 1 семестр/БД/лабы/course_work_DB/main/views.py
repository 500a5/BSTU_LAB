from django.shortcuts import render
from django.http import HttpResponse
from .models import News, Events, Workers, Refences, Text
from django.views.generic import DetailView
from django.views.generic.base import View
from django.http import HttpResponseRedirect
from django.contrib.auth.forms import UserCreationForm, AuthenticationForm
from django.contrib.auth import logout, login
from django.contrib.auth.models import Group
from django.views.generic import FormView
from .forms import ReferencesForm
# def index (request):
#   return render(request, 'main/index.html')

def index(request):
    news = News.objects.all()
    return render(request, 'main/index.html', {'news': news})


def events(request):
    events = Events.objects.all()
    return render(request, 'main/events.html', {'events': events})


def workers(request):
    workers = Workers.objects.all()
    return render(request, 'main/workers.html', {'workers': workers})


def references(request):
    references = Refences.objects.all()
    return render(request, 'main/references.html', {'references': references})


class NewsDetailView(DetailView):
    model = News
    template_name = 'main/details_news.html'
    context_object_name = 'news_detail'


class EventsDetailView(DetailView):
    model = Events
    template_name = 'main/details_events.html'
    context_object_name = 'events_detail'

class WorkersDetailView(DetailView):
    model = Workers
    template_name = 'main/details_workers.html'
    context_object_name = 'workers_detail'

class RegisterFormView(FormView): # Форма для регистрации нового пользователя
    form_class = UserCreationForm
    success_url = '../login'

    template_name = 'main/register.html'

    def form_valid(self, form):
        new_user = form.save()
        new_user.groups.add(Group.objects.get(name='user'))
        new_user.save()
        return super(RegisterFormView, self).form_valid(form)

    def form_invalid(self, form):
        return super(RegisterFormView, self).form_invalid(form)


class LoginFormView(FormView): # Форма для авторизации нового пользователя
    form_class = AuthenticationForm
    success_url = "../"

    template_name = "main/login.html"

    def form_valid(self, form):
        self.user = form.get_user()
        login(self.request, self.user)
        return super(LoginFormView, self).form_valid(form)


class LogoutView(View): # Форма для выхода из аккаунта
    def get(self, request):
        logout(request)
        return HttpResponseRedirect("../")


def create(request):
    error = ''
    if request.method == 'POST':
        form = ReferencesForm(request.POST)
        if form.is_valid():
            text1 = Text(text=form.cleaned_data['text'])
            text1.save()
            ref = Refences(user=request.user, title=form.cleaned_data['title'], text=text1)
            ref.save()
        else:
            error='Ошибка заполнения формы'
    form = ReferencesForm()
    data = {
        'form': form,
        'error': error
    }
    return render(request, 'main/references.html', data)

