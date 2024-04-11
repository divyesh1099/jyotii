from channels.testing import WebsocketCommunicator
from django.test import TestCase
from .consumers import DiyaStatusConsumer
import json
class DiyaStatusConsumerTestCase(TestCase):
    async def test_consumer(self):
        # Path to your WebSocket endpoint
        communicator = WebsocketCommunicator(DiyaStatusConsumer.as_asgi(), '/ws/diya/status/')
        connected, subprotocol = await communicator.connect()
        self.assertTrue(connected)

        # Send a message to the server
        await communicator.send_to(text_data=json.dumps({'status': 'on'}))

        # Receive the response from the server
        response = await communicator.receive_from()
        self.assertEqual(json.loads(response), {'status': 'on'})

        # Close the connection
        await communicator.disconnect()
