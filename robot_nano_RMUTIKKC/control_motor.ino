void Motor(int spl,  int spr)
  {
    if(spl > 0 )
      {
        analogWrite(pwm_L, spl);
        digitalWrite(dir_L1, 1);
        digitalWrite(dir_L2, 0);
      }
    else if(spl < 0 )
      {
        analogWrite(pwm_L, -spl);
        digitalWrite(dir_L1, 0);
        digitalWrite(dir_L2, 1);
      }
    else
      {
        analogWrite(pwm_L, 0);
        digitalWrite(dir_L1, 0);
        digitalWrite(dir_L2, 0);
      }
    
    if(spr > 0 )
      {
        analogWrite(pwm_R, spl);
        digitalWrite(dir_R1, 1);
        digitalWrite(dir_R2, 0);
      }
    else if(spr < 0 )
      {
        analogWrite(pwm_R, -spr);
        digitalWrite(dir_R1, 0);
        digitalWrite(dir_R2, 1);
      }
    else
      {
        analogWrite(pwm_R, 0);
        digitalWrite(dir_R1, 0);
        digitalWrite(dir_R2, 0);
      }
  }