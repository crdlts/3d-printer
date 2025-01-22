const int32_t nombers_points = 100;
int32_t Xmassiv[nombers_points] {};
int32_t Ymassiv[nombers_points] {};
int32_t Zmassiv[nombers_points] {};

void vvod(){
  if ((Xmassiv[point] != Xmas) || (Ymassiv[point] != Ymas) || (Zmassiv[point] != Zmas)){
  Xmassiv[point] = Xmas;
  Ymassiv[point] = Ymas;
  Zmassiv[point] = Zmas;
  Serial.print(Xmassiv[point]);
  Serial.print(' ');
  Serial.print(Ymassiv[point]);
  Serial.print(' ');
  Serial.print(Zmassiv[point]);
  Serial.print(' ');
  Serial.println(point);
  }
}

void analitic_traectory()
{
  static int tec_point = 0;
  float XmirTEC, YmirTEC;
  int32_t M1point, M2point;
  static int Xsled=0, Ysled=0, Zsled=0;
     //Переводим Мировые координаты в Моторные счетчики

     
  convertor2(float(Xmassiv[tec_point]), float(Ymassiv[tec_point]), M1point, M2point);

  //если в пределах 10 точек по обоим координатам, то можно двигаться дальше
  if ((abs(M1point - schet1) < 50) && (abs(M2point - schet2) < 50) && abs(schet3) < 50)
  {
    tec_point++;
    if (tec_point >= nombers_points) tec_point = 0;
    //Переводим Мировые координаты в Моторные счетчики
    convertor2(float(Xmassiv[tec_point]), float(Ymassiv[tec_point]), X, Y);
    Z = Zmassiv[tec_point];
    Xsled=X; Ysled=Y; 
      Serial.print("Xmir=");
      Serial.print(Xmassiv[tec_point]);
      Serial.print("  Ymir=");
      Serial.print(Ymassiv[tec_point]);
      Serial.print(" *** X=");
      Serial.print(X);
      Serial.print("  Y=");
      Serial.println(Y);
      Serial.print("  Z=");
      Serial.println(Z);
  }
  else
  {
    if(Xsled!=X) X=Xsled;
    if(Ysled!=Y) Y=Ysled;
  }
}
