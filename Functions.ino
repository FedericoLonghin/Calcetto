void checkSensors(bool Sens){
  digitalWrite(AnalogSEL,Sens);
  Sensors[Sens].prevStat= Sensors[Sens].stat;
  Sensors[Sens].value=analogRead(A0)-1;

  Sensors[Sens].stat= Sensors[Sens].value<Sensors[Sens].threshold;
  //Serial.print(Sensors[Sens].stat);
}

void checkStat(bool Sens){
if(!Sensors[Sens].prevStat && Sensors[Sens].stat)
Sensors[Sens].score++;
requestNewScore(Sens);
}