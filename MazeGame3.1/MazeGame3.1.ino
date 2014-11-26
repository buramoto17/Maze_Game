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
  if(Button_Up)
  {
    if(yCoord<7)//check if dot is still on screen
    {
      if(ReadPx(xCoord,yCoord+1)==Red)//Check if the next pixel is a wall or not
      {
        //leave this if statment empty because we don't want to do anything when the dot is trying to go into the wall
      }
      else//if the next dot is not a wall....
      {
        yCoord=yCoord+1;//now move the dot
      }
    }
  }
  if(Button_Down)//repeat for each direction
  {
    if(yCoord>0)
    {
      if(ReadPx(xCoord,yCoord-1)==Red)
      {
      }
      else
      {
        yCoord=yCoord-1;
      }
    }
  }
  if(Button_Right)
  {
    if(xCoord<7)
    {
      if(ReadPx(xCoord+1,yCoord)==Red)
      {
      }
      else
      {
        xCoord=xCoord+1;
      }
    }
  }
  if(Button_Left)
  {
    if(xCoord>0)
    {
      if(ReadPx(xCoord-1,yCoord)==Red)
      {
      }
      else
      {
        xCoord=xCoord-1;
      }
    }
  }
  DrawPx(xCoord,yCoord,Green);
  DisplaySlate();
  delay(50);
  ClearSlate();
}
