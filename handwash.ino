/*all projects available
 * Auto handwash system using arduino
 * All code available in https://github.com/NirmalKnock/Auto_Hand_wash_system

 */
int pump =8;
const int trigPin = 7;
const int echoPin = 6;

float duration, distance;


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(pump,OUTPUT);
  digitalWrite(pump,HIGH);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
 
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);
if(distance<15){    //use can increase the distancen   
  /* Due to the TTL logic of relay and Arduino , I writen  digitalwrite as LOW, if after building your project ,if they works in opposite mode
  just change digitalWrite as Hign in (if condition ) and Low in else condition.
  Otherwise skip this comment*/
    digitalWrite(pump,LOW);
    delay(10000);   //You can increase the water timing
    
  }
  else{
    digitalWrite(pump,HIGH);
  }
}
