from django.contrib import admin
from .models import News, Events, Workers, Text, Refences

admin.site.register(News)
admin.site.register(Workers)
admin.site.register(Events)
admin.site.register(Text)
admin.site.register(Refences)