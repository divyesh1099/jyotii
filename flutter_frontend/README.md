# Jyotii Flutter App

The Jyotii Flutter App is designed to interface with the Jyotii Flask backend to monitor and update the status of a flame, such as a diya (lamp). This application makes periodic requests to the backend and updates the UI accordingly. It also provides local notifications if the flame status changes to an abnormal state.

## Features

- **Real-Time Monitoring**: Periodically fetches the flame status every 5 seconds.
- **Notification Alerts**: Sends local notifications if the flame status is not 'Normal'.
- **User Interface**: Provides a simple and intuitive interface to view and refresh the flame status.

## Technologies

- Flutter: For building the iOS and Android applications.
- http: For making network requests.
- flutter_local_notifications: For managing local notifications.

## Getting Started

### Prerequisites

- Flutter installed on your machine.
- An Android or iOS device or emulator.
- Access to the backend Flask server.

### Installation

1. Clone the repository:
   ```bash
   git clone https://your-repository-url
   cd your-flutter-project-directory
   ```

2. Install dependencies:
   ```bash
   flutter pub get
   ```

3. Run the app:
   ```bash
   flutter run
   ```

## How it Works

- The app starts by displaying the current flame status, fetched from the Flask server.
- It updates the status every 5 seconds and displays a local notification if the status is abnormal.

## Configuration

Ensure that the backend URL in the `fetchFlameStatus` function points to your deployed Flask server. Modify the URL accordingly:
```dart
Uri.parse('http://your-flask-server-url/flame-status')
```

## Building and Deploying

To build the app for production, you can use the following commands:

- For Android:
  ```bash
  flutter build apk
  ```

- For iOS:
  ```bash
  flutter build ios
  ```

Ensure that you have the proper signing configurations for iOS deployment.

## Contributing

If you have suggestions for improving the app, please fork the repository and submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Papa
- Navratri
- Meri Berojgari
- Moti❤️