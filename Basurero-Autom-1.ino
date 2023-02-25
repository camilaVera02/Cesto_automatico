//defino variable

const int AIA = 3;  //motor A

const int AIB = 11;

const int ledTest = 13;



int bDer = 9;
int rDer = 5;
int rIzq = 6;
int bIzq = 10;

//Inicio variables temporales
int disparo = 4;
int echo = 2;
long tiempoPulso;
float dstMedida;

//inicializo pines
void setup() {

Serial.begin(9600);
  pinMode(bDer, OUTPUT);
  pinMode(bIzq, OUTPUT);
  pinMode(rDer, OUTPUT);
  pinMode(rIzq, OUTPUT);

  pinMode(disparo, OUTPUT);
  pinMode(echo, INPUT);


  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
pinMode(ledTest, OUTPUT);



  digitalWrite(AIA, LOW);
  digitalWrite(AIB, LOW);

  digitalWrite(ledTest, LOW);
  digitalWrite(bDer, LOW);
  digitalWrite(bIzq, LOW);
  digitalWrite(rDer, LOW);
  digitalWrite(rIzq, LOW);

  digitalWrite(disparo, LOW);



  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
  digitalWrite(ledTest, HIGH);
  delay(500);
  digitalWrite(ledTest, LOW);
  delay(500);
  
}


//indico lo que se va a ejecutar
void loop() {


  digitalWrite(disparo, HIGH);
  delayMicroseconds(10);
  digitalWrite(disparo, LOW);

  tiempoPulso = pulseIn(echo, HIGH);
  dstMedida = 0.0340 / 2 * tiempoPulso;

  Serial.println("Tiempo / Distancia ");

  Serial.print(tiempoPulso);                              // codigo de los datos recibidos por el sensor ultrasonico y vuelca en monitor serie

  Serial.print(" / ");

  Serial.println(dstMedida);

  delay (50);




  if (dstMedida < 25) {
    abrir(3);
    delay(500);
    line();
    delay(100);                        //condicion que permite la automatizacion de la apertura de tapa y su cierre
    flash();
    delay(100);
    cerrar();
    parar();
    delay(1500);
  }
  else {
    intermitente();
    analogWrite(AIA, 0);
    analogWrite(AIB, 0);
    delay(10);
  }
}






// ------ Function

void abrir(int veces) {
  for (int j = 0; j < veces; j++) {
    analogWrite(AIA, 255);
    analogWrite(AIB, 0);
    delay(500);
  }
}




void parar()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  delay(500);
}

void cerrar()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, 200);
  delay(500);
}

void intermitente()
{
  analogWrite(rDer, 100);
  analogWrite(rIzq, 100);
  delay(100);
  analogWrite(rDer, 255);
  analogWrite(rIzq, 255);
  delay(100);                                            //juego de luces
  desv();
  delay(100);
  analogWrite(bDer, 100);
  analogWrite(bIzq, 100);
  delay(100);
  analogWrite(bDer, 255);
  analogWrite(bIzq, 255);
  delay(100);
  desb();
  delay(100);
}

void desv()
{
  analogWrite(rDer, 150);
  analogWrite(rIzq, 150);
  delay(100);
  analogWrite(rDer, 0);
  analogWrite(rIzq, 0);
  delay(50);
}


void desb()
{
  analogWrite(bDer, 150);
  analogWrite(bIzq, 150);
  delay(100);
  analogWrite(bDer, 0);
  analogWrite(bIzq, 0);
  delay(100);
}

void flash(){
 analogWrite(bIzq, 255);
 analogWrite(bDer, 255);
 delay(300);
  analogWrite(bIzq, 0);
 analogWrite(bDer, 0);
 delay(100);

 analogWrite(rDer, 255);
 analogWrite(rIzq, 255);
 delay(100);
  analogWrite(rIzq, 0);
 analogWrite(rDer, 0);
 delay(100);
}

void line()
{
 analogWrite(bIzq, 255);
 delay(80);
 analogWrite(bIzq, 0);
 delay(80);
 analogWrite(rIzq, 255);
 delay(80);
 analogWrite(rIzq, 0);
 delay(80);
 analogWrite(rDer, 255);
 delay(80);
 analogWrite(rDer, 0);
 delay(80);
 analogWrite(bDer, 255);
 delay(80);
 analogWrite(bDer, 0);
 delay(80);
 analogWrite(rDer, 255);
 delay(80);
 analogWrite(rDer, 0);
 delay(80);
  analogWrite(rIzq, 255);
  delay(80);
 analogWrite(rIzq, 0);
 delay(80);
  analogWrite(bIzq, 255);
  delay(80);
 analogWrite(bIzq, 0);
 delay(100);
}

