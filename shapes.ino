#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library
#include <math.h>

#define SCREEN_WIDTH mylcd.Get_Width()
#define SCREEN_HEIGHT mylcd.Get_Height()
#define SCREEN_MARGIN 10

LCDWIKI_KBV mylcd(ILI9486,A3,A2,A1,A0,A4); //model,cs,cd,wr,rd,reset

class Ball
{ 
  public:

  int GetPosX() { return PosX; }
  int GetPosY() { return PosY; }
  int GetSpeed() { return Speed; }
  int GetDirection() { return Direction; }
  int GetRadius() { return Radius; }

  void SetSpeed(int S) { Speed = S; }
  void SetDirection(int Dir) { Direction = Dir; }
  void SetPosX(int X) { PosX = X; }
  void SetPosY(int Y) { PosY = Y; }

  Ball(int X, int Y, int R, int S, int Dir)
  {
    PosX = X;
    PosY = Y;
    Radius = R;
    Speed = S;
    Direction = Dir;
  }
  
  private:

  int PosX = 0;
  int PosY = 0;
  int Radius = 0;
  int Speed = 0;
  int Direction = 0;
};


// Creater another function update for the fill circle
  //mylcd.Fill_Circle(PosY, PosX, Radius);
  
void setup() 
{
    mylcd.Init_LCD(); //initialize lcd
    mylcd.Fill_Screen(0xffff); //display white
    
    
    
    Serial.begin(115200); 
}

void loop() 
{ 
  mylcd.Set_Draw_color(83, 128, 95);
  Ball MainBall(50,50,15,10, 5);

  while(true)
  {
    int PositionX = MainBall.GetPosX();
    int PositionY = MainBall.GetPosY();
    int Radius = MainBall.GetRadius();
    
    if(MainBall.GetPosX() + MainBall.GetRadius() < SCREEN_WIDTH)
    {
      if(MainBall.GetPosY() + MainBall.GetRadius() < SCREEN_HEIGHT)
      {
      
          DrawCircleTrig(PositionX, PositionY, Radius);
            
          MainBall.SetPosX(PositionX += MainBall.GetSpeed() * MainBall.GetDirection());
          MainBall.SetPosY(PositionY += MainBall.GetSpeed() * MainBall.GetDirection());
      
          mylcd.Fill_Screen(0xffff); //display white
          Serial.print(PositionX);
      }
      
   }
}

void DrawLinePleaseHorizontal(int StartPointX1, int EndPointX2, int PointY1)
{
  for(int i = StartPointX1; i < EndPointX2; i++)
  {
    mylcd.Draw_Pixel(i, PointY1);
  }
}

void DrawLinePleaseVerticle(int StartPointY1, int EndPointY2, int PointX1)
{
  for(int i = StartPointY1; i < EndPointY2; i++)
  {
    mylcd.Draw_Pixel(PointX1, i);
  }
}

void DrawLineDiagonal(int StartPointX1, int EndPointX2, int StartPointY1, int EndPointY2)
{
   for(int i = StartPointX1; i < EndPointX2; i++)
  {
    int Gradient = (EndPointY2 - StartPointY1) / (EndPointX2 - StartPointX1);
    int c = StartPointY1 - (Gradient * StartPointX1);
    int y = (Gradient * i) + c; 
    mylcd.Draw_Pixel(i, y);
  }
}

void DrawRightHandTriangle(int StartPointX1, int StartPointY1, int Width, int Height)
{
  DrawLinePleaseHorizontal(StartPointX1, StartPointX1 + Width, StartPointY1);
  DrawLinePleaseVerticle(StartPointY1, StartPointY1 + Height, StartPointX1);
  DrawLineDiagonal(StartPointX1, StartPointX1 + Width, StartPointY1 + Height, StartPointY1);
 
}

// Always X first (Along the floor up the stairs)
void DrawCircle(int CenterPointA, int CenterPointB, int Radius)
{

  for(float i = 0; i < Radius; i++)
  {
    float A = sqrt((Radius * Radius) - (i * i));

    // Top right segment
    mylcd.Draw_Pixel(i + CenterPointA , A + CenterPointB);
    mylcd.Draw_Pixel(A + CenterPointA , i + CenterPointB);

    // Top left segment
    mylcd.Draw_Pixel(A + CenterPointA , CenterPointB - i);

    // Bottom left segment
    mylcd.Draw_Pixel(CenterPointA - A , CenterPointB - i);

    // Bottom right segment
    mylcd.Draw_Pixel(CenterPointA - i , A + CenterPointB);

  }   
  
}


void DrawCircleTrig(int CenterPointA, int CenterPointB, float Radius)
{
  for(float i = 0; i < 360; i++)
  {
    float AngleToRadians = i * PI/180; 
    
    float x = (Radius * sin(AngleToRadians)); 
    float y = (Radius * cos(AngleToRadians)); 

    mylcd.Draw_Pixel(CenterPointA + x, CenterPointB + y); 

    for(int j = 0; j < x; j++)
    {
      mylcd.Draw_Pixel(j + CenterPointA, y + CenterPointB); 
      mylcd.Draw_Pixel(CenterPointA - j, CenterPointB - y); 
      
    }

  }

}





















// X1 100, Y1 200, X2 300, Y2 700
//void bresenham(int x1, int y1, int x2, int y2) 
//{ 
//
//  // Find the difference between Y 
//   int m_new = (y2 - y1); // * 2 why use these?    m_new = 700 - 300 = 400
//
//   // Find the difference between X
//   int slope_error_new = (x2 - x1); // m_new - why use these?     slope_error_new = 300 - 100 = 200
//
//
//   
//   for (int x = x1, y = y1; x <= x2; x++) // x = 100, y = 200, x <= 300; x++
//   { 
//      // Add slope to increment angle formed 
//      slope_error_new += m_new; // 600
//  
//      // Slope error reached limit, time to 
//      // increment y and update slope error. 
//      if (slope_error_new >= 0) // 600 >= 0
//      { 
//         y++; // y = 200++
//         slope_error_new  -= 2 * (x2 - x1); // 600 - 2 * (300 - 100) = 200
//      } 
//
//      mylcd.Draw_Pixel(x, y);
//   } 
//} 


   
  // Filling the screen one colour 
  //  int PosX = 0;
  //  int PosY = 0;
  //  
  //  
  //  for(int i = 0; i < mylcd.Get_Display_Width(); i++)
  //  {
  //
  //    for(int y = 0; y < mylcd.Get_Display_Height(); y++)
  //    {
  //      PosX = i;
  //      PosY = y;
  //      mylcd.Draw_Pixel(PosX, PosY);
  //    }
  //  }


  // First 2 parameters are start position. Third is length and fourth is slope
  //bresenham(0, 0, 200, 300);


  //mylcd.Draw_Circle(mylcd.Get_Width() / 2, mylcd.Get_Height() / 2, 20);

  // X pos, Y pos, 65 = A and 90 = Z uses ASCII, the colour of the char, the colour of the background, if we want the background to show. 
  //mylcd.Draw_Char(50, 60, 65, 225, 50, 10, false);
