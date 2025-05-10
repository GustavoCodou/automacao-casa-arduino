#include <LiquidCrystal.h>
#include <Adafruit_LiquidCrystal.h>
#include <Servo.h>

// led sensores
#define ledPin 9 

// Configuração do botão dos sensores
#define button_pin 7 

// Pinagem do botão do LCD
#define button_pin_LCD 2  

// Configuração dos pinos do sensor ultrassônico
#define trigger_pin 6
#define echo_pin 5

// Configuração do sensor de gás
#define gas_sensor_pin A5
#define buzzer_pin 8

// Define LED do servo motor
#define ledPin_servo 10 

// Pinagem do botão
#define button_pin_servo 4 


// Definindo o motor
#define SENSOR A5
#define MOTOR 12

// Botão do motor
#define button_pin_motor 11

// Variável para armazenar o estado atual do LED
bool ledState = LOW;  

// Variáveis do estado do botão dos sensores
bool buttonState = LOW;
bool lastButtonState = LOW;

// Variáveis do estado do botão do LCD
bool buttonState_LCD = LOW;  
bool lastButtonState_LCD = LOW; 

// Variáveis do estado do botão do Servo
bool buttonState_servo = LOW;  
bool lastButtonState_servo = LOW;

// Variáveis do estado do botão do motor
bool buttonState_motor = LOW;
bool lastButtonState_motor = LOW;
bool motorState = false;

// Variáveis do LCD
Adafruit_LiquidCrystal lcd_1(0);
bool lcdState = false;
int lcd_ligado=0;

// Variáveis do servo motor
Servo servo_3;
bool servoState = false;

// Estado dos sensores
bool sensorsState = false; 

// Variável para leitura do sensor de gás
int gasValue = 0;

// Função para leitura da distância do ultrassônico
long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT); 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH); 
}

void setup() {
  Serial.begin(9600);
  
  // Configuração do botão
  pinMode(button_pin, INPUT_PULLUP); 
  
  // Configuração do buzzer
  pinMode(buzzer_pin, OUTPUT);
  
  // Mensagem inicial no monitor serial
  Serial.println("Sistema iniciado.");
  
  //Inicializacão do LED
  pinMode(ledPin, OUTPUT); 
  
  // Inicialização do LCD
  lcd_1.begin(16, 2);
  lcd_1.setBacklight(0);
  lcd_1.clear();
  
   // Configurações do botão do LCD:
  pinMode(button_pin_LCD, INPUT_PULLUP);
  
   // led do servo
  pinMode(ledPin_servo, OUTPUT);
  
  // Configuração do botão
  pinMode(button_pin_servo, INPUT_PULLUP);
  
    // Configuração do servo motor
  servo_3.attach(3);
  servo_3.write(0); 
  
   // Configuração do botão
  pinMode(button_pin_motor, INPUT_PULLUP);

  // Colocando o motor como saída
  pinMode(MOTOR, OUTPUT);
  
}

