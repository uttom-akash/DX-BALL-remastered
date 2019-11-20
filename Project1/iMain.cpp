
# include<iostream>
# include<cmath>
# include<fstream>
# include<string>
# include "iGraphics.h"
# define screenwidth 1200
# define screenheight 675
# define  ymargin 30 
# define totalbricks 50
# define pi 3.1416

using namespace std;


void balljump();
void restart();
void brickcoor();

int lv = 1;
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
char name[80];


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
	char stage[80];
	//file 
	ifstream reader("hscore.txt");

	if (reader.is_open())
	{
		reader >>h;
	}
	reader.close();


	
	if (h < score)
	{
		h = score;
		ofstream writer("hscore.txt");
		if (writer.is_open())
		{
			writer << h << endl;
			
		}
	}

	///end of file
	sprintf_s(stage, "Stage :%d", lv);
	sprintf_s(hscore, "High Score :%d", h);
	sprintf_s(showlife, "Life : %d", life);
	sprintf_s(scorei, "Score : %d", score);
	if (state1 ==10)
	{
		
		char a[80];
		char ch,ch1;
	  
		iShowBMP(0, 0, "bc//Falling-confetti-video-on-color-background.bmp");
		ifstream read("name.txt");
		if (read.is_open())
			read >> ch>>ch1;
		reader.close();
		
		a[0] = ch;
		a[1] = ch1;
		a[2] = '\0';
		iSetColor(20, 120, 160);
		iFilledRectangle(400, 500, 300, 35);
		iFilledRectangle(400, 400, 30, 20);
		iFilledRectangle(440, 400, 30, 20);


		iSetColor(220, 20, 60);
		iText(420, 510, a, GLUT_BITMAP_TIMES_ROMAN_24);
		
	}
	else if (state1==5)
	{
		iShowBMP(0, 0, "bc//1.bmp");
		iText(430,450,hscore,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (state1 == 3)
	{ 
		
			iShowBMP(0, 0, "bc//d2ff97fd8442124a92acc4b0039fb36a.bmp");
			iText(300, 500, "Your", GLUT_BITMAP_TIMES_ROMAN_24);
			iText(380, 500, scorei, GLUT_BITMAP_TIMES_ROMAN_24);
			iText(700, 500, hscore, GLUT_BITMAP_TIMES_ROMAN_24);

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
		iText(1050, 605,stage, GLUT_BITMAP_TIMES_ROMAN_24);
		
	}
	else if (state1==0)
	{
			iShowBMP(0, 0, img[3]);
			iShowBMP(400,285, img[2]);
			iShowBMP(770,380, "bc//sign.bmp");
			iShowBMP(400,220,"bc//game-menuCON.bmp");
			iShowBMP(400,155,"bc//game-menucontrol.bmp");
			iShowBMP(400,25, "bc//game-menuEXIT.bmp");
			iShowBMP(400,90, "bc//game-menuHI.bmp");
			iShowBMP(330, 475, img[0]);
	}
	else if (state1 == 4)
	{
		iShowBMP(0, 0, "bc//texture_korinchevy_background_band_strips_high_contrast_hd-wallpaper-415966.bmp");
	}
}


void iMouseMove(int mx, int my)
{
	if (mx >= 0 && mx <= 1100)
	{
		xboard = mx;
		if (state1==1)
			xBall = mx + 50;
	}
}


void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (state1 == 10)
		{
			char a = 'a';
			ofstream write("name.txt");

				if (mx >= 400 && mx <= 400 + 30)
				{
					if (my >= 400 && my <= 400 + 20)
					{
						a = 'A';
						if (write.is_open())
						{
							write << a;
						}

						PlaySound("mc\\Click-SoundBible.com-1387633738.wav", NULL, SND_ASYNC);
					}
				}


				if (mx >= 440 && mx <= 440 + 30)
				{

					if (my >= 400 && my <= 400 + 20)
					{
						a = 'B';
						if (write.is_open())
						{
							write << a;
						}

						PlaySound("mc\\Click-SoundBible.com-1387633738.wav", NULL, SND_ASYNC);
					}
				}

			
		}
		if (!state1)
		{
			if (my >= 380 && my <= 380 + 46)
			{
				if (mx >= 770 && mx <= 770 + 208)
				{
					state1 = 10;
					PlaySound("mc\\Click-SoundBible.com-1387633738.wav", NULL, SND_ASYNC);
				}
			}
			else if (my >= 285 && my <= 285 + 60)
			{
				if (mx >= 400 && mx <= 400 + 330)
				{
					state1 = 1;
					PlaySound("mc\\Click-SoundBible.com-1387633738.wav", NULL, SND_ASYNC);
				}
			}
			else if (my >= 220 && my <= 220 + 60)
			{
				if (mx >= 400 && mx <= 400 + 330)
				{
					state1 = 1;
					PlaySound("mc\\Click-SoundBible.com-1387633738.wav", NULL, SND_ASYNC);
				}
			}
			else if (my >= 155 && my <= 155 + 60)
			{
				if (mx >= 400 && mx <= 400 + 330)
				{
					state1 = 4;
					PlaySound("mc\\Click-SoundBible.com-1387633738.wav", NULL, SND_ASYNC);
				}
			}
			else if (my >= 25 && my <= 25 + 60)
			{
				if (mx >= 400 && mx <= 400 + 330)
				{
					exit(0);
					PlaySound("mc\\Click-SoundBible.com-1387633738.wav", NULL, SND_ASYNC);
				}
			}
			else if (my >= 90 && my <= 90 + 60)
			{
				if (mx >= 400 && mx <= 400 + 330)
				{
					state1 = 5;
					PlaySound("mc\\Click-SoundBible.com-1387633738.wav", NULL, SND_ASYNC);
				}
			}
		}
		
	}
	cout << state1 << endl;
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		if (state1 == 1)
			state1 = 2;
	}
}


