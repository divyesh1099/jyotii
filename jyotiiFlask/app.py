from flask import Flask, request, jsonify
from flask_cors import CORS
app = Flask(__name__)
CORS(app)
# This will act as our simple database.
flame_status = {'status': 'unknown'}

@app.route('/flame-status', methods=['GET'])
def get_flame_status():
    return jsonify(flame_status)

@app.route('/flame-status', methods=['POST'])
def update_flame_status():
    new_status = request.json.get('status')
    if new_status:
        flame_status['status'] = new_status
        return jsonify({'message': 'Status updated'}), 200
    return jsonify({'error': 'No status provided'}), 400

if __name__ == '__main__':
    app.run()
