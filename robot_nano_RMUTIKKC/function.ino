void robot_begin()
  {
    Serial.begin(9600);
      pinMode(pwm_L, OUTPUT);
      pinMode(dir_L1, OUTPUT);
      pinMode(dir_L2, OUTPUT);

      pinMode(pwm_R, OUTPUT);
      pinMode(dir_R1, OUTPUT);
      pinMode(dir_R2, OUTPUT);

      pinMode(button, INPUT);
      pinMode(buzzer, OUTPUT);

      pinMode(sensor_L, INPUT);
      pinMode(sensor_R, INPUT);

      pinMode(Trig, OUTPUT);
      pinMode(Echo, INPUT);

      digitalWrite(Trig, LOW);

       lastPIDTime = millis();
  }

void wait_button()
  {
    tone(buzzer, 1000, 150);
    delay(200);
    tone(buzzer, 2000, 150);
    delay(800);
    while(digitalRead(button) == 0)
      {
         Serial.println(digitalRead(button));
         delay(30);
      }
    tone(buzzer, 2000, 350);
    delay(500);
  }

