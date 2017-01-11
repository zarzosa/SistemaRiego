#include <avr/wdt.h>
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 RTC;

boolean motor,v1,v2,v3,v4,v5,v6,v7,v8,v9;
int riegoEstado;
boolean bPresionado,bvPresionado;
boolean activarVRefuerzo1,activarVRefuerzo4,activarVRefuerzo5,activarVRefuerzo6;
int hi1,hf1,mi1,mf1,hi2,hf2,mi2,mf2,hi3,hf3,mi3,mf3,hi4,hf4,mi4,mf4,hi5,hf5,mi5,mf5,hi6,hf6,mi6,mf6,hi7,hf7,mi7,mf7,hi8,hf8,mi8,mf8,hi9,hf9,mi9,mf9;
int hi1b,hf1b,mi1b,mf1b,hi2b,hf2b,mi2b,mf2b,hi3b,hf3b,mi3b,mf3b,hi4b,hf4b,mi4b,mf4b,hi5b,hf5b,mi5b,mf5b,hi6b,hf6b,mi6b,mf6b,hi7b,hf7b,mi7b,mf7b,hi8b,hf8b,mi8b,mf8b,hi9b,hf9b,mi9b,mf9b;

void setup (){
  wdt_disable();
  Serial.begin(57600);
  Wire.begin();
  RTC.begin();
  
  ////// SETEO DEL REL¡OJ
  /// Setea el reloj con la hora de la PC (borrar barras linea inferior, cargar(flecha) y volver a poner // )
 // RTC.adjust(DateTime(__DATE__, __TIME__));
  /// Setea el reloj manualmente (year,month,day,hour,min,sec)
  //RTC.adjust(DateTime(2015,1,22,5,59,30));
   
  ////// ACTIVACION DEL RIEGO AUTOMATICO
  // true = Activado | false = Desactivado
  riegoEstado=0;
  
  ////// INICIO - CONFIGURACION DE HORARIOS (RIEGO AUTOMATICO)
  // Horas: 0 a 23 | Minutos: 0 a 59
  
  /// Valvula 1 - Releay 1A - Cable Celeste - Pico Solo Esquina
  // Hora Inicio (Primer Riego)
  hi1=6;
   // Minuto Inicio
  mi1=0;
  // Hora Fin
  hf1=6;
  // Minuto Fin
  mf1=15;
  
  // Hora Inicio  (Segundo Riego)
  hi1b=20;
   // Minuto Inicio
  mi1b=0;
  // Hora Fin
  hf1b=20;
  // Minuto Fin
  mf1b=15;
  
  /// Valvula 2 - Relay 2A - Cable Bordo Lavado - Quinta 1 Valvula Numero 1
  // Hora Inicio (Primer Riego)
  hi2=6;
  // Minuto Inicio
  mi2=20;
  // Hora Fin
  hf2=6;
  // Minuto Fin
  mf2=30;
  
  // Hora Inicio (Segundo Riego)
  hi2b=20;
  // Minuto Inicio
  mi2b=20;
  // Hora Fin
  hf2b=20;
  // Minuto Fin
  mf2b=30;
  
  /// Valvula 3 - Relay 3A - Cable Viejo 1 - Casa 1
  // Hora Inicio (Primer Riego)
  hi3=6;
  // Minuto Inicio
  mi3=40;
  // Hora Fin
  hf3=6;
  // Minuto Fin
  mf3=50;
  
  // Hora Inicio (Segundo Riego)
  hi3b=20;
  // Minuto Inicio
  mi3b=40;
  // Hora Fin
  hf3b=20;
  // Minuto Fin
  mf3b=50;
  
  /// Valvula 4 - Relay 4A - Cable Viejo 2 - Quinta 2 Valvula Frente Numero 1
  // Hora Inicio (Primer Riego)
  hi4=7;
  // Minuto Inicio
  mi4=10;
  // Hora Fin
  hf4=7;
  // Minuto Fin
  mf4=20;
  
  // Hora Inicio (Segundo Riego)
  hi4b=21;
  // Minuto Inicio
  mi4b=10;
  // Hora Fin
  hf4b=21;
  // Minuto Fin
  mf4b=20;
  
  /// Valvula 5 - Relay 4B - Cable Blanco - Quinta 3 Valvula Frente Numero 2
  // Hora Inicio (Primer Riego)
  hi5=7;
  // Minuto Inicio
  mi5=35;
  // Hora Fin
  hf5=7;
  // Minuto Fin
  mf5=45;
  
  // Hora Inicio (Segundo Riego)
  hi5b=21;
  // Minuto Inicio
  mi5b=35;
  // Hora Fin
  hf5b=21;
  // Minuto Fin
  mf5b=45;
  
  /// Valvula 6 - Relay 3B - Cable Negro - Manguera China y Pico Esquina
  // Hora Inicio (Primer Riego)
  hi6=8;
  // Minuto Inicio
  mi6=0;
  // Hora Fin
  hf6=8;
  // Minuto Fin
  mf6=40;
  
  // Hora Inicio (Segundo Riego)
  hi6b=22;
  // Minuto Inicio
  mi6b=00;
  // Hora Fin
  hf6b=22;
  // Minuto Fin
  mf6b=40;
  
  /// Valvula 7 - Relay 2B - Cable Verde - Quincho
  // Hora Inicio (Primer Riego)
  hi7=8;
  // Minuto Inicio
  mi7=44;
  // Hora Fin
  hf7=8;
  // Minuto Fin
  mf7=59;
  
  // Hora Inicio (Segundo Riego)
  hi7b=22;
  // Minuto Inicio
  mi7b=44;
  // Hora Fin
  hf7b=22;
  // Minuto Fin
  mf7b=59;
  
  /// Valvula 8 Relay 1B - Cable Amarillo - Frente Esquina
  // Hora Inicio (Primer Riego)
  hi8=9;
  // Minuto Inicio
  mi8=10;
  // Hora Fin
  hf8=9;
  // Minuto Fin
  mf8=20;
  
  // Hora Inicio (Segundo Riego)
  hi8b=23;
  // Minuto Inicio
  mi8b=10;
  // Hora Fin
  hf8b=23;
  // Minuto Fin
  mf8b=20;
  
    /// Valvula 9 - Relay 1C (Individual) - Cable Rosa - Desconectado
  // Hora Inicio (Primer Riego)
  hi9=9;
  // Minuto Inicio
  mi9=25;
  // Hora Fin
  hf9=9;
  // Minuto Fin
  mf9=26;
  
  // Hora Inicio (Segundo Riego)
  hi9b=23;
  // Minuto Inicio
  mi9b=25;
  // Hora Fin
  hf9b=23;
  // Minuto Fin
  mf9b=26;
  
  ////// FIN - CONFIGURACION DE HORARIOS (RIEGO AUTOMATICO)
  
  motor=false;
  v1=false;
  v2=false;
  v3=false;
  v4=false;
  
  bPresionado=false;
  bvPresionado=false;
  activarVRefuerzo1=true;
  activarVRefuerzo4=true;
  activarVRefuerzo5=true;
  activarVRefuerzo6=true;
  
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(15,INPUT);
  
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);

  if (! RTC.isrunning()) {
    Serial.println("RTC (Real Time Clock) no se encuentra en funcionamiento.");
  }
  
  wdt_enable(WDTO_2S);
}

