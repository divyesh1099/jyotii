# Generated by Django 5.0.4 on 2024-04-11 13:49

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Flame',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('status', models.CharField(choices=[('Normal', 'Normal'), ('Low', 'Low'), ('No', 'No')], default='Normal', max_length=6)),
                ('timestamp', models.DateTimeField(auto_now_add=True)),
            ],
        ),
    ]
