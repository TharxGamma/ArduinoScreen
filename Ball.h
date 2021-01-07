#ifndef BALL_H
#define BALL_H

class Ball
{ 
  public:
  
  Ball(int X, int Y, int R, int S, int Dir);

  int GetPosX() { return PosX; }
  int GetPosY() { return PosY; }
  int GetSpeed() { return Speed; }
  int GetDirection() { return Direction; }
  int GetRadius() { return Radius; }

  void SetSpeed(int S);
  void SetDirection(int Dir);
  void SetPosX(int X);
  void SetPosY(int Y);


  private:

  int PosX = 0;
  int PosY = 0;
  int Radius = 0;
  int Speed = 0;
  int Direction = 0;
};

#endif
