/*
    Codigo para la utilizacion del módulo HC-SR04 de electrodragon.
    http://www.electrodragon.com/w/index.php?title=HC-SR04_Ultrasonic_sensor
    
*/

#define EchoPin A1          //Declaramos pines del sensor
#define TrigPin A0

long duration;              //Variable de duracion de pulso Eco
long HR_dist = 0;           //Variable distancia calculada


//    SETUP

void setup()
{
  Serial.begin(9600);       // Configuramos comunicacion serie
  
  pinMode(TrigPin, OUTPUT); //Configuramos pines del sensor
  pinMode(EchoPin, INPUT);
  
}

//    LOOP

void loop()
{
  getDistance();
}

//    FUNCION DISTANCIA

void getDistance()
{
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(TrigPin, LOW);
  
  duration = pulseIn(EchoPin, HIGH);    //Medimos la duracion del pulso de Eco
  HR_dist = duration / 58.2;
}
  
