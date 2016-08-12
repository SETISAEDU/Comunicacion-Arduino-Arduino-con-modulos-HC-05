//Codigo para el esclavo
//Se agraga la libreria para el uso de servos
#include <Servo.h>

Servo servo;  // Se crea el objeto para el control del servo
//Declaracion de pines para los LEDs y Buzzer
int LED1=2;
int LED2=3;
int LED3=4;
int BUZZER=5;
//Declaracion de variables
int pos = 90;    // Variable para el control de la posicion del servo

char BluetoothData;
//Variables de estado de los LEDs y buzzer
bool R_state=0;
bool G_state=0;
bool Y_state=0;
bool B_state=0;


void setup() {
   //Inciacion de salidas digitales
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  //Se ponen en alto todas las salidas
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,HIGH);
  digitalWrite(BUZZER,HIGH);
  
  servo.attach(9);  // Se  define un pin para el objeto
  //Iniciacion del puerto serial para el Bluetooth
  Serial1.begin(115200);
  delay(400);
  digitalWrite(BUZZER,LOW);
  digitalWrite(LED1,LOW);//indicador de Arduino listo y configurado
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
}

void loop() {
  //Espera de dato entrante del Bluetooth
    
   while(Serial1.available()>0){
    BluetoothData=Serial1.read(); 
    //Decision de accion a realizar
    if(BluetoothData=='R')
    {
      R_state=!R_state;  //Cambio de estado de la variable de control del led
      digitalWrite(LED1,R_state);
    }else if(BluetoothData=='G')
    {
      G_state=!G_state; //Cambio de estado de la variable de control del led
      digitalWrite(LED2,G_state); 
    }else if(BluetoothData=='W')
    {
      Y_state=!Y_state; //Cambio de estado de la variable de control del led
      digitalWrite(LED3,Y_state);
    }else if(BluetoothData=='B')
    {
      B_state=!B_state; //Cambio de estado de la variable de control del Buzzer
      digitalWrite(BUZZER,B_state);
    }
    pos=Serial1.parseInt();//Se recupera la siguente cantidad entera, despues del *
    servo.write(pos); //Se escribe la nueva posicion recibida
   }   
}

