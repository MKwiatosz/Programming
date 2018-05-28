
var CanvasCenterX 	= innerWidth/2;
var CanvasCenterY 	= innerHeight/2;

var spot =
{
	x:100,
	y:50
};

var col =
{
	r: 255,
	g: 0,
	b:0
};

function setup() {
	 createCanvas(innerWidth, innerHeight);
	 background(130,132,43);
}

function draw() {
	noStroke();
	col.r	= random(0,255);
	col.g	= random(0,255);
	col.b	= random(0,255);

	var alpha	= random(0,255);

	spot.x = random(0,innerWidth);
	spot.y = random(0,innerHeight);
	fill(col.r,col.g,col.b,alpha);
	ellipse(spot.x,spot.y,50,50);
}
