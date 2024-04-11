from django.db import models

class FlameStatus(models.Model):
    STATUS_CHOICES = [
        ('Normal', 'Normal'),
        ('Low', 'Low'),
        ('No', 'No'),
    ]
    status = models.CharField(max_length=6, choices=STATUS_CHOICES, default='No')
    timestamp = models.DateTimeField(auto_now=True)

    def save(self, *args, **kwargs):
        # Ensure only one entry exists in the database.
        self.pk = 1
        super(FlameStatus, self).save(*args, **kwargs)
    
    def __str__(self):
        return f"Status: {self.status} at {self.timestamp}"
