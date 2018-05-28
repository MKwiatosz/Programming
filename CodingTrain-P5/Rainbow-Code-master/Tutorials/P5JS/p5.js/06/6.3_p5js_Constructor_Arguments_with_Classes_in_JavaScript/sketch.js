let bubble1;
let bubble2;

function setup() {
  createCanvas(innerWidth, innerHeight);
  bubble1 = new Bubble(random(0,innerHeight),random(0,innerHeight),random(10,50));
  bubble2 = new Bubble(random(0,innerHeight),random(0,innerHeight),random(10,50));
}

function draw() {
  background(0);
  bubble1.move();
  bubble1.show();
  bubble2.move();
  bubble2.show();
}

class Bubble {

  constructor(x, y, r) {
    this.x = x;
    this.y = y;
    this.r = r;
  }

  move() {
    this.x = this.x + random(-5, 5);
    this.y = this.y + random(-5, 5);
  }

  show() {
    stroke(255);
    strokeWeight(4);
    noFill();
    ellipse(this.x, this.y, this.r * 2);
  }

  
  
}
