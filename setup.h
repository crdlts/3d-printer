void setup1() {
  Serial.begin(115200);
  pinMode(SWITCH_ON, OUTPUT);
  pinMode(M1STEP, OUTPUT);
  pinMode(M1DIR, OUTPUT);
  pinMode(M2STEP, OUTPUT);
  pinMode(M2DIR, OUTPUT);
  pinMode(M3STEP, OUTPUT);
  pinMode(M3DIR, OUTPUT);

  ENmotor = disable;
  digitalWrite(SWITCH_ON, ENmotor);
  delay(100);

  digitalWrite(M1DIR, M1_anticlock);
  digitalWrite(M2DIR, M2_anticlock);
  digitalWrite(M3DIR, M3_anticlock);

  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, i, true);
  if (Flag_interrapt_m1)
    timerAlarmEnable(timer);

  timer2 = timerBegin(1, 80, true);
  timerAttachInterrupt(timer2, &onTimer2, true);
  timerAlarmWrite(timer2, i, true);
  if (Flag_interrapt_m2)
    timerAlarmEnable(timer2);

  timer3 = timerBegin(2, 80, true);
  timerAttachInterrupt(timer3, &onTimer3, true);
  timerAlarmWrite(timer3, i, true);
  if (Flag_interrapt_m3)
    timerAlarmEnable(timer3);
}
