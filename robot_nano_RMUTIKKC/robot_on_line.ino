void read_sensor()
  {
    Serial.print("sensor_R: ");
    Serial.print(analogRead(sensor_R));
    Serial.print("   sensor_L: ");
    Serial.print(analogRead(sensor_L));
    Serial.println("  ");
  }

void fw(int sl, int sr, int offset)
  {
    while(1)
      {
        int R = analogRead(sensor_R);
        int L = analogRead(sensor_L);
        int md_R = (min_sensor_R + max_sensor_R)/2;
        int md_L = (min_sensor_L + max_sensor_L)/2;
        if(R > md_R && L < md_L)
          {
            Motor(sl/3, sr);
          } 
        else if(R < md_R && L > md_L)
          {
            Motor(sl, sr/3);
          } 
        else if(R > md_R && L > md_L)
          {
            Motor(sl, sr);
          } 
        else
          {
            Motor(-sl, -sr);
            delay(offset);
            Motor(0, 0);
            delay(offset);
          }   
            // read_sensor();

      }
  }