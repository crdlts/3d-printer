void convertor1(int32_t schet1, int32_t schet2, float &Xmir, float &Ymir)
{
  Xmir = float (-schet1 - schet2) * 0.5;
  Ymir = float (-schet1 + schet2) * 0.5;
}

void convertor2(float Xmir, float Ymir, int32_t &Mschet1, int32_t &Mschet2)
{
  Mschet1 = round (-Xmir - Ymir);
  Mschet2 = round (Ymir - Xmir);
}
