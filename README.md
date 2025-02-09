# Advanced Web IoT

![Project Status](https://img.shields.io/badge/status-completed-brightgreen) [![License](https://img.shields.io/badge/license-MIT-blue)](./LICENSE) [![Certificate](https://img.shields.io/badge/Certificate-Available-blue)](https://github.com/user-attachments/files/18723289/Sertifikat_2.pdf)

Advanced IoT project using the MQTT protocol with a Laravel 11-based website. This project is part of an advanced Internet of Things (IoT) training program organized by **Nusabot**.

## **Illustrations**
<img src="https://github.com/user-attachments/assets/88b4315f-1696-49f0-b915-1de6f4ca06d6" alt="Illustration" style="width: 600px; height: auto;">

Explanation of the MQTT protocol, consisting of an MQTT Client publishing, MQTT Broker, and an MQTT Client subscribing.

## **Technologies Used**
- **Shiftr Io**
- **MQTT Protocol**
- **Wokwi**
- **Laravel 11**

## **Features**
- **Real-time Data Storage**: Stores real-time data from microcontrollers into an SQL database.
- **Device Identification**: Captures device serial numbers such as ESP32.
- **Sensor Data Handling**: Logs and monitors sensor readings.
- **Servo Control & LCD Display**: Controls a servo motor and displays temperature sensor readings on an LCD.
- **Web Monitoring & Control**: Allows users to monitor and control components via a web interface.
- **Temperature Monitoring**: Monitors temperature using the DHT22 sensor.

## **Demo**

### **Wokwi Simulation**
<img src="https://github.com/user-attachments/assets/0a51d00e-70d0-45c2-aa7b-ad5b0e5b9d65" alt="Wokwi Simulation" style="width: 600px; height: auto;">

### **Website Interface**
<img src="https://github.com/user-attachments/assets/0d9bb901-cc07-486f-b2e5-04b8ec7c848a" alt="Website Interface" style="width: 600px; height: auto;">
<img src="https://github.com/user-attachments/assets/e7d2f38b-c140-44c2-95e6-85d7a0a54536" alt="Website Interface" style="width: 600px; height: auto;">
<img src="https://github.com/user-attachments/assets/4e96d672-5d70-467a-a959-6c99b9a242d1" alt="Website Interface" style="width: 600px; height: auto;">
<img src="https://github.com/user-attachments/assets/aae27d08-e544-4483-bdde-3c258143e147" alt="Website Interface" style="width: 600px; height: auto;">

### **Cloud Shiftr Io**
<img src="https://github.com/user-attachments/assets/edba1fe5-30c3-4530-ac70-a51a6863e554" alt="Shiftr Io Dashboard" style="width: 600px; height: auto;">

## **Setup**

1. **Clone the repository**
   ```sh
   git clone https://github.com/your-username/advanced-web-iot.git
   cd advanced-web-iot
   ```
2. **Install dependencies**
   ```sh
   composer install
   ```
3. **Configure environment variables**
   ```sh
   cp .env.example .env
   php artisan key:generate
   ```
   - Update database credentials in `.env`
   - Configure MQTT broker details

4. **Run database migrations**
   ```sh
   php artisan migrate
   ```

5. **Start the Laravel server**
   ```sh
   php artisan serve
   ```

6. **Set up the MQTT broker and connect ESP32 devices**

## **Usage**
1. Connect an ESP32 device to the MQTT broker.
2. Use the web dashboard to monitor sensor data and control devices.
3. Send MQTT messages to control servo motors and other peripherals.

## **Project Status**
This project is **completed** and will not be further developed.

## **Contributions**
Contributions are welcome! Feel free to open issues or submit pull requests.

## **License**
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
