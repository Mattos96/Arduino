/*
***************************************************************

Led piscar usando millis
Elaborado por: Felipe
Data 17/09/2020
Descrição: Led com função Millis

********************************************************
*/
byte vm1Pin = 13; // Uma variável 'byte' armazena valores numéricos de 8-bit sem sinal, de 0 a 255.
byte am1Pin = 9; // Uma variável 'byte' armazena valores numéricos de 8-bit sem sinal, de 0 a 255.
byte vd1Pin = 6; // Uma variável 'byte' armazena valores numéricos de 8-bit sem sinal, de 0 a 255.
byte vm2Pin = 5; // Uma variável 'byte' armazena valores numéricos de 8-bit sem sinal, de 0 a 255.   
byte am2Pin= 4; // Uma variável 'byte' armazena valores numéricos de 8-bit sem sinal, de 0 a 255.
byte vd2Pin= 3; // Uma variável 'byte' armazena valores numéricos de 8-bit sem sinal, de 0 a 255.

byte piscaPisca = 2; // especificando pino

unsigned long vmTime = 5000; // vaiavel de tempo
unsigned long amTime = 2000; // vaiavel de tempo
unsigned long vdTime = 3000; // vaiavel de tempo

unsigned long semaforoTime = 0; // vaiavel de tempo

unsigned long piscaTempo = 500; // vaiavel de tempo
unsigned long piscaDecorrido =0; // vaiavel de tempo

bool status = 0; // variavel

void setup()
{
 pinMode(vm1Pin, OUTPUT); // Especificando pino de saida
 pinMode(am1Pin, OUTPUT); // Especificando pino de saida
 pinMode(vd1Pin, OUTPUT); // Especificando pino de saida
 pinMode(vm2Pin, OUTPUT); // Especificando pino de saida
 pinMode(am2Pin, OUTPUT); // Especificando pino de saida
 pinMode(vd2Pin, OUTPUT); // Especificando pino de saida

 pinMode (piscaPisca, INPUT_PULLUP); // Especificando pino de saida

 
}

void loop()
{
if (!digitalRead(piscaPisca)) // IF realiza a condição
{
  // ************** SEMAFORO A *************
  if ((millis() - semaforoTime) < vmTime)  // IF realiza a condição
  {
  digitalWrite(am1Pin, LOW);
  digitalWrite(am2Pin, LOW);
  digitalWrite(vm1Pin, HIGH);

  
  
  }
 else if ((millis() - semaforoTime) < (vmTime + vdTime ))// else realiza a condição de IF
  
 {
 digitalWrite(vm1Pin, LOW); 
 digitalWrite(vd1Pin, HIGH);
 
 }
    else if ((millis() - semaforoTime) < (vmTime + vdTime + amTime) ) //else realiza a condição de IF
  
 {
 digitalWrite(vd1Pin, LOW);
 digitalWrite(am1Pin, HIGH);
 
 }
    // ************** SEMAFORO B *************

   if ((millis() - semaforoTime) < vdTime) // IF realiza a condição
  {
  digitalWrite(vd2Pin, HIGH);
  }
 else if ((millis() - semaforoTime) < vdTime + amTime) //else realiza a condição de IF
  
 {
 digitalWrite(vd2Pin, LOW);
 digitalWrite(am2Pin, HIGH);
 
 }
    else if ((millis() - semaforoTime) < vdTime + amTime + vmTime) //else realiza a condição de IF
  
 {
 digitalWrite(am2Pin, LOW);
 digitalWrite(vm2Pin, HIGH);
 
 }
   else  //else realiza a condição de IF  
  {
  digitalWrite(am1Pin, LOW);
  digitalWrite(vm2Pin, LOW);
  semaforoTime = millis();
  }
}
  else  //else realiza a condição de IF
  {
    digitalWrite(vd1Pin, LOW);
    digitalWrite(am1Pin, LOW);
    digitalWrite(vm1Pin, LOW);
    digitalWrite(vd2Pin, LOW);
    digitalWrite(am2Pin, LOW);
    digitalWrite(vm2Pin, LOW);
  
    if ((millis() - piscaDecorrido) > piscaTempo) // IF realiza a condição
    
    {
    piscaDecorrido = millis();
      status =!status;
    }
    digitalWrite (am1Pin, status);
    digitalWrite (am2Pin, status);
    semaforoTime = millis();
    
  }

}