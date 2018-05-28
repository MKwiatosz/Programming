/*
https://vimeo.com/channels/learningp5js/139587732
*/

function setup() {
  createCanvas(innerWidth, innerHeight);
}

function draw() {
  background(50);
  lollipop(100,200,50);
  lollipop(10,10,10);
}

function lollipop(x, y, diameter) {

  fill(random(0,255),random(0,255) ,random(0,255));
  rectMode(CENTER);
  rect(innerWidth/2, innerHeight/2, 20, 150);
  
  fill(255, 0, 200);
  ellipse(innerWidth/2, innerHeight/2-y/2, diameter, diameter);
}