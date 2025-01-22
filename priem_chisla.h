bool String_to_double(char chh)
{
  Serial.write("00");
  if (((chh > 47) && (chh < 58)) || (chh == 45) || (chh == 46) || (chh == 32))
  {
    if ((kol == 1) && (chh == 32) && (input_string2.length() > 0)) kol = 2;
    if ((kol == 0) && (chh == 32) && (input_string.length() > 0)) kol = 1;
    if ((kol == 0) && (chh != 32)) input_string += chh;
    if ((kol == 1) && (chh != 32)) input_string2 += chh;
    if ((kol == 2) && (chh != 32)) input_string3 += chh;
  }
  else {
    if (chh == 'e') {
      if (ENmotor != enable)
      {
        ENmotor = enable;
        digitalWrite(SWITCH_ON, ENmotor);
      }
    }

    if (chh == 'd') {
      if (ENmotor != disable)
      {
        ENmotor = disable; digitalWrite(SWITCH_ON, ENmotor);
        en_traectory = false;
      }
    }

    if (chh == 'T') {
      en_traectory = true;
      Serial.println('Y');
    }

    if (chh == 't') {
      en_traectory = false;
      Serial.println('F');
    }

    if (chh == 'm') {
      mas = true;
      Serial.println('M');
    }

    if (chh == 'n') {
      mas = false;
      point = 0;
      Serial.println('N');
    }
    if (chh == 10) enter2++;
  }

  if ((chh == 10) && (input_string.length() > 0)) return true;
  else return false;
}

void zapros(int32_t &X, int32_t &Y, int32_t &Z)
{
  if (String_to_double(Serial.read()))
  {
    Xmir = input_string.toFloat();
    input_string = ""; //Обнуляем
    Ymir = input_string2.toFloat();
    input_string2 = ""; //Обнуляем
    Z = input_string3.toFloat();
    input_string3 = ""; //Обнуляем
    kol = 0;// Счетчик
    convertor2 (Xmir, Ymir, X, Y);
    while (Serial.available()) Serial.read();
    Serial.print("Xmir=");
    Serial.print(Xmir);
    Serial.print("  Ymir=");
    Serial.print(Ymir);
    Serial.print(" *** X=");
    Serial.print(X);
    Serial.print("  Y=");
    Serial.println(Y);
    if (mas) point++;
  }
}

void kords(int32_t &X, int32_t &Y, int32_t &Z)
{
  //cartasd_test();

  if ((fabs(X - schet1) <= 10) && (fabs(Y - schet2) <= 10) && (fabs(Z - schet3) <= 10))
  {

    if (file.available()) String_to_double(file.read());

    while (!String_to_double(file.read()) && (file.available()))
    {}
    //   {
    //if (enter2 == enter)
    Xmir = input_string.toFloat();
    input_string = ""; //Обнуляем
    Ymir = input_string2.toFloat();
    input_string2 = ""; //Обнуляем
    Z = input_string3.toFloat();
    input_string3 = ""; //Обнуляем
    kol = 0;// Счетчик
    convertor2 (Xmir, Ymir, X, Y);
    //if (schet1 != X)
    // while (Serial.available()) Serial.read();
    Serial.print("Xmir=");
    Serial.print(Xmir);
    Serial.print("  Ymir=");
    Serial.print(Ymir);
    Serial.print(" *** X=");
    Serial.print(X);
    Serial.print("  Y=");
    Serial.println(Y);
    if (mas) point++;
  }
}
