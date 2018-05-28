
var CanvasCenterX 	= innerWidth/2;
var CanvasCenterY 	= innerHeight/2;

var col	=	0;

var colX	=	0;
var colY	=	0;

function setup() {
	 createCanvas(innerWidth, innerHeight);

}

function draw() {
	// background
	background(colX,colY);
	// background(col);

	// mapping
	colX =map(mouseX,0,innerWidth,0,255);
	colY =map(mouseY,0,innerHeight,0,255);
	//circle
	fill(250,118,222);
	ellipse(mouseX,mouseY,64,64);
}
