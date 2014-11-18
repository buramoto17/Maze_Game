#include <MeggyJrSimple.h>

void setup()
{
  MeggyJrSimpleSetup(); 
}

int xCoord=0;
int yCoord=0;

void loop()
{  
  CheckButtonsPress();
  if(Button_Right);
  {
    xCoord=xCoord+1;
    if(xCoord>7)
    {
      xCoord=7;
    }
  }
  if(Button_Left);
  {
    xCoord=xCoord-1;
    if(xCoord<0)
    {
      xCoord=0;
    }
  }
  if(Button_Down)
  {
    yCoord=yCoord-1;
    if(yCoord<0)
    {
      yCoord=0;
    }
  }
  if(Button_Up)
  {
    yCoord=yCoord+1;
    if(yCoord>7)
    {
      yCoord=7;
    }
  }
  DrawPx(xCoord,yCoord,5);
  DisplaySlate();
  delay(50);
  ClearSlate();
}
