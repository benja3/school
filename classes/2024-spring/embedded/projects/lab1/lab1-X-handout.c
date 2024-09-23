#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "/usr/include/X11/Xlib.h"
#include "/usr/include/X11/Xutil.h"

#include "imgdisp.h"

main(int argc, char *argv[])
{
Display*	    Monitor;
Window			ImageWindow;
GC				ImageGC;
XWindowAttributes		Atts;
XImage*			Picture;
int				ROWS,COLS;
unsigned char*  displaydata;

FILE*			image_file;
char 			mode[64];
int 			rows, cols, range;



// decide which image 
if(argv[1] == NULL)
{
	goto bad_input;
}
else if (*argv[1] == '0')
{
	image_file = fopen("img/bridge.ppm", "rb");
}
else if (*argv[1] == '1')
{
	image_file = fopen("img/retina.ppm", "rb");
}
else 
{
	bad_input:

	printf("options: \n0: bridge.ppm\n1: retina.ppm\n");
	exit(1);
}

assert(image_file != NULL);

// grab image metadata
fscanf(image_file,"%s %d %d %d",mode,&cols,&rows,&range);

// allocate space for displaydata
displaydata = (unsigned char *) calloc(cols * rows, sizeof(unsigned char));

// for all bytes in image data, convert to display data appropriately


exit(0);

Monitor=XOpenDisplay(NULL);
if (Monitor == NULL)
  {
  printf("Unable to open graphics display\n");
  exit(0);
  }

ImageWindow=XCreateSimpleWindow(Monitor,RootWindow(Monitor,0),
	50,10,		/* x,y on screen */
	COLS,ROWS,	/* width, height */
	2, 		/* border width */
	BlackPixel(Monitor,0),
	WhitePixel(Monitor,0));

ImageGC=XCreateGC(Monitor,ImageWindow,0,NULL);

XMapWindow(Monitor,ImageWindow);
XFlush(Monitor);
while(1)
  {
  XGetWindowAttributes(Monitor,ImageWindow,&Atts);
  if (Atts.map_state == IsViewable /* 2 */)
    break;
  }

Picture=XCreateImage(Monitor,DefaultVisual(Monitor,0),
		DefaultDepth(Monitor,0),
		ZPixmap,	/* format */ 
		0,		/* offset */ 
		displaydata,/* the data */ 
		COLS,ROWS,	/* size of the image data */ 
		16,		/* pixel quantum (8, 16 or 32) */ 
		0);		/* bytes per line (0 causes compute) */ 

XPutImage(Monitor,ImageWindow,ImageGC,Picture,
		0,0,0,0,	/* src x,y and dest x,y offsets */
		COLS,ROWS);	/* size of the image data */

XFlush(Monitor); // flush (send) contents of display buffer

sleep(2); // wait for 2 seconds with image on screen

XCloseDisplay(Monitor);
}

