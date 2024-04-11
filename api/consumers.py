from channels.generic.websocket import AsyncWebsocketConsumer
import json

class DiyaStatusConsumer(AsyncWebsocketConsumer):
    async def connect(self):
        await self.accept()

    async def disconnect(self, close_code):
        pass

    async def receive(self, text_data):
        text_data_json = json.loads(text_data)
        status = text_data_json['status']

        # Handle the message
        await self.send(text_data=json.dumps({
            'status': status
        }))
