let bubbles = [];

function setup() {
  createCanvas(window.innerWidth, window.innerHeight);
  
}

function mouseDragged() {
  let d = random(10, 50);
  let b = new Bubble(mouseX, mouseY, d);
  bubbles.push(b);
}

function draw() {

  background(0);
  for (let i = 0; i < bubbles.length; i++) {
    bubbles[i].move();
    bubbles[i].show();
  }
}



class Bubble {

  constructor(x, y, d, r, g, b) {
    this.x = x;
    this.y = y;
    
    this.d = d;

    this.r  = random(0,255);
    this.g  = random(0,255);
    this.b  = random(0,255);

    this.c_r = floor(random(0,2));
  }

  move() {
    this.x = this.x + random(-5, 5);
    this.y = this.y + random(-5, 5);
  }

  show() {

    if (this.c_r==0) {  
      stroke(255);
      strokeWeight(0);
      fill(this.r,this.g,this.b)
      ellipse(this.x, this.y, this.d * 2);
    }else{
      fill(this.r,this.g,this.b);
      rect(this.x, this.y, this.d,this.d);
    }
  }

}





