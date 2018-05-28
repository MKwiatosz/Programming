
var CanvasCenterX 	= innerWidth/2;
var CanvasCenterY 	= innerHeight/2;

var r	=	rand(0,255);
var g	=	rand(0,255);
var b	=	rand(0,255);


var circle1 = {
	x:CanvasCenterX,
	y:CanvasCenterY,
	diameter:50,
};

var circle2 = {
	x:rand(0,innerWidth),
	y:rand(0,innerHeight),
	diameter:20,
};

var rect1 = {
	diameter:10,
};

function setup() {
	createCanvas(innerWidth, innerHeight);
	background(rand(50,200),rand(50,200),rand(50,200));
}

function draw() {
	
	noStroke();
	fill(r,g,b);
	ellipse(circle1.x,circle1.y,circle1.diameter,circle1.diameter);

	//noStroke();
	fill(0,g,b);
	rectMode(CENTER);
	rect(innerWidth/2,innerHeight/2,rect1.diameter,rect1.diameter,20);

	rect1.diameter+=0.5;


	noStroke();
	fill(r,g,b);

	ellipse(circle2.x,circle2.y,circle2.diameter,circle2.diameter);

	r +=0.3;
	g +=0.3;
	b +=0.3;
	circle2.diameter	+= 1;
	circle1.diameter	+= 2;
}

function mousePressed() {
	background(150,200,0);
}

function rand(min, max) {
    return Math.random() * (max - min) + min;
}