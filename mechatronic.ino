#define IN1 6
#define IN2 7
#define IN3 9
#define IN4 10
#define ENA 5
#define ENB 8
#define R_S 4 // Sensor kanan
#define L_S 2 // Sensor kiri


void lurus(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
}
void kanan(){
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); 
  digitalWrite(IN4, LOW); 
  analogWrite(ENA, 125);
  analogWrite(ENB, 125);
}
void kiri(){
  digitalWrite(IN1, HIGH); 
  digitalWrite(IN2, LOW);  
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 125);
  analogWrite(ENB, 125);
}

void stop(){
  digitalWrite(IN1, LOW); 
  digitalWrite(IN2, LOW); 
  digitalWrite(IN3, LOW); 
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
}

void setup() {

  TCCR0B = TCCR0B & B11111000 | B00000010 ; // Mengubah frekuensi PWM menjadi 7812.5 Hz
  // Pada DC motor yang kita pakai, ketika dikasi value PWM yang terlalu kecil, motor tidak bergerak, tetapi ketika dikasi value PWM yang lebih besar
  // motor akan berputar terlalu kencang dan robot tidak terkontrol
  // Jadi, kami merubah frekuensi pada analogWrite. Jadi motor dapat lebih mudah dikontrol.

  pinMode(R_S, INPUT);
  pinMode(L_S, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
 
}

void loop() {
  int kiri = digitalRead(L_S);
  int kanan = digitalRead(R_S);

  if((kanan == 0)&&(kiri == 0)){lurus();}
  if((kanan == 1)&&(kiri == 0)){kanan();}
  if((kanan == 0)&&(kiri == 1)){kiri();}
  if((kanan == 1)&&(kiri == 1)){stop();}

}