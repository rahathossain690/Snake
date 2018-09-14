
/*
	Used Igrapics.h
	Rahat Hossain
	14 - 9 - 2018
*/
#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
int size = 20;
int dirrection = 1; //1 r,2 l,3 U,4 D
void drawS(int x,int y){
	iFilledRectangle(size*x,size*y,size,size);
	iSetColor(29,29,29);
	iRectangle(size*x+1,size*y+0.5,size-1,size-1);
}
int s[1000][2],l=1;
int foodX,foodY;
int hit;
/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
	iClear();
	iSetColor(29,29,29);
	iFilledRectangle(0,0,400,400);
	if(hit){
		iSetColor(255,255,255);
		iText(150,200,"Click to exit",GLUT_BITMAP_TIMES_ROMAN_24);	
		iPauseTimer(0);
	}
	else{
		iSetColor(255,0,0);
		drawS(foodX,foodY);
		iSetColor(255,255,255);
		for(int i=0;i<l;i++)iSetColor(255,255,255),drawS(s[i][0],s[i][1]);
	}
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		if(hit)exit(0);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
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
	//1 r,2 l,3 U,4 D
	if(key == GLUT_KEY_LEFT)
	{
		if(dirrection!=1)dirrection=2;
	}
	if(key == GLUT_KEY_RIGHT)
	{
		if(dirrection!=2)dirrection=1;
	}
	if(key == GLUT_KEY_UP)
	{
		if(dirrection!=4)dirrection=3;
	}
	if(key == GLUT_KEY_DOWN)
	{
		if(dirrection!=3)dirrection=4;
	}
	//place your codes for other keys here
}
void extend(){
	for(int i=l-1;i>0;i--){
		s[i][0]=s[i-1][0];
		s[i][1]=s[i-1][1];
	}
}
void change(){
	for(int i=1;i<l;i++)if(s[i][0]==s[0][0]&&s[i][1]==s[0][1])hit=1;
	if(s[0][0]==foodX&&s[0][1]==foodY)foodX = rand()%(400/size),foodY = rand()%(400/size),l++;
	extend();
	if(dirrection==1)s[0][0]++;
	if(dirrection==2)s[0][0]--;
	if(dirrection==4)s[0][1]--;
	if(dirrection==3)s[0][1]++;
	if(s[0][0]>=size)s[0][0]=0;
	if(s[0][1]>=size)s[0][1]=0;
	if(s[0][0]<0)s[0][0]=size-1;
	if(s[0][1]<0)s[0][1]=size-1;
}
int main()
{
	//place your own initialization codes here.
	s[0][0] = rand()%(400/size);
	s[0][1] = rand()%(400/size);
	foodX = rand()%(400/size);
	foodY = rand()%(400/size);
	iSetTimer(200,change);
	iInitialize(400, 400, "HUNGRY SNAKE");
	return 0;
}
