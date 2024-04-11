from websocket import create_connection
import json

ws = create_connection("ws://127.0.0.1:8000/ws/diya/status/")

# Send a status message
ws.send(json.dumps({'status': 'on'}))

# Receive server response
result = ws.recv()
print("Received: " + result)

ws.close()