void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        
 else if(my== 2){}  

}


void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//do something with 'q'
	}

	if (key == ' ')
	{
		if (state1 == 3)
		{
			state1 = 0;
			score = 0;
		}

	}
	
}



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
		 else if(score == 500)
			 {
				 lv++;
				 score += 10;
				 for (int i = 0; i < totalbricks; i++)
				 brick[i].show = true;
				 brickcoor();
				 restart();

			 }
		 else if (score == 1010)
		 {
			 state1 = 3;
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
	theta = 45;
	dx = v*cos(theta*pi / 180);
	dy = v*sin(theta*pi / 180);
	state1 = 1;
	if (life == 0)
	{
		state1= 3;
		life = 2;
		for (int i = 0; i < totalbricks; i++)
			brick[i].show = true;
	}
}


void brickcoor()
{
	
	if (lv==1)
	{
		int sumx = 39;
		int sumy = 450;


		int ro = 0;
		int co = 11, pre = 0;
		for (int i = 0; i < 36; i++)
		{

			brick[i].x = sumx;
			brick[i].y = sumy;
			sumx += 102;

			if ((i + 1 - pre) % co == 0)
			{
				ro++;
				pre = i + 1;
				co -= 2;
				sumy += 22;
				sumx = 39 + 102 * ro;
			}
			brick[i].color1 = rand() % 255;
			brick[i].color2 = rand() % 255;
			brick[i].color3 = rand() % 255;
		}
		sumx = 39;
		sumy = 516;
		co = 10;
		ro = 0;
		for (int i = 36; i < 46; i++)
		{
			brick[i].x = sumx;
			brick[i].y = sumy;
			sumx += 102*co;
			if ((i + 1) % 2 == 0)
			{
				ro++;
				co -= 2;
				sumy += 22;
				sumx = 39 + 102 * ro;
			}

			brick[i].color1 = rand() % 255;
			brick[i].color2 = rand() % 255;
			brick[i].color3 = rand() % 255;
		}

		sumx = 39;
		sumy = 538;
		for (int i = 46; i < 50; i++)
		{
			brick[i].x = sumx;
			brick[i].y = sumy;
			 sumx += 102 * 10;
			 if ((i + 1) % 2 == 0)
			 {
				 sumy += 22;
				 sumx = 39;
			 }

			 brick[i].color1 = rand() % 255;
			 brick[i].color2 = rand() % 255;
			 brick[i].color3 = rand() % 255;
			  

		}

	}
	else if (lv == 2)
	{
		int sumx = 90;
		int sumy = 500;

		for (int i = 0; i < totalbricks; i++)
		{
			brick[i].x = sumx;
			brick[i].y = sumy;
			sumx += 102;
			if ((i + 1) % 10 == 0)
			{
				sumy -= 22;
				sumx = 90;
			}
			brick[i].color1 = rand() % 255;
			brick[i].color2 = rand() % 255;
			brick[i].color3 = rand() % 255;
		}
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
