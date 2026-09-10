
// =====================================================
// เดินตามเส้นด้วย PID
// =====================================================
void lineFollowPID()
{
  int rawL = analogRead(sensor_L);
  int rawR = analogRead(sensor_R);

  float valueL = readCalibratedSensor(
    rawL,
    min_sensor_L,
    max_sensor_L
  );

  float valueR = readCalibratedSensor(
    rawR,
    min_sensor_R,
    max_sensor_R
  );

  // เมื่อค่าทั้งสองเท่ากัน error จะเท่ากับ 0
  error = valueL - valueR;

  // P
  float proportional = error;

  // I พร้อมจำกัดค่า ป้องกัน Integral windup
  integral += error;
  integral = constrain(integral, -5000.0f, 5000.0f);

  // D
  derivative = error - previousError;
  previousError = error;

  PID_output =
      (Kp * proportional)
    + (Ki * integral)
    + (Kd * derivative);

  PID_output = constrain(
    PID_output,
    -(float)maxSpeed,
    (float)maxSpeed
  );

  // error เป็นบวก หมายถึงเซนเซอร์ซ้ายพบเส้นมากกว่า
  int speedL = baseSpeed - PID_output;
  int speedR = baseSpeed + PID_output;

  speedL = constrain(speedL, -maxSpeed, maxSpeed);
  speedR = constrain(speedR, -maxSpeed, maxSpeed);

  Motor(speedL, speedR);

  printSensor(
    rawL,
    rawR,
    valueL,
    valueR,
    error,
    PID_output,
    speedL,
    speedR
  );
}

// =====================================================
// แปลงค่าเซนเซอร์ให้อยู่ในช่วง 0-100
// 0   = พื้นขาว
// 100 = เส้นดำ
// =====================================================
float readCalibratedSensor(int raw, int minValue, int maxValue)
{
  if (maxValue <= minValue)
  {
    return 0;
  }

  raw = constrain(raw, minValue, maxValue);

  float value =
    ((float)(raw - minValue) * 100.0f) /
    ((float)(maxValue - minValue));

  if (!blackIsHigh)
  {
    value = 100.0f - value;
  }

  return constrain(value, 0.0f, 100.0f);
}

// =====================================================
// แสดงค่าบน Serial Monitor
// =====================================================
void printSensor(
  int rawL,
  int rawR,
  float valueL,
  float valueR,
  float err,
  float output,
  int speedL,
  int speedR
)
{
  Serial.print("Raw L:");
  Serial.print(rawL);

  Serial.print(" R:");
  Serial.print(rawR);

  Serial.print(" | Sensor L:");
  Serial.print(valueL, 1);

  Serial.print(" R:");
  Serial.print(valueR, 1);

  Serial.print(" | Error:");
  Serial.print(err, 1);

  Serial.print(" PID:");
  Serial.print(output, 1);

  Serial.print(" | Motor L:");
  Serial.print(speedL);

  Serial.print(" R:");
  Serial.println(speedR);
}
// จุดที่ต้องปรับก่อนใช้งาน:

// ตั้ง min_sensor_L, max_sensor_L, min_sensor_R, max_sensor_R ตามค่าพื้นขาวและเส้นดำจริง

// ถ้าเส้นดำอ่านค่าได้น้อย ให้เปลี่ยนเป็น blackIsHigh = false

// ถ้าหุ่นยนต์หักเลี้ยวผิดด้าน ให้เปลี่ยนเป็น:

// int speedL = baseSpeed + PID_output;
// int speedR = baseSpeed - PID_output;
// แนวทางปรับ PID:

// ส่ายซ้าย–ขวาแรง: ลด Kp หรือเพิ่ม Kd

// เข้าโค้งไม่ทัน: เพิ่ม Kp หรือลด baseSpeed

// ตอบสนองช้า: เพิ่ม Kp

// กระตุกเมื่อเจอขอบเส้น: ลด Kd

// ช่วงแรกแนะนำตั้ง Ki = 0 ก่อน แล้วจูน Kp กับ Kd ให้เรียบร้อย จากนั้นจึงเพิ่ม Ki ทีละน้อยครับ


