void checkSensors(bool Sens){
  digitalWrite(AnalogSEL,Sens);
  Sensors[Sens].value=analogRead(A0)-1;

  Sensors[Sens].stat= Sensors[Sens].value<1020;
  //Serial.print(Sensors[Sens].stat);
}

