# Flame Status Monitor

This Flask application provides a simple backend service to monitor and update the flame status of a device, such as a lamp or a candle. It is deployed on Heroku, offering a REST API that can be accessed remotely. The app uses CORS to allow cross-origin requests, enabling integration with web or mobile frontends.

## Features

- **Get Flame Status**: Allows retrieval of the current flame status via a GET request.
- **Update Flame Status**: Supports updating the flame status via a POST request.

## Technologies

- Flask: A lightweight WSGI web application framework.
- Flask-CORS: A Flask extension for handling Cross-Origin Resource Sharing (CORS), making cross-origin AJAX possible.
- Heroku: A platform as a service (PaaS) that enables developers to build, run, and operate applications entirely in the cloud.

## Getting Started

### Prerequisites

- Python 3.8 or later
- Flask
- Flask-CORS
- Git
- Heroku CLI

### Installation

1. Clone the repository:
   ```bash
   git clone https://your-repository-url
   cd your-repository-directory
   ```

2. Set up a virtual environment:
   ```bash
   python -m venv venv
   source venv/bin/activate  # On Windows use `venv\Scripts\activate`
   ```

3. Install the required dependencies:
   ```bash
   pip install Flask Flask-CORS gunicorn
   ```

4. Run the application locally:
   ```bash
   flask run
   ```

### Deployment to Heroku

1. Log in to your Heroku account and create a new app:
   ```bash
   heroku login
   heroku create your-app-name
   ```

2. Add git remote for Heroku to local repository:
   ```bash
   git remote add heroku https://git.heroku.com/your-app-name.git
   ```

3. Deploy your application:
   ```bash
   git add .
   git commit -am "Initial deployment"
   git push heroku master
   ```

4. Ensure that at least one instance of the app is running:
   ```bash
   heroku ps:scale web=1
   ```

5. Visit your deployed application:
   ```bash
   heroku open
   ```

## API Endpoints

- **GET /flame-status**
  - Description: Retrieve the current status of the flame.
  - Response: `{"status": "current-status"}`

- **POST /flame-status**
  - Description: Update the flame status.
  - Payload: `{"status": "new-status"}`
  - Response: `{"message": "Status updated"}` or `{"error": "No status provided"}`

## Contributing

Feel free to fork this repository, make changes, and submit a pull request if you have improvements to offer.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Papa
- Navratri
- Meri Berojgari
- Moti❤️
