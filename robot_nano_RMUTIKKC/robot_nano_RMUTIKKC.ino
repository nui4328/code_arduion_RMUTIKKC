// กำหนด pin มอเตอร์ซ้าย
#define pwm_L 10
#define dir_L1 7
#define dir_L2 8
// กำหนด pin มอเตอร์ซ้าย
#define pwm_R 9
#define dir_R1 6
#define dir_R2 5
// กำหนด pin button
#define button A0
// กำหนด pin buzzer
#define buzzer 12
// กำหนด pin untrasonic
#define Echo 2
#define Trig 3

// กำหนด pin sensor analog
#define sensor_L A2
#define sensor_R A3

// ================= ตั้งค่าความเร็ว =================
int baseSpeed = 100;
int maxSpeed  = 180;

// ================= ค่า PID =================
float Kp = 0.50;
float Ki = 0.003;
float Kd = 0.50;

float error = 0;
float previousError = 0;
float integral = 0;
float derivative = 0;
float PID_output = 0;

// ================= ค่าคาลิเบรตเซนเซอร์ =================
// เปลี่ยนตามค่าที่วัดได้จริง
int min_sensor_L = 250;
int max_sensor_L = 950;

int min_sensor_R = 250;
int max_sensor_R = 950;

// true  = พื้นดำอ่านค่าได้มาก
// false = พื้นดำอ่านค่าได้น้อย
bool blackIsHigh = true;

unsigned long lastPIDTime = 0;
const unsigned long PID_INTERVAL = 10;  // คำนวณทุก 10 ms




void setup() 
  {
      robot_begin();
      ///////////////////////////////////////////////////////เริ่มโปรแกรม

      wait_button();
      
      lineFollowPID();
      
      ///////////////////////////////////////////////////////จบโปรแกรม
  }

void loop() {
  //   move_untrasonic(120, 150);
  //  float distance = readDistanceCM();

  // if (distance >= 0)
  // {
  //   Serial.print("Distance: ");
  //   Serial.print(distance, 1);
  //   Serial.println(" cm");
  // }

  if (millis() - lastPIDTime >= PID_INTERVAL)
  {
    lastPIDTime = millis();
    lineFollowPID();
  }

}
