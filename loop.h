int koordinateXandY(float dt) 
{
  f_dX = float(X - schet1);
  f_dY = float(Y - schet2);
  f_dZ = float(Z - schet3);
  error = sqrt(f_dX * f_dX + f_dY * f_dY + f_dZ * f_dZ);
  if (error > 10.0)
  {
    VPIDabs = sqrt(error * a_2 + qvstop) - a_dt_05;
    VPIDabs = constrain(VPIDabs, 0, vmax);
//    VPIDabsold = VPIDabs;
    Vcom = (f_dX / error) * VPIDabs;
    Vcom2 = (f_dY / error) * VPIDabs;
    Vcom3 = (f_dZ / error) * VPIDabs;
  }
  else
  {
    Vcom = 0;
    Vcom2 = 0;
    Vcom3 = 0;
   // VPIDabsold = 0;
  }
  return 0;
}


void loop1() {
  ttec = micros();
  if (Serial.available() > 0) {
    if (mas == false) {
      zapros(X, Y, Z);
    }
  }
    if (mas == true) {
    kords(X, Y, Z);
    }
 
  // zapros(Xmas, Ymas, Zmas);
  //vvod();
  if (ttecmillis < millis())
  {
    ttecmillis = millis() + 100;
    if ((loc_schet1 != schet1) || (loc_schet2 != schet2) || (loc_schet3 != schet3))
    {
      Serial.print(schet1); Serial.print(' '); Serial.print(schet2);Serial.print(' '); Serial.print(schet3); Serial.print(' '); Serial.print(' '); Serial.print(vtec); Serial.print(' '); Serial.print(' '); Serial.println(vtec2);Serial.print(' '); Serial.println(vtec3);
      loc_schet1 = schet1;
      loc_schet2 = schet2;
      loc_schet3 = schet3;
    }
  }

  if (ttec > (told + dT))
  {
    deltt = ttec - told;
    told = ttec;
    a_dT = a * float(deltt) * 0.000001;
    if (en_traectory) analitic_traectory();
    koordinateXandY (a_dT);
   // os3();
    vtec = constrain(Vcom, vtec - a * float(deltt) * 0.000001, vtec + a * float(deltt) * 0.000001);
    vtec2 = constrain(Vcom2, vtec2 - a * float(deltt) * 0.000001, vtec2 + a * float(deltt) * 0.000001);
    vtec3 = constrain(Vcom3, vtec3 - a * float(deltt) * 0.000001, vtec3 + a * float(deltt) * 0.000001);
    if (vtec >= 0)
    {
      if (znak1 == M1_anticlock) {
        znak1 = M1_clock;
        digitalWrite(M1DIR, M1_clock);
      }
    }
    else
    {
      if ( znak1 == M1_clock) {
        znak1 = M1_anticlock;
        digitalWrite(M1DIR, M1_anticlock);
      }
    }
    if (vtec2 >= 0)
    {
      if (znak2 == M2_anticlock) {
        znak2 = M2_clock;
        digitalWrite(M2DIR, M2_clock);
      }
    }
    else
    {
      if (znak2 == M2_clock) {
        znak2 = M2_anticlock;
        digitalWrite(M2DIR, M2_anticlock);
      }
    }
if (vtec3 >= 0)
    {
      if (znak3 == M3_anticlock) {
        znak3 = M3_clock;
        digitalWrite(M3DIR, M3_clock);
      }
    }
    else
    {
      if ( znak3 == M3_clock) {
        znak3 = M3_anticlock;
        digitalWrite(M3DIR, M3_anticlock);
      }
    }


    if (fabs(vtec) > 1.0)
    {
      T = uint32_t (500000.0 / (fabs(vtec)));
      T = constrain (T, 10, 100000000);
      timerAlarmWrite (timer, T, true);
    }
    else
    {
      if (Flag_interrapt_m1 == true)
      {
        T = 100000000;
        timerAlarmWrite (timer, T, true);
      }
    }
    if (fabs(vtec2) > 1.0)
    {
      t1 = uint32_t (500000.0 / (fabs(vtec2)));
      t1 = constrain(t1, 10, 100000000);
      timerAlarmWrite(timer2, t1, true);
    }
    else
    {
      if (Flag_interrapt_m2 == true)
      {
        uint32_t t1 =  100000000;
        timerAlarmWrite(timer2, t1, true);
      }
    }

    
    if (fabs(vtec3) > 1.0)
    {
      t3 = uint32_t (500000.0 / (fabs(vtec3)));
      t3 = constrain (t3, 10, 100000000);
      timerAlarmWrite (timer3, t3, true);
    }
    else
    {
      if (Flag_interrapt_m3 == true)
      {
        t3 = 100000000;
        timerAlarmWrite (timer3, t3, true);
      }
    }
  }
}
