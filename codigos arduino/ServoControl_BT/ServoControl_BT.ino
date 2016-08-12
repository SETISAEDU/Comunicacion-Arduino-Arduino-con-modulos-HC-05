//Codigo para el maestro
int potenciometro; //Variable para guardar el valor analogico
int pos = 0; //variable de posicion en grados

void setup() {
  //Rutina de arranque
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
  digitalWrite(13, HIGH);

  //Iniciacion del puerto serial para el Bluetooth
  Serial1.begin(115200);

  //Declaracion de interrupcion de los pulsadores
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(20, INPUT);
  pinMode(21, INPUT);
  // Interrupciones por flanco ascendente, se recomienda el uso de capacitor extra 
  // para evitar efectos de rebote
  attachInterrupt(digitalPinToInterrupt(2), Red, RISING);
  attachInterrupt(digitalPinToInterrupt(3), Green, RISING);
  attachInterrupt(digitalPinToInterrupt(20), White, RISING);
  attachInterrupt(digitalPinToInterrupt(21), Blue, RISING);
  
}

void loop() {
  //Lectura del pin analogico y envio de datos
  Serial1.print("*"); //Se envia un primer dato para activar el receptor
  potenciometro = analogRead(0); // Se lee el valor del potenciometro con el ADC del arduino
  pos = map(potenciometro, 0, 1023, 15, 180); //ajuste de valores maximos y minimos de angulo
  Serial1.print(String(pos)); // Se envia el valor deposicion

  //Retardo para evitar conflictos
  delay(100);
}

void Green() 
{
  noInterrupts(); /* Se desactivan las interrupcion para no aceptar nuevas peticiones 
                   * generadas por los rebotes
                   */
  Serial1.print("G"); //Se envia la letra asignada a el pulsador
  delay(200);  // Espera de estabilizacion del pulsador
  interrupts(); /* Se reactivan las interrupciones, para aceptar nuevas peticones 
                 * de los pulsadores
                 */
}
void Red() 
{
  noInterrupts();
  Serial1.print("R");
  delay(200);
  interrupts();
}
void White() 
{
  noInterrupts();
  Serial1.print("W");
  delay(200);
  interrupts();
}
void Blue() 
{
  noInterrupts();
  Serial1.print("B");
  delay(200);
  interrupts();
}


