# Jyotii

Jyotii is a Django-based application designed to interact with IoT devices for tracking the status of a diya (lamp), ensuring it remains lit throughout the Navratri festival period. This project showcases real-time communication between a server and IoT devices, leveraging Django Channels for WebSocket communication.

## Features

- **Real-Time Updates**: Utilizes WebSockets for instant status updates from IoT devices.
- **IoT Integration**: Seamlessly connects with IoT devices monitoring diya status.
- **Scalable Architecture**: Built on Django Channels, allowing for easy scaling to handle multiple device connections.
- **User-Friendly Dashboard**: Provides a web interface for users to monitor and control the diya status.

## Getting Started

### Prerequisites

- Python 3.8 or later
- Django 3.2 or later
- Django Channels
- A Redis server for Channels layer

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/divyesh1099/jyotii.git
   cd jyotii
   ```

2. Set up a virtual environment and activate it:
   ```bash
   python -m venv venv
   source venv/bin/activate # On Windows use `venv\Scripts\activate`
   ```

3. Install the required dependencies:
   ```bash
   pip install -r requirements.txt
   ```

4. Set up the Django database:
   ```bash
   python manage.py migrate
   ```

5. Run the development server:
   ```bash
   python manage.py runserver
   ```

6. Access the web application at `http://localhost:8000`.

### Configuration

- **Environment Variables**: Configure the necessary environment variables for production, including `DATABASE_URL`, `REDIS_URL`, and `SECRET_KEY`.

- **Static and Media Files**: Set up AWS S3 for handling static and media files in production as described in the project setup guide.

## Deployment

Refer to the project setup guide for detailed instructions on deploying to AWS using Elastic Beanstalk and setting up RDS and S3 for a production environment.

## Contributing

We welcome contributions! Open a PR, we'll act upon it asap. 

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Papa
- Moti❤️