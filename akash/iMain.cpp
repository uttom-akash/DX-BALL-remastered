
# include<iostream>
# include<cmath>
# include "iGraphics.h"
# define screenwidth 1200
# define screenheight 675
# define  ymargin 30 
# define totalbricks 5*10
# define pi 3.1416

using namespace std;


void balljump();
void restart();
void brickcoor();

int h;
int go = 1;
int life = 2;
int score = 0;
int mposx,  mposy;
int xBall = screenwidth / 2;
int yBall = ymargin+10;
float v = 10;
int theta =45;
int dx =v*cos(theta*pi / 180);
int dy =v*sin(theta*pi / 180);

int radius = 6;

int xboard = xBall - 50;
int yboard =ymargin-radius;
int dxboard = 100;
int dyboard = 10;
int state1=0;


struct  bricks{
	int x, y;
	bool show = true;

	int color1 = 255;
	int color2 = 0;
	int color3 = 255;
};

struct bricks brick[totalbricks];

char img[4][80] = { "bc\\maxresdefault.bmp", "bc\\Falling-confetti-video-on-color-background.bmp", "bc\\game-menu.bmp","bc\\transistor_20150318203303.bmp" };

void iDraw()
{
	iClear();
	char showlife[80];
	char scorei[80];
	char hscore[80];

	//file 


	sprintf_s(hscore, "HIGH SCORE :%d", h);
	sprintf_s(showlife, "LIFE : %d", life);
	sprintf_s(scorei, "SCORE : %d", score);
	if (state1 == 3)
	{
		iShowBMP(0, 0, "bc//d2ff97fd8442124a92acc4b0039fb36a.bmp");
	}
	else if(state1==1 || state1==2)
	{
		iShowBMP(0, 0, "bc//dark-polygonal-objects.bmp");
		iSetColor(220, 20,60);
	    iFilledCircle(xBall, yBall, radius, 100);
	    //iFilledRectangle(xboard, yboard, 100, 10);
		iShowBMP(xboard, yboard, "bc\\d1e5ce65fa3cb5ba4c8c94e2621e8f27.bmp");

	    for (int i = 0; i < totalbricks; i++)
	    {
			
				if (brick[i].show)
				{
					iSetColor(brick[i].color1, brick[i].color2, brick[i].color3);
					iFilledRectangle(brick[i].x, brick[i].y, 100, 20);
					
				}
	   }

		iText(1050, 625, showlife, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1050, 645, scorei, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(10, 645, hscore, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (state1==0)
	{
			iShowBMP(0, 0, img[3]);
			iShowBMP(400,285, img[2]);
			iShowBMP(400,210,"bc//game-menucontrol.bmp");
			iShowBMP(400, 135, "bc//game-menuEXIT.bmp");
			iShowBMP(330, 475, img[0]);
	}
	else if (state1 == 4)
	{
		iShowBMP(0, 0, "bc//texture_korinchevy_background_band_strips_high_contrast_hd-wallpaper-415966.bmp");
	}
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	if (mx >= 0 && mx <= 1100)
	{
		xboard = mx;
		if (state1==1)
			xBall = mx + 50;
	}
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (!state1)
		{
			if (my >= 285 && my <= 345)
			{
				if (mx >= 400 && mx <= 400 + 330)
				state1 = 1;
			}
			else if (my >= 210 && my <= 270)
			{
				if (mx >= 400 && mx <= 400 + 330)
				state1 = 4;
			}
			else if (my >= 135 && my <= 135 + 60)
			{
				if (mx >= 400 && mx <= 400 + 330)
					exit(0);
			}
		}
		PlaySound("mc\\Click-SoundBible.com-1387633738.wav", NULL, SND_ASYNC);
	}
	cout << state1 << endl;
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		if (state1 == 1)
			state1 = 2;
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//do something with 'q'
	}

	if (key == ' ')
	{
		if (state1 == 3)
			state1 = 0;
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	else if (key == GLUT_KEY_LEFT)
	{
		if (xboard>0)
		{
			xboard -= 65;
			if (state1==1)
			{
				xBall -= 65;
			}
		}
	}
	else if (key == GLUT_KEY_RIGHT)
	{
		if (xboard<screenwidth-65)
		{
			xboard += 65;
		     if (state1==1)
		     {
			    xBall += 65;
		     }
		}
	}
	else if (key == GLUT_KEY_UP)
	{
		if (state1 == 1)
			state1 = 2;
	}
	else if (key == GLUT_KEY_HOME)
	{
			state1 = 0;
	}
	//place your codes for other keys here
}

void balljump()
{
	if (score == 500)
		state1 = 0;
	if (state1==2)
	{
	     xBall += dx;
	     yBall += dy;
	   
	   
		 if (xBall <= 0 || xBall >= screenwidth)
		 {
			 dx *= -1;
			 PlaySound("mc\\Mario_Jumping-Mike_Koenig-989896458.wav", NULL, SND_ASYNC);
		 }
		 if (yBall <= 0 || yBall >= screenheight)
		 {
			 dy *= -1;
			 PlaySound("mc\\Mario_Jumping-Mike_Koenig-989896458.wav", NULL, SND_ASYNC);
		 }



	     if (xBall >= xboard && xBall <= xboard + dxboard && yBall >= yboard && yBall <= yboard + dyboard)
	     {
		   theta = xboard + dxboard - xBall;
		   theta += 40;
		   dx = v*cos(theta*pi / 180);
		   dy = v*sin(theta*pi / 180);
		   
		   PlaySound("mc\\Mario_Jumping-Mike_Koenig-989896458.wav",NULL, SND_ASYNC);
	     }
	     else if (yBall < yboard)
	     {
			 life--;
		     restart();
	     }





	   for (int i = 0; i < totalbricks; i++)
	   {
		   if (brick[i].show)
		   {
			   if (xBall >= brick[i].x && xBall <= brick[i].x + 100)
			   {
				   if (yBall >= brick[i].y && yBall <= brick[i].y + 20)
				   {
					   dy *= -1;
					   brick[i].show = false;
					   score += 10;
					   PlaySound("mc\\Smashing-Yuri_Santana-1233262689.wav", NULL, SND_ASYNC);
				   }
			   }
			   else if (yBall >= brick[i].y && yBall <= brick[i].y + 20)
			   {
				   if (xBall >= brick[i].x && xBall <= brick[i].x + 100)
				   {
					   dx*= -1;
					   brick[i].show = false;
					   score += 10;
					   PlaySound("mc\\Smashing-Yuri_Santana-1233262689.wav", NULL, SND_ASYNC);
				   }
			   }

		   }
	   }
	}
}

void restart()
{
	xBall = screenwidth / 2;
	yBall = ymargin + 10;

	xboard = xBall - 50;
	yboard = ymargin - radius;
	theta = 30;
	dx = v*cos(theta*pi / 180);
	dy = v*sin(theta*pi / 180);
	state1 = 1;
	if (life == 0)
	{
		state1= 3;
		life = 2;
		score = 0;
		for (int i = 0; i < totalbricks; i++)
			brick[i].show = true;
	}
}


void brickcoor()
{
	int sumx =85;
	int sumy =500;
	for (int i = 0; i < totalbricks; i++)
	{
		brick[i].x = sumx;
		brick[i].y = sumy;
		sumx += 103;
		if ((i+1)%10==0)
		{
			sumy -= 23;
			sumx = 85;
		}
		brick[i].color1 = rand() % 255;
		brick[i].color2 = rand() % 255;
		brick[i].color3 = rand() % 255;
	}
}
//
int main()
{
	 //mainmenu();
	 brickcoor();
	 iSetTimer(15, balljump);
	//place your own initialization codes here.
	iInitialize(screenwidth, screenheight, "DX-BALL by akash");
	return 0;
}
