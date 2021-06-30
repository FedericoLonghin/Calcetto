
//PIN
#define LedStripData D8
#define BtnSL D7
#define BtnCLk D6
#define BtnQ7 D5
#define BuzzPin D4
#define AnalogSEL D3


struct Sensor{
  long int threshold=1200;
  bool stat;
  bool prevStat;
  bool isAvailable;
  char* ReqURL="";
 int value;
 int score;
};
struct Sensor Sensors[2];
int nReq;
bool currentAnalogSensor;

