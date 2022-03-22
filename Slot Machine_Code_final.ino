/*
 * Máquina de Jackpot
 * Implementação no arduino e código  - Daniel Ferrari Alves
 * Código, Ideia e Descrição          - Luiz Phillyp Sabadini Bazoni
 * Código, Esquemático e Github       - Thiago Felippe Neitzke Lahass
 */

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Stepper.h>

//VARIAVEIS --------------------//

//setup das entradas usadas no display
const int16_t lcd_end = 0x27;
const int en = 2, rw = 1, rs = 0, d4 = 4, d5 = 5, d6 = 6, d7 = 7, bl = 3;
LiquidCrystal_I2C lcd(lcd_end, en, rw, rs, d4, d5, d6, d7, bl, POSITIVE);

//entrada do botao
const int inputButton = A0;

// valor lido pelo botao na ultima vez que foi apertado
int oldValue; 
int currentValue;
int diff;
int flag = 0;
int i;

//valor da aposta atual
int aposta = 10;

//informacao sobre os motores (depende do motor)
const int passosPorVolta = 2048; //numero de passos em uma volta
const int passosPorIcone = 256;     //numero de passos em cada icone

//sorteio
char sorteio[3];
char ultimoSorteio[3] = {'A', 'A', 'A'};
int pontos = 100, ganho;

//motores
Stepper motor_1(passosPorVolta, 10,12,11,13); //os inputs mudam dependendo do motor
Stepper motor_2(passosPorVolta, 6,8,7,9);
Stepper motor_3(passosPorVolta, 2,4,3,5);

//------------------------------//


//FUNCOES --------------------//
void generateSequence(char *sequenceArray);
void AtivaMotores(char *sequenceArray, char *memoria);
int retornaPontos(char *sequenceArray);
int verificaLetra(char caractere, char *sequenceArray);
void resetarRoletas(char *memoria);
//----------------------------//



void setup()
{
    lcd.begin(16, 2);
    Serial.begin(9600);
  
    pinMode(inputButton, INPUT);
    
    lcd.setCursor(0,0);
    lcd.print("    Voce tem    ");
    lcd.setCursor(0,1);
    lcd.print("   100 Pontos   ");
    


    //para gerar uma seed a gente usa os valores aleatorios
    //que ficam nas portas nao inicializadas  
    randomSeed(analogRead(A1));
  
    //inicializar motores
    motor_1.setSpeed(6);
    motor_2.setSpeed(6);
    motor_3.setSpeed(6);
}

