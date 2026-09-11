
float readDistanceCM()
  {
    // สร้างคลื่น Ultrasonic
    delay(30);
    digitalWrite(Trig, LOW);
    delayMicroseconds(2);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);
    // รอรับสัญญาณ Echo สูงสุด 30 ms
    unsigned long duration =
        pulseIn(Echo, HIGH, 30000UL);
    // ไม่พบวัตถุหรือหมดเวลา
    if (duration == 0)
      return -1.0;
    // ระยะทาง = เวลา × ความเร็วเสียง ÷ 2
    return duration * 0.0343 / 2.0;
  }

void move_untrasonic(int sl, int sr)
  {
    while(1)
      {
        float distance = readDistanceCM();
        if(distance < 15)
          {
            Motor(-sl, -sr);
            delay(30);
            Motor(0, 0);
            delay(300);

            Motor(-sl, -sr);
            delay(200);
            Motor(0, 0);
            delay(300);

            Motor(-sl, sr);
            delay(250);
            Motor(0, 0);
            delay(500);
           
                break;
           
            
          }
        else
          {
            Motor(sl, sr);
          }
      }
            
  }