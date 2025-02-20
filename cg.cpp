#include&lt;stdlib.h&gt;
#include&lt;Windows.h&gt;
#include&lt;string.h&gt;
#include&lt;stdarg.h&gt;
#include&lt;stdio.h&gt;
#include &lt;GL/glut.h&gt;
static double x=0.0,x1=-3.0,x2=3.0,y1=0.0,y2=0;
static double x8=-4.0,x9=4.0,y8=1.0,y9=1;
static double move=-60;
static bool pca2pcb=false,pca2rt=false,rt2pca=false, pcb2pca=false, local=false,
dubai=false;
void P();
void d();
void *font;
void *currentfont;
void setFont(void *font)
{
currentfont=font;
}
void drawstring(float x,float y,float z,char *string)
{
char *c;
glRasterPos3f(x,y,z);
for(c=string;*c!=&#39;\0&#39;;c++)
{ glColor3f(0.0,1.0,1.0);
glutBitmapCharacter(currentfont,*c);
}
}
void stroke_output(GLfloat x, GLfloat y, char *format,...)
{
va_list args;
char buffer[200], *p;
va_start(args, format);
vsprintf(buffer, format, args);
va_end(args);
glPushMatrix();

glTranslatef(-2.5, y, 0);
glScaled(0.003, 0.005, 0.005);
for (p = buffer; *p; p++)
glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
glPopMatrix();
}
//Windows
void window(float x4, float y4)
{
glLoadIdentity();
glColor3f(1.0,1.5,0.5);
glTranslatef(0.0f,0.0f,-11.0f);
for(float j=-2;j&lt;1.5;j+=.8)
{ for(float i=-3.3;i&lt;-2;i+=0.7)
{ glPushMatrix();
glTranslatef(i,j,-0.2);
glutSolidCube(0.3);
glPopMatrix();
}
}
}
//Windows
void window1(float x5, float y5)
{
glLoadIdentity();
glColor3f(1.5,0,0);
glTranslatef(0.0f,0.0f,-11.0f);
for(float j=-2;j&lt;1.5;j+=.8)
{ for(float i=2.6;i&lt;=3.5;i+=0.7)
{ glPushMatrix();
glTranslatef(i,j,-0.2);
glutSolidCube(0.3);
glPopMatrix();
}
}
}

//Router
void router(float x6, float y6)
{
glLoadIdentity();
glColor3f(0.2,0.3,1);
glTranslatef(0.0f,0.0f,-13.0f);
glPushMatrix();
glScaled(0.45,1.5,0.1);
glRotatef(91,1.0f,0.0f,0.0f);
glTranslatef(x6,y6,-2.0);
glutSolidTorus(0.2,1.5,10,10);
glPopMatrix();
}
//PC Computers
void pc(float x7, float y7, float z7)
{ glLoadIdentity();
glColor3f(0.1,0.1,.1);
glTranslatef(0.0f,0.0f,-13.0f);
glPushMatrix();
glPushMatrix();
glScaled(.7,.7,0);
glRotatef(95,1.0f,0.0f,0.0f);
glTranslatef(x7,y7,z7);
glutSolidCube(1);
glPopMatrix();
glPushMatrix();
glColor3f(1,1,1);
//Condition for pcB to change Color
if(pcb2pca &amp;&amp; x7==5)
glColor3f(1,0,0);
// Condition for PCA to change color
if(pcb2pca &amp;&amp; x9&gt;=-5 &amp;&amp; x9&lt;=-4 &amp;&amp; x7==-5)
glColor3f(1,0,0);
glScaled(.7,.7,0);
glRotatef(95,1.0f,0.0f,0.0f);
glTranslatef(x7,y7,z7);
glutSolidCube(.85);
glPopMatrix();
glPopMatrix();
}
//PC
void cpu(float x7, float y7, float z7)
{ glLoadIdentity();
glColor3f(0.5,0.5,.5);
glTranslatef(0.0f,0.0f,-13.0f);
glPushMatrix();
glPushMatrix();
glScaled(1,.3,0);
glRotatef(95,1.0f,0.0f,0.0f);
glTranslatef(x7,y7,z7);
glutSolidCube(1);
glPopMatrix();
glPushMatrix();
glColor3f(1,1,1);
glScaled(1,.3,0);
glRotatef(95,1.0f,0.0f,0.0f);
glTranslatef(x7,y7,z7);
glutSolidCube(.4);
glPopMatrix();
glPopMatrix();
}
//Draw LAN/WAN
void lan(double x8,double y8)
{
glClearColor(0.6,0.5,.5,0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef(0.0f,0.0f,-13.0f);
router(0,-1);
//Data Media (connected to Router)
glPushMatrix();
glTranslatef(0.0,1.0,-2.0);
glScaled(0.1,5.0,0.1);
glColor3f(1,1,1);
glutWireCube(1.5);
glPopMatrix();
glPushMatrix();
glTranslatef(0.0,0.0,-2.0);
glScaled(5.1,0.1,0.1);
glColor3f(1,1,1);
glutWireCube(1.5);
glPopMatrix();
glPushMatrix();
glTranslatef(0.0,0.0,-2.0);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(0,0,0);
drawstring(1,3.5,-1.0,&quot;ROUTER&quot;);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(0,0,0);
drawstring(-4.6,.5,-1.0,&quot;PC-A&quot;);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(0,0,0);
drawstring(-.5,.5,-1.0,&quot;SWITCH&quot;);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(0,0,0);
drawstring(4,.5,-1.0,&quot;PC-B&quot;);
glPopMatrix();
//Data Transfer
if(pca2pcb){
// data
glPushMatrix();
glTranslatef(x8,y8,-2.0);
glScaled(0.1,0.1,0.1);
glColor3f(x8,0,1);
glutSolidCube(1);
glPopMatrix();
if(x8&gt;=4){

pcb2pca=true;
pca2pcb=false;
} }
//Ack
if(pcb2pca){
glPushMatrix();
glTranslatef(x8,y8,-2.0);
glScaled(0.1,0.1,0.1);
glColor3f(x8,0,1);
glutSolidCube(1);
glPopMatrix();
}
if(pca2rt)
{
glPushMatrix();
glTranslatef(x8,y8,-2.0);
glScaled(0.1,0.1,0.1);
glColor3f(x8,0,1);
glutSolidCube(1);
glPopMatrix();
}
// move the packet out of LAN
if(pca2rt &amp;&amp; rt2pca==false &amp;&amp; y8&gt;=6)
{
glutIdleFunc(P);
}
//switch
glPushMatrix();
glColor3f(0.5,0.5,1.5);
glTranslatef(0.0,0,1.0);
glRotatef(15,1.0f,0.0f,0.0f);
glScaled(1.2,0.2,1.0);
glutSolidCube(1);
glPopMatrix();
pc(-5,1,0);
cpu(-3.5,7,1.5);
pc(5,1,0);
cpu(3.5,7,1.5);
pc(0,20,2);
cpu(0,105,1.5);
glFlush();
glutSwapBuffers();
}
// Draw Network
void network(double ang,double x1,double x2,double y1,double y2)
{
glClearColor(0.0,0.85,1,0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef(0.0f,0.0f,-13.0f);
glBegin(GL_POLYGON);
glColor3f(0.0,1.8,0.0);
glVertex2f(-10,0);
glVertex2f(10,0);
glVertex2f(-10,-10);
glVertex2f(-10,10);
glEnd();
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(0,0,0);
drawstring(-4.2,2.65,0.0,&quot;LOCAL BUILDING&quot;);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(0,0,0);
drawstring(-1.5,3.2,0.0,&quot;EARTH Connected with Fibric Wires&quot;);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(0,0,0);
drawstring(2.5,2.65,0.0,&quot;DUBAI BUILDING&quot;);
//Earth
glPushMatrix();
glColor3f(0.5,0.5,1.5);
glScaled(0.8,1,0.8);
glTranslatef(0.0,2.2,0.0);
glRotatef(ang,0.0f,-1.0f,0.0f);

glutSolidSphere(1,20,20);
glPopMatrix();
//Building A
glLoadIdentity();
glTranslatef(0.0f,0.0f,-12.0f);
glPushMatrix();
glTranslatef(-3,-0.5,0.0);
glScaled(0.8,2.2,0.8);
glutSolidCube(1.8);
glPopMatrix();
window(-2.6, 1);
//Building B
glLoadIdentity();
glTranslatef(0.0f,0.0f,-12.0f);
glPushMatrix();
glTranslatef(3,-0.5,0.0);
glScaled(0.8,2.2,0.8);
glutSolidCube(1.8);
glPopMatrix();
window1(3.3, 1);
// Line 1
glPushMatrix();
glTranslatef(-3.0,1.0,-2.0);
glScaled(0.1,3.0,0.1);
glColor3f(1,1,1);
glutWireCube(1);
glPopMatrix();
glPushMatrix();
glTranslatef(-1.45,2.4,-2.0);
glScaled(3.0,0.2,0.1);
glColor3f(1,1,1);
glutWireCube(1);
glPopMatrix();
//Line 2
glPushMatrix();

glTranslatef(3.0,1.0,-2.0);
glScaled(0.1,3.0,0.1);
glColor3f(1,1,1);
glutWireCube(1);
glPopMatrix();
glPushMatrix();
glTranslatef(1.45,2.4,-2.0);
glScaled(3.0,0.2,0.1);
glColor3f(1,1,1);
glutWireCube(1);
glPopMatrix();
// Transmission of Datapackets
glPushMatrix();
// Send Packets
if(local){
if(x1==-3 &amp;&amp; y1&lt;=2.38)
glTranslatef(-3,y1,-2.0);
if(y1&gt;=2.38 &amp;&amp; x1&lt;=3)
glTranslatef(x1,2.38,-2.0);
if(x1&gt;=3 &amp;&amp; y1&gt;=0)
glTranslatef(3,y1,-2.0);
if(x1&gt;=3 &amp;&amp; y1&lt;=0.0)
{
dubai=true;
local=false;
} }
// Ack packets
if(dubai)
{
if(x2&gt;=3 &amp;&amp; y2&lt;=2.38)
glTranslatef(3,y2,-2.0);
if(y2&gt;=2.38 &amp;&amp; x2&gt;=-3)
glTranslatef(x2,2.38,-2.0);
if(x2&lt;=-3 &amp;&amp; y2&gt;=0.0)
glTranslatef(-3,y2,-2.0);
if(x2&lt;=-3 &amp;&amp; y2&lt;=0.0)

{
dubai=false;
local=true;
rt2pca=true;
x8=0;
y8=6;
glutIdleFunc(d);
} }
glScaled(0.1,0.1,0.1);
glColor3f(1,1,1);
glutSolidCube(1);
glPopMatrix();
glFlush();
glutSwapBuffers();
}
void building(double ang)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef(0.0f,0.0f,-13.0f);
glPushMatrix();
glScaled(0.3,1.5,0.3);
glRotatef(90,1.0f,0.0f,0.0f);
glTranslatef(8.5,0,-0.5);
glutSolidTorus(0.2,1.0,40,40);
glPopMatrix();
glFlush();
glutSwapBuffers();
}
void about()
{
glClearColor(0.0,0.85,1,0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef(0.0f,0.0f,-13.0f);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);

glColor3f(0,0,0);
drawstring(-4.2,2,0.0,&quot;About Data Communication&quot;);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(0,0,0);
drawstring(-3.5,1.5,0.0,&quot;1. Data Communications refers to the exchange of
data between two devices&quot;);
glColor3f(0,0,0);
drawstring(-3.5,1,0.0,&quot; form of transmission medium such as a wire
cable.&quot;);
glColor3f(0,0,0);
drawstring(-3.5,.5,0.0,&quot;2. Similarly data and information from one computer
system can be transmitted to&quot;);
glColor3f(0,0,0);
drawstring(-3.5,0.0,0.0,&quot; other systems across geographical areas.&quot;);
glColor3f(0,0,0);
drawstring(-3.5,-0.5,0.0,&quot;3. Thus data transmission is the movement of
information using some standard methods.&quot;);
glColor3f(0,0,0);
drawstring(-3.5,-1,0.0,&quot;4. The effectiveness of a data communications
system depends on&quot;);
glColor3f(0,0,0);
drawstring(-3.5,-1.5,0.0,&quot; four fundamental characteristics: delivery,
accuracy, timeliness, and jitter.&quot;);
glColor3f(0,0,0);
drawstring(-3.5,-2,0.0,&quot;5. A network is two or more devices connected
through links.&quot;);
glColor3f(0,0,0);
drawstring(-3.5,-2.5,0.0,&quot;6. A link is a communications pathway that
transfers data from one device to another.&quot;);
glColor3f(0,0,0);
drawstring(-3.5,-3,0.0,&quot;7. Type of Connection : Point-to-Point &amp;
Multipoint.&quot;);
glFlush();
glutSwapBuffers();
}
void s()

{
lan(-4,1);
}
void n()
{
x-=0.07;
network(x,0,0,0,0);
}
void P()
{
if(local)
{
if(x1==-3 &amp;&amp; y1&lt;=2.38){
y1+=0.01;
}
if(y1&gt;=2.38 &amp;&amp; x1&lt;=3.0)
{ x1+=0.01;
}
if(x1&gt;=3 &amp;&amp; y1&gt;=0.0){
y1-=0.01;
}
x+= .07;
network(x,x1,x2,y1,y2);
}
//Dubai to local
if(dubai)
{
if(x2&gt;=3 &amp;&amp; y2&lt;=2.38)
y2+=0.01;
if(y2&gt;=2.38 &amp;&amp; x2&gt;=-3)
x2-=0.01;
if(x2&lt;=-3 &amp;&amp; y2&gt;=0.0)
y2-=0.01;
x+= .07;
network(x,x1,x2,y1,y2);
} }

void d()
{
if(pca2pcb)
{ if(x8&gt;=-4 &amp;&amp; x8&lt;=4){
x8+=0.01;
}
lan(x8,0);
}
if(pcb2pca)
{
if(x9&lt;=4 &amp;&amp; x9&gt;=-4){
x9-=0.01;
}
lan(x9,0);
}
// To Dubai
if(pca2rt &amp; rt2pca==false)
{
if(x8&gt;=-4 &amp;&amp; y8&lt;=6){
if(x8&lt;=0)
{x8+=0.01;
}
if(x8&gt;=0 &amp;&amp; y8&lt;=6)
{
y8+=0.01;
}
}
lan(x8,y8);
}
if(rt2pca)
{
if(x8&lt;=0 &amp;&amp; y8&lt;=6){
if(y8&gt;=0)
{y8-=0.01;
}
if(x8&gt;=-4 &amp;&amp; y8&lt;=0)

{
x8-=0.01;
} }
lan(x8,y8);
} }
void doInit()
{
/* Background and foreground color */
glClearColor(0.0,0.0,0.0,0);
glViewport(0,0,640,480);
/* Select the projection matrix and reset it then
setup our view perspective */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(30.0f,(GLfloat)640/(GLfloat)480,0.1f,200.0f);
/* Select the modelview matrix, which we alter with rotatef() */
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glClearDepth(2.0f);
glEnable(GL_DEPTH_TEST);
glDepthFunc(GL_LEQUAL);
}
void display()
{
glClearColor(0.1,0.1,0.5,0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glTranslatef(0.0f,0.0f,-13.0f);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(3.0,1.0,1.0);
drawstring(-1.5,3.0,0.0,&quot;DEPARTMENT OF COMPUTER SCIENCE&quot;);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(0.0,1.0,1.0);
drawstring(-3.0,2.5,0.0,&quot;Computer Graphics Mini Project on DATA
COMMUNICATION IN NETWORK&quot;);

setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(0.0,1.0,1.0);
drawstring(-1,2,0,&quot;Using OPENGL&quot;);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(0.0,1.0,1.0);
drawstring(-0.5,1.5,0,&quot;By&quot;);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(0.0,1.0,1.0);
drawstring(-2,1,0,&quot;Hemalatha N K  (USN : 4HG20CS009)&quot;);
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
glColor3f(0.0,1.0,1.0);
drawstring(-2,.5,0,&quot;Vinay N (USN : 4HG20CS033)&quot;);
stroke_output(-2.0, -1, &quot;s --&gt; Start&quot;);
stroke_output(-2.0, -1.75, &quot;A --&gt; About&quot;);
stroke_output(-2.0, -3,&quot;q --&gt; Quit&quot;);
GLfloat mat_ambient[]={0.0f,1.0f,2.0f,1.0f};
GLfloat mat_diffuse[]={0.0f,1.5f,.5f,1.0f};
GLfloat mat_specular[]={5.0f,1.0f,1.0f,1.0f};
GLfloat mat_shininess[]={50.0f};
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
GLfloat lightIntensity[]={1.7f,1.7f,1.7f,1.0f};
GLfloat light_position3[]={0.0f,5.0f,5.0f,0.0f};
glLightfv(GL_LIGHT0,GL_POSITION,light_position3);
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
glEnable(GL_COLOR_MATERIAL);
glFlush();
glutSwapBuffers();
}
void menu(int id)
{
switch(id)
{
case 1:glutIdleFunc(about);

break;
case 2:glutIdleFunc(s);
break;
case 3:glutIdleFunc(d);
break;
case 4:glutIdleFunc(P);
break;
case 5:glutIdleFunc(n);
break;
case 6:
pca2pcb=true;
x8=-4;
glutIdleFunc(d);
break;
case 7:
local=true;
dubai=false;
pca2rt=true;
x8=-4.0;x9=4.0;y8=0.0; y9=0;
pca2pcb=false;
pcb2pca=false;
glutIdleFunc(d);
break;
case 8: pca2rt=false;
pca2pcb=false;
x8=-4.0;x9=4.0;y8=1.0; y9=0;
x=0.0;x1=-3.0;x2=3.0;y1=0.0;y2=2.38;
pca2pcb=false;pca2rt=false; pcb2pca=false;

glutIdleFunc(s);
break;
case 9:exit(0);
break;
}
glFlush();
glutSwapBuffers();
glutPostRedisplay();

}
void mykey(unsigned char key,int x,int y)
{
if(key==&#39;s&#39;)
{
glutIdleFunc(s);
}
if(key==&#39;n&#39;)
{
glutIdleFunc(n);
}
if(key==&#39;P&#39;)
{
glutIdleFunc(P);
}
if(key==&#39;A&#39;)
{
glutIdleFunc(about);
}
if(key==&#39;q&#39;||key==&#39;Q&#39;)
{
exit(0);
}
}
void main(int argc, char *argv[])
{
glutInit(&amp;argc, argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowSize(1000,480);
glutInitWindowPosition(0,0);
glutCreateWindow(&quot;Data Communication in Network&quot;);
glutDisplayFunc(display);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glShadeModel(GL_SMOOTH);
glEnable(GL_DEPTH_TEST);

glEnable(GL_NORMALIZE);
glutKeyboardFunc(mykey);
glutCreateMenu(menu);
glutAddMenuEntry(&quot;About Project &#39;A&#39;&quot;,1);
glutAddMenuEntry(&quot;Local Area Network(LAN) &#39;s&#39;&quot;,2);
glutAddMenuEntry(&quot;Local Area Network(LAN) &#39;n&#39;&quot;,3);
glutAddMenuEntry(&quot;Wide Area Network(WAN) &#39;P&#39;&quot;,5);
glutAddMenuEntry(&quot;Transfer data from PC-A to PC-B &#39;1&#39;&quot;,6);
glutAddMenuEntry(&quot;Transfer data from PC-A to Company B --&gt;&#39;2&#39;&quot;,7);
glutAddMenuEntry(&quot;Reset &#39;r&#39;&quot;,8);
glutAddMenuEntry(&quot;Quit &#39;q&#39;&quot;,9);
glutAttachMenu(GLUT_RIGHT_BUTTON);
doInit();
glutMainLoop();
}