void loop()
{
  flag=0;
  //le o valor do botao
  currentValue = analogRead(inputButton);
  //Serial.println(currentValue);
  
  if(currentValue != oldValue)
  {
    oldValue = currentValue;
    
    //botao amarelo
    if((currentValue >= 450)&&(currentValue <= 550))
    {
        
      //Cuidando da flutuacao
      for(i=0; i<50; i++)
      {
        currentValue = analogRead(inputButton);
        diff = currentValue - oldValue;
        Serial.println(diff);
        if((diff>=-1)&&(diff<=1)){
          flag = 1;
        }
        else{
          flag = 0;
          break;
        }
        oldValue = currentValue;
      }

      if(flag)
      {
        flag=0;
        Serial.println("Botao amarelo");
        aposta+= 10;
        if(aposta > 30)
        {
          aposta = 30;
          
          //o cursor eh onde o caractere vai ser colocado
          //(linha, coluna)
          
          lcd.setCursor(0, 1);
          lcd.print("--aposta max!!--");
          delay(1000);
        }
        else
        {
          lcd.setCursor(0, 1);
          
          //print de espaco " " e a mesma coisa que apagar
          lcd.print("                ");
        }
        
        lcd.setCursor(0,0);
        lcd.print("Aposta:         ");
        lcd.setCursor(11,0);
        lcd.print(aposta);
        delay(500);
      }
    }   


    //botao vermelho
    if((currentValue >= 700)&&(currentValue <= 800))
    {
      //Cuidando da flutuacao
      for(i=0; i<50; i++)
      {
        currentValue = analogRead(inputButton);
        diff = currentValue - oldValue;
        if((diff>=-1)&&(diff<=1)){
          flag = 1;
        }
        else{
          flag = 0;
          break;
        }
        oldValue = currentValue;
      }

      if(flag)
      {
        flag=0;
        Serial.println("Botao vermelho");
        aposta -= 10;
        if(aposta < 10)
        {
          aposta = 10;
          lcd.setCursor(0 ,1);
          lcd.print("--aposta min!!--");
          delay(1000);
        }
        else
        {
          lcd.setCursor(0, 1);
          lcd.print("                ");
        }
        
        lcd.setCursor(0,0);
        lcd.print("Aposta:         ");
        lcd.setCursor(11,0);
        lcd.print(aposta);
        delay(500);
      }
    }
    
    //botao verde
    if((currentValue >= 200)&&(currentValue <= 300))
    {
      //Cuidando da flutuacao
      for(i=0; i<50; i++)
      {
        currentValue = analogRead(inputButton);
        diff = currentValue - oldValue;
        if((diff>=-1)&&(diff<=1)){
          flag = 1;
        }
        else{
          flag = 0;
          break;
        }
        oldValue = currentValue;
      }

      if(flag)
      {
        flag=0;
        Serial.println("Botao verde");
        if(pontos < aposta){
          lcd.setCursor(0,0);
          lcd.print("      ERRO      ");
          lcd.setCursor(0,1);
          lcd.print("Saldo insufiente");
          delay(2000);
          lcd.setCursor(0,0);
          lcd.print("Aposta:         ");
          lcd.setCursor(11,0);
          lcd.print(aposta);
          lcd.setCursor(0, 1);
          lcd.print("                ");
        } else {
          pontos -= aposta;
          generateSequence(sorteio);
          AtivaMotores(sorteio, ultimoSorteio);

          ganho = retornaPontos(sorteio);

          if((ganho - aposta) >= 0){
            lcd.setCursor(0,0);
            lcd.print("  Voce ganhou:  ");
            lcd.setCursor(0,1);
            if((ganho - aposta) > 9){
              lcd.print("      Pontos!   ");
              lcd.setCursor(3,1);
              lcd.print(ganho - aposta);
            } else{
              lcd.print("      Pontos    ");
              lcd.setCursor(3,1);
              lcd.print(ganho - aposta);
            }
          } else{
            lcd.setCursor(0,0);
            lcd.print("  Voce perdeu:  ");
            lcd.setCursor(0,1);
            if((aposta - ganho) > 9){
              lcd.print("      Pontos!   ");
              lcd.setCursor(3,1);
              lcd.print(aposta - ganho);
            } else{
              lcd.print("      Pontos    ");
              lcd.setCursor(3,1);
              lcd.print(aposta - ganho);
            }
          }
          delay(2000);
          
          lcd.setCursor(0,0);
          lcd.print("    Voce tem    ");
          lcd.setCursor(0,1);
          if(pontos<1000){
            lcd.setCursor(0,1);
            lcd.print("       Pontos   ");
            lcd.setCursor(3,1);
            lcd.print(pontos);
          }
          else{
            lcd.setCursor(0,1);
            lcd.print("       Pontos!  ");
            lcd.setCursor(2,1);
            lcd.print(pontos);
          }
        }
      }
      delay(500);
    }
    //botao pequeno
    if((currentValue >= 950)&&(currentValue <= 1050))
    {
      //Cuidando da flutuacao
      for(i=0; i<50; i++)
      {
        currentValue = analogRead(inputButton);
        diff = currentValue - oldValue;
        if((diff>=-1)&&(diff<=1)){
          flag = 1;
        }
        else{
          flag = 0;
          break;
        }
        oldValue = currentValue;
      }
      if(flag)
      {
        flag=0;
        lcd.setCursor(0,0);
        lcd.print("Jogo Finalizado!");
        lcd.setCursor(0,1);
        lcd.print("Total:    Pontos");
        lcd.setCursor(7,1);
        lcd.print(pontos);
        pontos = 100;
        resetarRoletas(ultimoSorteio);
        lcd.setCursor(0,0);
        lcd.print("    VOCE TEM    ");
        lcd.setCursor(0,1);
        lcd.print("   100 PONTOS   ");
      }
      delay(500);
    }
  }

  if(pontos < 10){
    
    lcd.setCursor(0,0);
    lcd.print("******VOCE******");
    lcd.setCursor(0,1);
    lcd.print("****PERDEU!!****");
    delay(5000);
    pontos = 100;
    resetarRoletas(ultimoSorteio);
    lcd.setCursor(0,0);
    lcd.print("    VOCE TEM    ");
    lcd.setCursor(0,1);
    lcd.print("   100 PONTOS   ");
    
  }
}


