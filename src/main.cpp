#include <Arduino.h>

int E = 1;
int D = 2;
int decimal = 3;
int C = 4;
int G = 5;
int D4 = 6;
int B = 7;
int D3 = 8;
int D2 = 9;
int F = 10;
int A = 11;
int D1 = 12;

int digit[4] = {0, 0, 0, 0};

int delayVal1 = 1;

int numbers[10][7] = {
    {A, B, C, D, E, F},    //0
    {B, C},                //1
    {A, B, G, E, D},       //2
    {A, B, G, C, D},       //3
    {F, G, B, C},          //4
    {A, F, G, C, D},       //5
    {A, F, E, D, C, G},    //6
    {A, B, C},             //7
    {A, B, C, D, E, F, G}, //8
    {A, B, C, D, F, G}     //9
};

int allLowPin[7] = {A, B, C, D, E, F, G};
int chatodePin[4] = {D1, D2, D3, D4};

void allLow(int pins[7])
{
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(pins[i + 1], LOW);
  }
}

void segmentView(int digit[10][7], int num)
{
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(digit[num][i + 1], HIGH);
  }
}

void numCalc(int num)
{
  int num2 = num;
  digit[4] = num % 10;
  digit[3] = num / 10 % 10;
  digit[2] = num / 100 % 10;
  digit[1] = num / 1000 % 10;

  do
  {
    for (int i = 0; i < 3; i++)
    {
      segmentView(numbers, digit[i + 1]);
      digitalWrite(chatodePin[i + 1], LOW);
      delay(delayVal1);
      allLow(allLowPin);
      digitalWrite(chatodePin[i + 1], HIGH);
    }

  } while (num != num2);
}

void setup()
{
  pinMode(E, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(decimal, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(D1, OUTPUT);

  digitalWrite(D1, HIGH); //katódok alapértelmezésre állítása
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
}

void loop()
{
  for (int i = 0; i < 10000; i++)
  {
    numCalc(i);
    delay(100);
  }
}