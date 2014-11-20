#include <MeggyJrSimple.h>

void setup()
{
  MeggyJrSimpleSetup();
  DrawPx(1,4,Green);
}

int xCoord=1;
int yCoord=4;
int grav=0;
int obst=0;
int obstTmr=0;
int obstX=0;
int obstY=0;
int obstStart=0;
int obstMove=0;
int gameOver=0;

void loop()
{
  CheckButtonsPress();
  if(Button_A)
  {
    yCoord=yCoord+1;
    grav=0;
  }
  if(grav==5)
  {
    if(yCoord>0)
    {
      yCoord=yCoord-1;
      grav=0;
    }
  }
  if(obstTmr>10)
  {
    if(obstStart==0)
    {
      obst=random(1,5);
      obstY=0;
      obstX=7;
    }
    obstStart=1;
    if(obst==1)
    {
      DrawPx(obstX,obstY,Red);
    }
    if(obst==2)
    {
      DrawPx(obstX,obstY,Red);
      DrawPx(obstX,obstY+1,Red);
    }
    if(obst==3)
    {
      DrawPx(obstX,obstY,Red);
      DrawPx(obstX,obstY+1,Red);
      DrawPx(obstX,obstY+2,Red);
    }
    if(obst==4)
    {
      DrawPx(obstX,obstY,Red);
      DrawPx(obstX,obstY+1,Red);
      DrawPx(obstX,obstY+2,Red);
      DrawPx(obstX,obstY+3,Red);
    }
    if(obst==5)
    {
      DrawPx(obstX,obstY,Red);
      DrawPx(obstX,obstY+1,Red);
      DrawPx(obstX,obstY+2,Red);
      DrawPx(obstX,obstY+3,Red);
      DrawPx(obstX,obstY+4,Red);
    }
    if(obstMove>5)
    {
      if(obstX<0)
      {
        obstTmr=0;
        obstStart=0;
      }
      if(ReadPx(obstX-1,obstY)==Red)
      {
        gameOver=1;
      }
      else
      {
        obstX=obstX-1;
        obstMove=0;
      }
    }
  }
  DrawPx(xCoord,yCoord,Green);
  DisplaySlate();
  delay(50);
  ClearSlate();
  grav=grav+1;
  obstTmr=obstTmr+1;
  obstMove=obstMove+1;
  if(gameOver==1)
  {
    ClearSlate();
    DisplaySlate();
    xCoord=1;
    yCoord=4;
    grav=0;
    obst=0;
    obstTmr=0;
    obstX=0;
    obstY=0;
    obstStart=0;
    obstMove=0;
    gameOver=0;
    delay(3000);
  }
}
