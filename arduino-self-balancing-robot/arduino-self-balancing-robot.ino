#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

// Motor Driver Pins
int ENA = 11;
int IN1 = 7;
int IN2 = 6;
int IN3 = 5;
int IN4 = 4;
int ENB = 10;

// PID Parameters
float Kp = 15.0;
float Ki = 0.5;
float Kd = 3.0;

float setpoint = 20.0;

float error, last_error = 0.0;
float integral = 0.0;
float derivative;
float output;

// Timing Variables
unsigned long last_time;
float elapsed_time;

void setup() {
    Serial.begin(9600);

    Wire.begin();  // SDA = A4, SCL = A5
    mpu.initialize();

    if (!mpu.testConnection()) {
        Serial.println("MPU6050 connection failed!");
        while (1);
    }

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

    last_time = millis();
}

void loop() {
    // Waktu Sampling
    unsigned long current_time = millis();
    elapsed_time = (current_time - last_time) / 1000.0;
    last_time = current_time;

    // Baca Data MPU6050
    int16_t ax, ay, az, gx, gy, gz;
    mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    // Hitung Sudut dari Accelerometer
    float angle = atan2(ay, az) * 180 / PI;

    // PID Controller
    error = setpoint - angle;
    integral += error * elapsed_time;
    derivative = (error - last_error) / elapsed_time;

    output = (Kp * error) +
             (Ki * integral) +
             (Kd * derivative);

    last_error = error;

    // Batasi Output PWM (0–255)
    int pwm = constrain(abs(output), 0, 255);

    if (output > 0) {
        // Robot miring ke depan → tarik mundur
        maju(pwm);
    } else {
        // Robot miring ke belakang → dorong maju
        mundur(pwm);
    }

    // Debug Serial Monitor
    Serial.print("Angle: ");
    Serial.print(angle);
    Serial.print(" | Output: ");
    Serial.println(output);

    delay(10); // Waktu sampling
}

// =====================
// Fungsi Kontrol Motor
// =====================

void maju(int pwm) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    analogWrite(ENA, pwm);
    analogWrite(ENB, pwm);
}

void mundur(int pwm) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    analogWrite(ENA, pwm);
    analogWrite(ENB, pwm);
}