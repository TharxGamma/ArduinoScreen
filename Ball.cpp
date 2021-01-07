#include "Ball.h"

Ball::Ball(int X, int Y, int R, int S, int Dir)
{
  PosX = X;
  PosY = Y;
  Radius = R;
  Speed = S;
  Direction = Dir;
}

void Ball::SetSpeed(int S) 
{ 
  Speed = S; 
}

void Ball::SetDirection(int Dir) 
{ 
  Direction = Dir; 
}

void Ball::SetPosX(int X) 
{ 
  PosX = X; 
}

void Ball::SetPosY(int Y) 
{ 
  PosY = Y; 
}
