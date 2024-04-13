# Jyotii

Jyotii is a comprehensive IoT project designed to monitor the status of a Navratri diya (lamp) ensuring it remains lit continuously for 9 days. The system includes an Arduino Nano with an old bootloader CH340, a NodeMCU ESP8266MOD, and an analog flame sensor. The backend server is built with Flask and deployed on Heroku, while the frontend is developed in Flutter.

## Working Demo
[Live Demo Video](https://1drv.ms/v/s!Av9ohgmVUvX8bw-YeF7jfEV9EG0?e=XjxeQm)

## Features

- **Real-Time Monitoring**: Provides live status updates of the Navratri Diya via a Flask server.
- **IoT Integration**: Utilizes Arduino and NodeMCU ESP8266MOD for precise and non-invasive diya monitoring.
- **Cross-Platform App**: A user-friendly Flutter frontend for monitoring and interacting with the IoT device.
- **Scalable Server**: The Flask server can handle connections efficiently and is deployed on Heroku for high availability.

## Project Structure

- `flutter_frontend/`: Contains all the Flutter application code.
- `jyotiiFlask/`: Contains the Flask server application code.

## Getting Started

### Prerequisites

- Python 3.8 or later
- Flask 1.1 or later
- Arduino IDE
- Flutter 2.0 or later

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/divyesh1099/jyotii.git
   cd jyotii
   ```

2. Set up the Flask server:

   - Navigate to the `jyotiiFlask` directory:
     ```bash
     cd jyotiiFlask
     ```

   - Install the required dependencies:
     ```bash
     pip install -r requirements.txt
     ```

   - Run the Flask server:
     ```bash
     flask run
     ```

3. Set up the Flutter app:

   - Navigate to the `flutter_frontend` directory:
     ```bash
     cd flutter_frontend
     ```

   - Install Flutter dependencies:
     ```bash
     flutter pub get
     ```

   - Run the app:
     ```bash
     flutter run
     ```

### Configuration

- **Environment Variables**: Configure necessary environment variables such as `DATABASE_URL` and `SECRET_KEY`.
- **IoT Device Setup**: Ensure the Arduino and NodeMCU are programmed with the correct firmware which can be found in the `firmware` directory.

## Deployment

Refer to the included deployment guide for detailed instructions on deploying the Flask server to Heroku and setting up the Flutter app for production use.

## Contributing

Contributions are welcome! Please feel free to fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Papa
- Navratri
- Meri Berojgari
- Moti❤️
