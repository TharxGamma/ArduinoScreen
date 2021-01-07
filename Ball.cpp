#include "Ball.h"

Ball::Ball(int X, int Y, int R)
{
  PosX = X;
  PosY = Y;
  Radius = R;
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

void Ball::SetSpeed(int VelX, int VelY)
{
  VelocityX = VelX;
  VelocityY = VelY;
}
