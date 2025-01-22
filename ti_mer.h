void IRAM_ATTR onTimer () {
  Step1 = !Step1 ;
  digitalWrite  (M1STEP, Step1 );
  if (Step1) {
    if (znak1 == M1_clock) schet1++; else schet1--;
  }
}

void IRAM_ATTR onTimer2 () {
  Step2 = !Step2 ;
  digitalWrite  (M2STEP, Step2 );
  if (Step2) {
    if (znak2 == M2_clock) schet2++; else schet2--;
  }
}

void IRAM_ATTR onTimer3 () {
  Step3 = !Step3 ;
  digitalWrite  (M3STEP, Step3 );
  if (Step3) {
    if (znak3 == M3_clock) schet3++; else schet3--;
  }
}