void loop () {
    DateTime now = RTC.now();
    
    if(digitalRead(15)==HIGH){
      if(bPresionado==false){
        if(riegoEstado==0){
          riegoEstado=1;
          bPresionado=true;
        }else if(riegoEstado==1){
          riegoEstado=2;
          bPresionado=true;
        }else{
          riegoEstado=0;
          bPresionado=true;
        }
      }
      bPresionado=true;
    }else{
      bPresionado=false;
    }
    
    if(digitalRead(13)==HIGH){
      digitalWrite(13,LOW);
    }else{
      digitalWrite(13,HIGH);
    }
    
    if(v1 || v2 || v3 || v4 || v5 || v6 || v7 || v8 || v9){
      digitalWrite(6,LOW);
    }else{
      digitalWrite(6,HIGH);
    }
    
    if(v1){
      digitalWrite(10,LOW);
    }else{
      digitalWrite(10,HIGH);
      activarVRefuerzo1=true;
    }
    
    if(v2){
      digitalWrite(9,LOW);
    }else{
      digitalWrite(9,HIGH);
    }
    
    if(v3){
      digitalWrite(8,LOW);
    }else{
      digitalWrite(8,HIGH);
    }
    
    if(v4){
      digitalWrite(7,LOW);
    }else{
      digitalWrite(7,HIGH);
      activarVRefuerzo4=true;
    }
    
    if(v5){
      digitalWrite(2,HIGH);
    }else{
      digitalWrite(2,LOW);
      activarVRefuerzo5=true;
    }
    
    if(v6){
      digitalWrite(3,HIGH);
    }else{
      digitalWrite(3,LOW);
      activarVRefuerzo6=true;
    }
    
    if(v7){
      digitalWrite(4,HIGH);
    }else{
      digitalWrite(4,LOW);
    }
    
    if(v8){
      digitalWrite(5,HIGH);
      if(v1 && activarVRefuerzo1){
        digitalWrite(5,HIGH);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        activarVRefuerzo1=false;
      }
      if(v4 && activarVRefuerzo4){
        digitalWrite(5,HIGH);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        activarVRefuerzo4=false;
      }
      if(v5 && activarVRefuerzo5){
        digitalWrite(5,HIGH);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        activarVRefuerzo5=false;
      }
      if(v6 && activarVRefuerzo6){
        digitalWrite(5,HIGH);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        activarVRefuerzo6=false;
      }
    }else{
      digitalWrite(5,LOW);
      if(v1 && activarVRefuerzo1){
        digitalWrite(5,HIGH);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        activarVRefuerzo1=false;
      }
      if(v4 && activarVRefuerzo4){
        digitalWrite(5,HIGH);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        activarVRefuerzo4=false;
      }
      if(v5 && activarVRefuerzo5){
        digitalWrite(5,HIGH);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        activarVRefuerzo5=false;
      }
      if(v6 && activarVRefuerzo6){
        digitalWrite(5,HIGH);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        delay(1000);
        wdt_reset();
        activarVRefuerzo6=false;
      }
    }
    
    if(v9){
      digitalWrite(12,LOW);
    }else{
      digitalWrite(12,HIGH);
    }
    
    if(riegoEstado==0){
      if(now.hour()>=hi1 && now.hour()<=hf1 && now.minute()>=mi1 && now.minute()<=mf1){
        v1=true;
      }else if(now.hour()>=hi1b && now.hour()<=hf1b && now.minute()>=mi1b && now.minute()<=mf1b){
        v1=true;
      }else{
        v1=false;
      }
      
      if(now.hour()>=hi2 && now.hour()<=hf2 && now.minute()>=mi2 && now.minute()<=mf2){
        v2=true;
      }else if(now.hour()>=hi2b && now.hour()<=hf2b && now.minute()>=mi2b && now.minute()<=mf2b){
        v2=true;
      }else{
        v2=false;
      }
      
      if(now.hour()>=hi3 && now.hour()<=hf3 && now.minute()>=mi3 && now.minute()<=mf3){
        v3=true;
      }else if(now.hour()>=hi3b && now.hour()<=hf3b && now.minute()>=mi3b && now.minute()<=mf3b){
        v3=true;
      }else{
        v3=false;
      }
      
      if(now.hour()>=hi4 && now.hour()<=hf4 && now.minute()>=mi4 && now.minute()<=mf4){
        v4=true;
      }else if(now.hour()>=hi4b && now.hour()<=hf4b && now.minute()>=mi4b && now.minute()<=mf4b){
        v4=true;
      }else{
        v4=false;
      }
      
      if(now.hour()>=hi5 && now.hour()<=hf5 && now.minute()>=mi5 && now.minute()<=mf5){
        v5=true;
      }else if(now.hour()>=hi5b && now.hour()<=hf5b && now.minute()>=mi5b && now.minute()<=mf5b){
        v5=true;
      }else{
        v5=false;
      }
      
      if(now.hour()>=hi6 && now.hour()<=hf6 && now.minute()>=mi6 && now.minute()<=mf6){
        v6=true;
      }else if(now.hour()>=hi6b && now.hour()<=hf6b && now.minute()>=mi6b && now.minute()<=mf6b){
        v6=true;
      }else{
        v6=false;
      }
      
      if(now.hour()>=hi7 && now.hour()<=hf7 && now.minute()>=mi7 && now.minute()<=mf7){
        v7=true;
      }else if(now.hour()>=hi7b && now.hour()<=hf7b && now.minute()>=mi7b && now.minute()<=mf7b){
        v7=true;
      }else{
        v7=false;
      }
      
      if(now.hour()>=hi8 && now.hour()<=hf8 && now.minute()>=mi8 && now.minute()<=mf8){
        v8=true;
      }else if(now.hour()>=hi8b && now.hour()<=hf8b && now.minute()>=mi8b && now.minute()<=mf8b){
        v8=true;
      }else{
        v8=false;
      }
      
      if(now.hour()>=hi9 && now.hour()<=hf9 && now.minute()>=mi9 && now.minute()<=mf9){
        v9=true;
      }else if(now.hour()>=hi9b && now.hour()<=hf9b && now.minute()>=mi9b && now.minute()<=mf9b){
        v9=true;
      }else{
        v9=false;
      }
    }else if(riegoEstado==1){
      if(analogRead(A0)>=880 && analogRead(A0)<=895){
        if(bvPresionado==false){
          v1=!v1;
        }
        bvPresionado=true;
      }else if(analogRead(A0)>=910 && analogRead(A0)<=930){
        if(bvPresionado==false){
          v2=!v2;
        }
        bvPresionado=true;
      }else if(analogRead(A0)>=940 && analogRead(A0)<=960){
        if(bvPresionado==false){
          v3=!v3;
        }
        bvPresionado=true;
      }else if(analogRead(A0)>=980 && analogRead(A0)<=995){
        if(bvPresionado==false){
          v4=!v4;
        }
        bvPresionado=true;
      }else{
        bvPresionado=false;
      }
    }else{
      if(analogRead(A0)>=880 && analogRead(A0)<=895){
        if(bvPresionado==false){
          v5=!v5;
        }
        bvPresionado=true;
      }else if(analogRead(A0)>=910 && analogRead(A0)<=930){
        if(bvPresionado==false){
          v6=!v6;
        }
        bvPresionado=true;
      }else if(analogRead(A0)>=940 && analogRead(A0)<=960){
        if(bvPresionado==false){
          v7=!v7;
        }
        bvPresionado=true;
      }else if(analogRead(A0)>=980 && analogRead(A0)<=995){
        if(bvPresionado==false){
          v8=!v8;
        }
        bvPresionado=true;
      }else{
        bvPresionado=false;
      }
    }
    
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    
    if(riegoEstado==0){
      delay(1000);
    }else if(riegoEstado==1){
      delay(369);
    }else{
      delay(115);
    }
    wdt_reset();
}
