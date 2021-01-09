#include "Ball.h"

#include <math.h>
#define _USE_MATH_DEFINES 

Ball::Ball(int X, int Y, int R)
{
  PosX = X;
  PosY = Y;
  Radius = R;
}

void Ball::Update()
{
  int NextPosX = Ball::GetPosX() + Ball::GetVelocityX(); 
  int NextPosY = Ball::GetPosY() + Ball::GetVelocityY();
  Ball::SetPosX(NextPosX);
  Ball::SetPosY(NextPosY);
  
}

int Ball::GetVelocityX()
{
  return VelocityX;
}

int Ball::GetVelocityY()
{
  return VelocityY;
}

int Ball::GetPosX() 
{
  return PosX; 
}

int Ball::GetPosY() 
{ 
  return PosY; 
}
  
int Ball::GetRadius() 
{ 
  return Radius; 
}

void Ball::SetPosX(int X) 
{ 
  PosX = X; 
}

void Ball::SetPosY(int Y) 
{ 
  PosY = Y; 
}

void Ball::SetSpeed(int Direction, int Speed)
{
  float AngleToRadians = Direction * M_PI/180; 

  int X = (Speed * sin(AngleToRadians));
  int Y = (Speed * cos(AngleToRadians));
  
  VelocityX = X;
  VelocityY = Y;
}
