import 'dart:async';
import 'dart:convert';
import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;
import 'package:flutter_local_notifications/flutter_local_notifications.dart';

void main() {
  runApp(MyApp());
  // initializeNotifications();
}

// void initializeNotifications() async {
//   FlutterLocalNotificationsPlugin flutterLocalNotificationsPlugin = FlutterLocalNotificationsPlugin();
//   AndroidInitializationSettings initializationSettingsAndroid = AndroidInitializationSettings('app_icon');
//   IOSInitializationSettings initializationSettingsIOS = IOSInitializationSettings();
//   InitializationSettings initializationSettings = InitializationSettings(
//     android: initializationSettingsAndroid,
//     iOS: initializationSettingsIOS,
//   );
//   await flutterLocalNotificationsPlugin.initialize(initializationSettings);
// }

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Jyotii',
      theme: ThemeData(
        brightness: Brightness.dark,
        primarySwatch: Colors.blue,
        visualDensity: VisualDensity.adaptivePlatformDensity,
      ),
      home: FlameStatusPage(),
    );
  }
}

class FlameStatusPage extends StatefulWidget {
  @override
  _FlameStatusPageState createState() => _FlameStatusPageState();
}

class _FlameStatusPageState extends State<FlameStatusPage> {
  String flameStatus = 'No';
  Timer? timer;
  FlutterLocalNotificationsPlugin? localNotifications;

  @override
  void initState() {
    super.initState();
    localNotifications = FlutterLocalNotificationsPlugin();
    timer = Timer.periodic(Duration(seconds: 5), (_) => fetchFlameStatus());
  }

  @override
  void dispose() {
    timer?.cancel();
    super.dispose();
  }

  Future<void> fetchFlameStatus() async {
    try {
      final response = await http.get(Uri.parse('http://jyotiiflask-0b739e38df99.herokuapp.com/flame-status'));
      if (response.statusCode == 200) {
        setState(() {
          flameStatus = json.decode(response.body)['status'];
        });
        if (flameStatus != 'Normal') {
          sendNotification(flameStatus);
        }
      }
    } catch (e) {
      print('Failed to fetch data: $e');
    }
  }

  Future<void> sendNotification(String status) async {
    const androidDetails = AndroidNotificationDetails(
      'channelId',
      'Local Notifications',
      channelDescription: 'Channel to test notifications',
      importance: Importance.max,
      priority: Priority.high,
    );
    const iosDetails = IOSNotificationDetails();
    await localNotifications!.show(
      0,
      'Flame Alert',
      'Flame status is $status',
      NotificationDetails(android: androidDetails, iOS: iosDetails),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            // Add a heading, white text, and a refresh button
            Text(
              'Flame Status',
              style: TextStyle(fontSize: 24, color: Colors.white),
            ),
            SizedBox(height: 20),
            AnimatedContainer(
              duration: Duration(milliseconds: 500),
              height: 200,
              width: 200,
              decoration: BoxDecoration(
                image: DecorationImage(
                  image: AssetImage('assets/${getImageForStatus(flameStatus)}'),
                  fit: BoxFit.cover,
                ),
              ),
            ),
            SizedBox(height: 20),
            Text(
              'Current Status: $flameStatus',
              style: TextStyle(fontSize: 18, color: Colors.white),
            ),
            SizedBox(height: 20),
            ElevatedButton(
              onPressed: () => fetchFlameStatus(),
              child: Text('Refresh Status'),
            ),
          ],
        ),
      ),
    );
  }

  String getImageForStatus(String status) {
    switch (status) {
      case 'Normal':
        return 'flame_normal.png';
      case 'Low':
        return 'flame_low.png';
      case 'No':
        return 'flame_off.png';
      default:
        return 'flame_unknown.png'; // Default case for 'Unknown' status
    }
  }
}