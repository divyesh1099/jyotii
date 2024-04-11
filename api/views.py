from django.http import JsonResponse
from .models import FlameStatus
from django.views.decorators.csrf import csrf_exempt
from django.utils.decorators import method_decorator
from django.views import View
import json
class GetFlameStatusView(View):
    def get(self, request, *args, **kwargs):
        try:
            flame_status = FlameStatus.objects.get(pk=1)
            return JsonResponse({'status': flame_status.status, 'timestamp': flame_status.timestamp})
        except FlameStatus.DoesNotExist:
            return JsonResponse({'status': 'error', 'message': 'Status not found'})

@method_decorator(csrf_exempt, name='dispatch')
class UpdateFlameStatusView(View):
    def post(self, request, *args, **kwargs):
        try:
            data = json.loads(request.body)
            status = data.get('status')
        except json.JSONDecodeError:
            return JsonResponse({'status': 'error', 'message': 'Invalid JSON'})

        if status in [choice[0] for choice in FlameStatus.STATUS_CHOICES]:
            FlameStatus.objects.update_or_create(pk=1, defaults={'status': status})
            return JsonResponse({'status': 'success', 'message': 'Flame status updated'})
        return JsonResponse({'status': 'error', 'message': 'Invalid status'})
