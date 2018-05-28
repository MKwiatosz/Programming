
let bubble1;
let bubble2;


function setup() {
  createCanvas(innerWidth, innerHeight);

  bubble1 = new Bubble();
  bubble2 = new Bubble();
}

function draw() {

  background(0);

  bubble1.move();
  bubble1.show();
  bubble1.grow();
  bubble2.move();
  bubble2.show();
  bubble2.grow();

}

class Bubble{

  constructor(){
    this.x = random(0,innerWidth);
    this.y = random(0,innerHeight);
    this.diameter = 24;
  }

  move() {
    this.x+=random(-5,5); 
    this.y+=random(-5,5);  
  }

  show(){

  var r = random(200,255);
  var g = random(0,255);
  var b = random(0,50);

  r = map(mouseX, 0, innerWidth, 200, 255);
  g = map(mouseY, 0, innerHeight, 0, 255);
  b = map(mouseX, 0, innerWidth, 0, 50);
    
    noStroke();    
    fill(r,g,b);
    ellipse(this.x,this.y,this.diameter,this.diameter);
  }

  grow(){

    if (mouseIsPressed) {
      this.diameter+=1;
    }
    else{
      this.diameter+=-0.8;
    }
  }
}
