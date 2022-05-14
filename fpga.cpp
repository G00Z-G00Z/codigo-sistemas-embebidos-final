int LED_Luz_Artificial = 7;
int Persiana1 = 6;
int Persiana2 = 5;
int Ventana1 = 4;
int Ventana2 = 3;
int Abanico = 2;
int Bombilla_Calor = 0;

int Estado_Ventana;
int Estado_Persiana;

int bit0 = 8;
int bit1 = 9;
int bit2 = 10;
int bit3 = 11;

void setup(){

  	pinMode(LED_Luz_Artificial, OUTPUT);
    pinMode(Persiana1, OUTPUT);
    pinMode(Persiana2, OUTPUT);
    pinMode(Ventana1, OUTPUT);
 	pinMode(Ventana2, OUTPUT);
    pinMode(Abanico, OUTPUT);
  	pinMode(Bombilla_Calor, OUTPUT);
	pinMode(bit0, INPUT);
  	pinMode(bit1, INPUT);
  	pinMode(bit2, INPUT);
  	pinMode(bit3, INPUT);
    Serial.begin(9600);
}

void loop(){
  //Lectura de los bits del Arduino Central
  bit0=digitalRead(8);
  bit1=digitalRead(9);
  bit2=digitalRead(10);
  bit3=digitalRead(11);
  
  //Ver cual de los 15 estado esta el sistema
  Serial.print(bit0);
  Serial.print(bit1);
  Serial.print(bit2);
  Serial.print(bit3);
  Serial.print("    ");
  Serial.print(Estado_Persiana);
  Serial.println(Estado_Ventana);
  //Estado 0
  while(bit0 == 0 && bit1 == 0 && bit2 == 0 && bit3 == 0){
  	bit0=digitalRead(8);
  	bit1=digitalRead(9);
  	bit2=digitalRead(10);
  	bit3=digitalRead(11);
    digitalWrite(LED_Luz_Artificial,HIGH);
	digitalWrite(Bombilla_Calor,LOW);
    digitalWrite(Abanico,LOW);
	
	if(Estado_Ventana == 1){
		for(int x; x<500; x++){
			digitalWrite(Ventana1,HIGH); //Checar PWM
		}
		Estado_Ventana = 0;
	}
	digitalWrite(Ventana1,LOW);
	
	if(Estado_Persiana == 0){
		for(int x; x<500; x++){
			digitalWrite(Persiana2,HIGH);
		}
		Estado_Persiana = 1;
	}
	digitalWrite(Persiana2,LOW);
	
	break;
  }
  //Estado 1
  while(bit0 == 0 && bit1 == 0 && bit2 == 0 && bit3 == 1){
  	bit0=digitalRead(8);
  	bit1=digitalRead(9);
  	bit2=digitalRead(10);
  	bit3=digitalRead(11);
    digitalWrite(LED_Luz_Artificial,HIGH);
	digitalWrite(Bombilla_Calor,LOW);
    digitalWrite(Abanico,LOW);
	
	if(Estado_Ventana == 0){
		for(int x; x<500; x++){
			digitalWrite(Ventana2,HIGH);
		}
		Estado_Ventana = 1;
	}
	digitalWrite(Ventana2,LOW);
	if(Estado_Persiana == 0){
		for(int x; x<500; x++){
			digitalWrite(Persiana2,HIGH);
		}
		Estado_Persiana = 1;
	}
	digitalWrite(Persiana2,LOW);
	
	break;
  }
  //Estado 2
  while(bit0 == 0 && bit1 == 0 && bit2 == 1 && bit3 == 0){
	bit0=digitalRead(8);
  	bit1=digitalRead(9);
  	bit2=digitalRead(10);
  	bit3=digitalRead(11);
    digitalWrite(LED_Luz_Artificial,HIGH);
	digitalWrite(Bombilla_Calor,LOW);
    digitalWrite(Abanico,LOW);
	
	if(Estado_Ventana == 1){
		for(int x; x<500; x++){
			digitalWrite(Ventana1,HIGH);
		}
		Estado_Ventana = 0;
	}
	digitalWrite(Ventana1,LOW);
	
	if(Estado_Persiana == 0){
		for(int x; x<500; x++){
			digitalWrite(Persiana2,HIGH);
		}
		Estado_Persiana = 1;
	}
	digitalWrite(Persiana2,LOW);
	
	break;
  
  }
  //Estado 3
  while(bit0 == 0 && bit1 == 0 && bit2 == 1 && bit3 == 1){
	bit0=digitalRead(8);
  	bit1=digitalRead(9);
  	bit2=digitalRead(10);
  	bit3=digitalRead(11);
    digitalWrite(LED_Luz_Artificial,HIGH);
	digitalWrite(Bombilla_Calor,LOW);
    digitalWrite(Abanico,LOW);
	
	if(Estado_Ventana == 0){
		for(int x; x<500; x++){
			digitalWrite(Ventana2,HIGH);
		}
		Estado_Ventana = 1;
	}
	digitalWrite(Ventana2,LOW);
	
	if(Estado_Persiana == 0){
		for(int x; x<500; x++){
			digitalWrite(Persiana2,HIGH);
		}
		Estado_Persiana = 1;
	}
	digitalWrite(Persiana2,LOW);
	
	break;
    
  }
  //Estado 4
  while(bit0 == 0 && bit1 == 1 && bit2 == 0 && bit3 == 0){
	bit0=digitalRead(8);
  	bit1=digitalRead(9);
  	bit2=digitalRead(10);
  	bit3=digitalRead(11);
    digitalWrite(LED_Luz_Artificial,HIGH);
	digitalWrite(Bombilla_Calor,LOW);
    digitalWrite(Abanico,HIGH);
    
	if(Estado_Ventana == 1){
		for(int x; x<500; x++){
			digitalWrite(Ventana1,HIGH);
		}
		Estado_Ventana = 0;
	}
    
	digitalWrite(Ventana1,LOW);
	
	if(Estado_Persiana == 0){
		for(int x; x<500; x++){
			digitalWrite(Persiana2,HIGH);
		}
		Estado_Persiana = 1;
	}
	digitalWrite(Persiana2,LOW);
	
	break;
  }
  //Estado 5
  while(bit0 == 0 && bit1 == 1 && bit2 == 0 && bit3 == 1){
	bit0=digitalRead(8);
  	bit1=digitalRead(9);
  	bit2=digitalRead(10);
  	bit3=digitalRead(11);
	
    digitalWrite(LED_Luz_Artificial,HIGH);
	digitalWrite(Bombilla_Calor,LOW);
    digitalWrite(Abanico,HIGH);
    
	if(Estado_Ventana == 0){
		for(int x; x<500; x++){
			digitalWrite(Ventana2,HIGH);
		}
      	
		Estado_Ventana = 1;
	}
    
	digitalWrite(Ventana2,LOW);
	
	if(Estado_Persiana == 0){
		for(int x; x<500; x++){
			digitalWrite(Persiana2,HIGH);
		}
		Estado_Persiana = 1;
	}
	digitalWrite(Persiana2,LOW);
	
	break;  
  }
  //Estado 6
  while(bit0 == 0 && bit1 == 1 && bit2 == 1 && bit3 == 0){
	bit0=digitalRead(8);
  	bit1=digitalRead(9);
  	bit2=digitalRead(10);
  	bit3=digitalRead(11);
	
    digitalWrite(LED_Luz_Artificial,HIGH);
	digitalWrite(Bombilla_Calor,LOW);
    digitalWrite(Abanico,LOW);
    
	if(Estado_Ventana == 1){
		for(int x; x<500; x++){
			digitalWrite(Ventana1,HIGH);
		}
      	
		Estado_Ventana = 0;
	}
    
	digitalWrite(Ventana1,LOW);
	
	if(Estado_Persiana == 0){
		for(int x; x<500; x++){
			digitalWrite(Persiana2,HIGH);
		}
		Estado_Persiana = 1;
	}
	digitalWrite(Persiana2,LOW);
	
	break;  
  }
  //Estado 7
  while(bit0 == 0 && bit1 == 1 && bit2 == 1 && bit3 == 1){
	bit0=digitalRead(8);
  	bit1=digitalRead(9);
  	bit2=digitalRead(10);
  	bit3=digitalRead(11);
	
    digitalWrite(LED_Luz_Artificial,HIGH);
	digitalWrite(Bombilla_Calor,LOW);
    digitalWrite(Abanico,LOW);
    
	if(Estado_Ventana == 0){
		for(int x; x<500; x++){
			digitalWrite(Ventana2,HIGH);
		}
      	
		Estado_Ventana = 1;
	}
    
	digitalWrite(Ventana2,LOW);
	
	if(Estado_Persiana == 0){
		for(int x; x<500; x++){
			digitalWrite(Persiana2,HIGH);
		}
		Estado_Persiana = 1;
	}
	digitalWrite(Persiana2,LOW);
	
	break;    
  }
  //Estado 8
  while(bit0 == 1 && bit1 == 0 && bit2 == 0 && bit3 == 0){
	bit0=digitalRead(8);
  	bit1=digitalRead(9);
  	bit2=digitalRead(10);
  	bit3=digitalRead(11);
	
    digitalWrite(LED_Luz_Artificial,LOW);
	digitalWrite(Bombilla_Calor,LOW);
    digitalWrite(Abanico,LOW);
    
	if(Estado_Ventana == 1){
		for(int x; x<500; x++){
			digitalWrite(Ventana1,HIGH);
		}
      	
		Estado_Ventana = 0;
	}
    
	digitalWrite(Ventana1,LOW);
	
	if(Estado_Persiana == 1){
		for(int x; x<500; x++){
			digitalWrite(Persiana1,HIGH);
		}
		Estado_Persiana = 0;
	}
	digitalWrite(Persiana1,LOW);
	
	break;  
  }
  //Estado 9
  while(bit0 == 1 && bit1 == 0 && bit2 == 0 && bit3 == 1){
	bit0=digitalRead(8);
  	bit1=digitalRead(9);
  	bit2=digitalRead(10);
  	bit3=digitalRead(11);
	
    digitalWrite(LED_Luz_Artificial,LOW);
	digitalWrite(Bombilla_Calor,LOW);
    digitalWrite(Abanico,LOW);
    
	if(Estado_Ventana == 0){
		for(int x; x<500; x++){
			digitalWrite(Ventana2,HIGH);
		}
      	
		Estado_Ventana = 1;
	}
    
	digitalWrite(Ventana2,LOW);
	
	if(Estado_Persiana == 1){
		for(int x; x<500; x++){
			digitalWrite(Persiana1,HIGH);
		}
		Estado_Persiana = 0;
	}
	digitalWrite(Persiana1,LOW);
	
	break; 
  }
  //Estado 10
  while(bit0 == 1 && bit1 == 0 && bit2 == 1 && bit3 == 0){
	bit0=digitalRead(8);
  	bit1=digitalRead(9);
  	bit2=digitalRead(10);
  	bit3=digitalRead(11);
	
    digitalWrite(LED_Luz_Artificial,LOW);
	digitalWrite(Bombilla_Calor,HIGH);
    digitalWrite(Abanico,LOW);
    
	if(Estado_Ventana == 1){
		for(int x; x<500; x++){
			digitalWrite(Ventana1,HIGH);
		}
      	
		Estado_Ventana = 0;
	}
    
	digitalWrite(Ventana1,LOW);
	
	if(Estado_Persiana == 1){
		for(int x; x<500; x++){
			digitalWrite(Persiana1,HIGH);
		}
		Estado_Persiana = 0;
	}
	digitalWrite(Persiana1,LOW);
	
	break; 
  }
  //Estado 11
  while(bit0 == 1 && bit1 == 0 && bit2 == 1 && bit3 == 1){
	bit0=digitalRead(8);
  	bit1=digitalRead(9);
  	bit2=digitalRead(10);
  	bit3=digitalRead(11);
	
    digitalWrite(LED_Luz_Artificial,LOW);
	digitalWrite(Bombilla_Calor,HIGH);
    digitalWrite(Abanico,LOW);
    
	if(Estado_Ventana == 0){
		for(int x; x<500; x++){
			digitalWrite(Ventana2,HIGH);
		}
      	
		Estado_Ventana = 1;
	}
    
	digitalWrite(Ventana2,LOW);
	
	if(Estado_Persiana == 1){
		for(int x; x<500; x++){
			digitalWrite(Persiana1,HIGH);
		}
		Estado_Persiana = 0;
	}
	digitalWrite(Persiana1,LOW);
	
	break; 
  }
  //Estado 12
  while(bit0 == 1 && bit1 == 1 && bit2 == 0 && bit3 == 0){
	bit0=digitalRead(8);
  	bit1=digitalRead(9);
  	bit2=digitalRead(10);
  	bit3=digitalRead(11);
	
    digitalWrite(LED_Luz_Artificial,LOW);
	digitalWrite(Bombilla_Calor,LOW);
    digitalWrite(Abanico,HIGH);
    
	if(Estado_Ventana == 1){
		for(int x; x<500; x++){
			digitalWrite(Ventana1,HIGH);
		}
		Estado_Ventana = 0;
	}
    
	digitalWrite(Ventana1,LOW);
	
	if(Estado_Persiana == 1){
		for(int x; x<500; x++){
			digitalWrite(Persiana1,HIGH);
		}
		Estado_Persiana = 0;
	}
	digitalWrite(Persiana1,LOW);
	
	break;   
  }
  //Estado 13
  while(bit0 == 1 && bit1 == 1 && bit2 == 0 && bit3 == 1){
	bit0=digitalRead(8);
  	bit1=digitalRead(9);
  	bit2=digitalRead(10);
  	bit3=digitalRead(11);
	
    digitalWrite(LED_Luz_Artificial,LOW);
	digitalWrite(Bombilla_Calor,LOW);
    digitalWrite(Abanico,HIGH);
    
	if(Estado_Ventana == 0){
		for(int x; x<500; x++){
			digitalWrite(Ventana2,HIGH);
		}
		Estado_Ventana = 1;
	}
    
	digitalWrite(Ventana2,LOW);
	
	if(Estado_Persiana == 1){
		for(int x; x<500; x++){
			digitalWrite(Persiana1,HIGH);
		}
		Estado_Persiana = 0;
	}
	digitalWrite(Persiana1,LOW);
	
	break; 
  }
  //Estado 14
  while(bit0 == 1 && bit1 == 1 && bit2 == 1 && bit3 == 0){
	bit0=digitalRead(8);
  	bit1=digitalRead(9);
  	bit2=digitalRead(10);
  	bit3=digitalRead(11);
	
    digitalWrite(LED_Luz_Artificial,LOW);
	digitalWrite(Bombilla_Calor,LOW);
    digitalWrite(Abanico,LOW);
    
	if(Estado_Ventana == 1){
		for(int x; x<500; x++){
			digitalWrite(Ventana1,HIGH);
		}
		Estado_Ventana = 0;
	}
    
	digitalWrite(Ventana1,LOW);
	
	if(Estado_Persiana == 1){
		for(int x; x<500; x++){
			digitalWrite(Persiana1,HIGH);
		}
		Estado_Persiana = 0;
	}
	digitalWrite(Persiana1,LOW);
	
	break; 
  }
  //Estado 15
  while(bit0 == 1 && bit1 == 1 && bit2 == 1 && bit3 == 1){
	bit0=digitalRead(8);
  	bit1=digitalRead(9);
  	bit2=digitalRead(10);
  	bit3=digitalRead(11);
	
    digitalWrite(LED_Luz_Artificial,LOW);
	digitalWrite(Bombilla_Calor,LOW);
    digitalWrite(Abanico,LOW);
    
	if(Estado_Ventana == 0){
		for(int x; x<500; x++){
			digitalWrite(Ventana2,HIGH);
		}
		Estado_Ventana = 1;
	}
    
	digitalWrite(Ventana2,LOW);
	
	if(Estado_Persiana == 1){
		for(int x; x<500; x++){
			digitalWrite(Persiana1,HIGH);
		}
		Estado_Persiana = 0;
	}
	digitalWrite(Persiana1,LOW);
	
	break;   
  }
}
