#ifndef BALL_H
#define BALL_H

#include <math.h>

class Ball
{ 
  public:
  
  Ball(int X, int Y, int R);

  int GetPosX();
  int GetPosY(); 
  int GetRadius(); 

  void SetSpeed(int Direction, int Speed);
  void SetPosX(int X);
  void SetPosY(int Y);


  private:

  int PosX = 0;
  int PosY = 0;
  int Radius = 0;
  int VelocityX = 0;
  int VelocityY = 0;
};

#endif