void loop() {
  
//---------------------------------------------------------- 
//Parte do botão para ativar os sensores

  buttonState = digitalRead(button_pin);

  // Detecta a transição do botão (pressionado e solto)
  if (buttonState == LOW && lastButtonState == HIGH) {
    sensorsState = !sensorsState; 
    if (sensorsState) {
      Serial.println("Sensores ativados.");
      ledState = !ledState;
      digitalWrite(ledPin, ledState);  
    } else {
      Serial.println("Sensores desativados.");
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
      if(lcd_ligado==1){
        lcd_1.clear(); 
        lcd_1.print("Sensores desativados.");
      }
    }
  }

//---------------------------------------------------------- 
//Parte do sensor ultrassonico
  
  // Atualiza o estado do botão
  lastButtonState = buttonState;

  // Se os sensores estiverem ativos
  if (sensorsState) {
    // Leitura do sensor ultrassônico
    int distance = 0.01723 * readUltrasonicDistance(trigger_pin, echo_pin); 
    if (distance > 0 && distance < 30) {      
      Serial.println("Presença detectada!");
      if(lcd_ligado==1){
		lcd_1.clear(); 
        lcd_1.setCursor(0, 0);
        lcd_1.print("Presenca detectada!");
      }      
      tone(buzzer_pin, 2000, 400); 
    } else {
      Serial.print("Distancia: ");
      Serial.print(distance);      
      
      if(lcd_ligado==1){
		lcd_1.clear(); 
        lcd_1.setCursor(0, 0);
       	lcd_1.print("Distancia: ");
       	lcd_1.print(distance);
       	lcd_1.print("cm");
      }
      
    }
    
//---------------------------------------------------------- 
  //Parte do sensor de gás

    // Leitura do sensor de gás
    gasValue = analogRead(gas_sensor_pin);
    Serial.print("Gas valor: ");
    Serial.println(gasValue);
    
    
    if (gasValue > 620) {
      if(lcd_ligado==1){
		lcd_1.clear(); 
        lcd_1.setCursor(0, 0);
        lcd_1.print("Gas detectado!");
      }   
      tone(buzzer_pin, 2000, 400);
    }else{
      if(lcd_ligado==1){
		lcd_1.clear(); 
        lcd_1.setCursor(0, 0);
        lcd_1.print("Gas valor: ");
        lcd_1.print(gasValue);
      } 
      
    }
    

  }

//---------------------------------------------------------- 
  //Parte do LCD
  
  buttonState_LCD = digitalRead(button_pin_LCD);
   
  if (buttonState_LCD == LOW && lastButtonState_LCD == HIGH) { 
    lcdState = !lcdState; 

    if (lcdState) {
      lcd_1.setBacklight(1);      
      lcd_1.setCursor(0, 1);
      lcd_1.clear(); 
      lcd_1.print("LCD ligado");
      lcd_ligado=1;
    } else {
      lcd_1.setBacklight(0);      
      lcd_1.clear();
      lcd_ligado=0;
    }
  }
  lastButtonState_LCD = buttonState_LCD;
  
  //---------------------------------------------------------- 
  //Parte do servo motor
  
  
  // Parte de ligar o servo
  buttonState_servo = digitalRead(button_pin_servo);

  // Detecta a transição do botão (pressionado e solto)
  if (buttonState_servo == LOW && lastButtonState_servo == HIGH) { 
    servoState = !servoState;
    
    if (servoState) {
      servo_3.write(90);
      digitalWrite(ledPin_servo, HIGH); 
    } else {
      servo_3.write(0); 
      digitalWrite(ledPin_servo, LOW); 
    }
  }

  // Atualiza o estado do botão
  lastButtonState_servo = buttonState_servo;
  
//---------------------------------------------------------- 
  //Parte do motor
  
   buttonState_motor = digitalRead(button_pin_motor);

  // Detecta a transição do botão (pressionado e solto)
  if (buttonState_motor == LOW && lastButtonState_motor == HIGH)
  {
    motorState = !motorState;  // Alterna o estado do motor

    // Agora, controlamos o motor apenas pelo estado do botão
    if (motorState)
    {
      int lecturaSensor = analogRead(SENSOR);
      int temperatura = map(lecturaSensor, 20, 358, -40, 125);

      // Controla o motor baseado na temperatura
      if (temperatura - 25 > 0 || temperatura - 25 < 0)
      {
        analogWrite(MOTOR, 128); // Liga o motor com intensidade de 50% (pode ajustar)
        Serial.println("Motor ligado.");
      }
      else
      {
        analogWrite(MOTOR, 0);  // Desliga o motor
        Serial.println("Motor desligado.");
      }
    }
    else
    {
      // Desliga o motor quando motorState for falso
      analogWrite(MOTOR, 0);
      Serial.println("Motor desligado.");
    }
  }

  // Atualiza o estado do botão
  lastButtonState_motor = buttonState_motor;
 
}

//a melhor organização de código
