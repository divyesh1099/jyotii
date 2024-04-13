import pytest
from app import app  # Ensure your Flask app is importable

@pytest.fixture
def client():
    app.config['TESTING'] = True
    with app.test_client() as client:
        yield client

def test_get_flame_status(client):
    """ Test GET /flame-status """
    rv = client.get('/flame-status')
    assert rv.status_code == 200
    assert rv.json == {'status': 'unknown'}

def test_post_flame_status(client):
    """ Test POST /flame-status """
    rv = client.post('/flame-status', json={'status': 'active'})
    assert rv.status_code == 200
    assert rv.json == {'message': 'Status updated'}

    # Check if status is updated
    rv = client.get('/flame-status')
    assert rv.json == {'status': 'active'}