//--------------//
//Gera uma sequencia aleatoria entre 'A' e 'H'

void generateSequence(char *sequenceArray)
{
  for(int i = 0; i < 3; i++)
  {
    char simboloAtual = random((passosPorVolta/passosPorIcone)) + 'A';
  sequenceArray[i] = simboloAtual;
  Serial.print(simboloAtual);
          
  if(i<2)
    Serial.print(" - "); 
  }
  Serial.println();
  
  pontos += retornaPontos(sequenceArray);
  Serial.println(pontos);
}

void AtivaMotores(char *sequenceArray, char *memoria)
{   
  int passos1, passos2, passos3;
    
  passos1 = passosPorIcone * (sequenceArray[0] - memoria[0]);
  if(passos1 <= 0){
    passos1 = passosPorVolta - (passosPorIcone * (memoria[0] - sequenceArray[0]));
  }
  motor_1.step(passos1);
  Serial.print("Passos motor 1: ");
  Serial.println(passos1);
  
  passos2 = passosPorIcone * (sequenceArray[1] - memoria[1]);
  if(passos2 <= 0){
    passos2 = passosPorVolta - (passosPorIcone * (memoria[1] - sequenceArray[1]));
  }
  motor_2.step(passos2);
  Serial.print("Passos motor 2: ");
  Serial.println(passos2);
  
  passos3 = passosPorIcone * (sequenceArray[2] - memoria[2]);
  if(passos3 <= 0){
    passos3 = passosPorVolta - (passosPorIcone * (memoria[2] - sequenceArray[2]));
  }
  motor_3.step(passos3);
  Serial.print("Passos motor 3: ");
  Serial.println(passos3);
  memoria[0] = sequenceArray[0];
  memoria[1] = sequenceArray[1];
  memoria[2] = sequenceArray[2];
}

int retornaPontos(char *sequenceArray)
{
  int retorno;
  for(int i = 0; i < 8; i++)
  {
    retorno = verificaLetra(i + 'A', sequenceArray);
    
    // Pode retornar menos que a aposta gasta
    if(retorno == 3)
    {
    return 2*((i + 1) * retorno)*(aposta/10);
    }
    else
    
    if(retorno == 2)
    {
    return 2*((i + 1) * retorno)*(aposta/10);
    }
  }
  return 0;
}

int verificaLetra(char caractere, char *sequenceArray)
{
  int cont = 0;
  for(int i = 0; i<3; i++)
  {
    if(sequenceArray[i] == caractere)
    cont++;
  }
  return cont;
}

void resetarRoletas(char *memoria){
  int passos1, passos2, passos3;

  passos1 = passosPorIcone * ('A' - memoria[0]);
  if(passos1 <= 0){
    passos1 = passosPorVolta - (passosPorIcone * (memoria[0] - 'A'));
  }
  motor_1.step(passos1);
  Serial.print("Passos motor 1: ");
  Serial.println(passos1);
  
  passos2 = passosPorIcone * ('A' - memoria[1]);
  if(passos2 <= 0){
    passos2 = passosPorVolta - (passosPorIcone * (memoria[1] - 'A'));
  }
  motor_2.step(passos2);
  Serial.print("Passos motor 2: ");
  Serial.println(passos2);
  
  passos3 = passosPorIcone * ('A' - memoria[2]);
  if(passos3 <= 0){
    passos3 = passosPorVolta - (passosPorIcone * (memoria[2] - 'A'));
  }
  motor_3.step(passos3);
  Serial.print("Passos motor 3: ");
  Serial.println(passos3);
  memoria[0] = 'A';
  memoria[1] = 'A';
  memoria[2] = 'A';
}
