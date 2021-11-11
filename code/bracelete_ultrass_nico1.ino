#define triggerPin 4
#define echoPin 5

int buzzer = 10;

//#define motor 8


//#define distance_max 200
//int distance_min = 10;

void setup(){

  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  distance(0,200);
  delay(100);
}

  int medicao_distancia(){
  long tempo, distancia;

  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  tempo = pulseIn(echoPin, HIGH);
  distancia = tempo / 58;

  return distancia;
  
  }
  void distance(int a, int b){
    int limiteDistancia = medicao_distancia();

   if ((limiteDistancia > a) && (limiteDistancia < b)) {
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
tone(buzzer, 1000);


} else {
digitalWrite(8, LOW); 
digitalWrite(9, LOW);
noTone(buzzer);

}
}