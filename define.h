#define BTN_STOP_ALARM
//koordinateXandY переменные
int enter = 0;
int enter2 = 0;
static float error_old = 0;
static float VPIDabsold = 0;
float VPIDabs;
float f_dX;
float f_dY;
float error;
const char * path =  ("/kords.txt");

//запуск траектории
bool en_traectory = false;

//включение мотора
const bool disable = true;
const bool enable = false;
volatile bool ENmotor = disable;

//шаги мотора
bool Step1 = false;
bool Step2 = false;
bool Step3 = false;
uint32_t i = 10000000;
int Vcom;
int Vcom2;
int Vcom3;
hw_timer_t * timer = NULL;
hw_timer_t * timer2 = NULL;
hw_timer_t * timer3 = NULL;
int schet1;
int schet2;
static int32_t loc_schet1 = 0;
static int32_t loc_schet2 = 0;
static int32_t loc_schet3 = 0;
bool byowl1 = 0;
bool byowl2 = 1;
int kol = 0;

static uint32_t ttecmillis = 0;

String input_string = "";
String input_string2 = "";
String input_string3 = "";

//работа мотора
bool M1_clock = 1;
bool M1_anticlock = 0;
bool M2_clock = 0;
bool M2_anticlock = 1;
bool M3_clock = 1;
bool M3_anticlock = 0;
volatile bool znak1 = M1_anticlock;
volatile bool znak2 = M2_anticlock;
volatile bool znak3 = M3_clock;


//для первого двигателя
bool c = 0;
uint32_t told = 0;
float vtec;
float vmax = 20000;
float vold = 0;
uint32_t ttec;
const float vstop = 500;
const float qvstop = vstop * vstop;
long deltt;
uint32_t T = 0;
float VtecN;
uint32_t dT = 5000;

//для второго двигателя
bool c2 = 0;
uint32_t told2 = 0;
float vtec2;
float vold2 = 0;
uint32_t ttec2;
float a2 = 40000;
long deltt2;
uint32_t t1 = 0;
uint32_t t3 = 0;
float VtecN2;
//ускорения
const float a = 40000;
const float a_2 = a * 2;
const float a_dt_05 = a * float(dT) * 0.000001 * 0.5;
float a_dT;



bool Flag_interrapt_m1 = true;
bool Flag_interrapt_m2 = true;
bool Flag_interrapt_m3 = true;

// Пины
const int SWITCH_ON = 13;
const int M1STEP = 26;
const int M2STEP = 14;
const int M3STEP = 4;
const int M1DIR = 25;
const int M2DIR = 27;
const int M3DIR = 15;


// Координаты
int32_t Y;
int32_t X;
float Xmir = 0;
float Ymir = 0;

// Какая то непонятная
float v1;
float v2;
float errorL1new;
float errorL1old;
//float errorL2new;
//float errorL2old;
int xtec;
float k = 50;
float koef = 0.1;
float speederror1;
//float speederror2;
const double deltaT = 0.01;
// TRYHARD THADACHA

float Vx;
float Vy;
float dX;
float dY;

//3 ось
int schet3;
int32_t Z;
float f_dZ;
float vtec3;

bool mas = false;
int32_t point = 0;
int32_t Xmas, Ymas, Zmas;
File  file;
