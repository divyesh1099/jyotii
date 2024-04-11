from django.contrib import admin
from .models import FlameStatus
from django.utils.html import format_html

@admin.register(FlameStatus)
class FlameStatusAdmin(admin.ModelAdmin):
    list_display = ('status', 'timestamp')

    def decorated_status(self, obj):
        # Assign different colors based on the status value
        colors = {
            'Normal': 'green',
            'Low': 'orange',
            'No': 'red',
        }
        return format_html(
            '<span style="color: {};">{}</span>',
            colors.get(obj.status, 'black'),
            obj.status
        )
    
    decorated_status.short_description = 'Status'