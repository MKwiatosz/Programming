/* 

1. Code below is for https://vimeo.com/channels/learningp5js/141211396
2. Video reference at 0:20 seconds on Objects > https://vimeo.com/channels/learningp5js/138327558

*/

var nums = [100, 35, 46, 72];
var word = ["Michał","Kwiatosz","Żółw","Tablica","YOLO","KUUURWAA"]

var num = 23;
var index = 0;

function setup() {
  createCanvas(innerWidth,innerHeight);
}

function draw() {
background(0);

fill(255);
textSize(20);
text(word[index],12,207);

ellipse(100, 200, num, num);
ellipse(200, 200, nums[2], nums[2]);

}

function mousePressed(){

	index+=1;

	if (index==word.length) {
		index=0;
	}
}