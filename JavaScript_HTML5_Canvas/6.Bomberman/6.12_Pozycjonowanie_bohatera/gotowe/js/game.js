// Zachowałem tylko komentarze tam gdzie coś się zmieniło
window.onload = function(){
	Game.spr = new Image();
	Game.spr.onload = Game.init;
	Game.spr.src = 'bombe.png';
}

VAR = {
	fps:16,
	W:0,
	H:0,
	scale:4,
	//
	lastTime:0,
	rand:function(min,max){
		return Math.floor(Math.random()*(max-min+1))+min;
	},
	shuffle:function(arr){
		var counter = arr.length; 
		var tmp; 
		var index; 
		while(counter>0){
			counter--;
			index = Math.floor(Math.random() * counter);
			tmp = arr[counter];
			arr[counter] = arr[index];
			arr[index] = tmp;
		}
		return arr;
	}
}

Game = {
	toDraw:{},
	init:function(){
		Game.canvas = document.createElement('canvas');
		Game.ctx = Game.canvas.getContext('2d');
		//
		Game.board = new Board();
		//Dodanie bohatera
		Game.hero = new Hero();
		// 
		Game.layout();
		window.addEventListener('resize', Game.layout, false);
		document.body.appendChild(Game.canvas);
		Game.animationLoop();
	},
	layout:function(ev){
		VAR.W = window.innerWidth;
		VAR.H = window.innerHeight;
		//
		VAR.scale = Math.max(1, Math.min(
			Math.floor(VAR.W/(Game.board.fW*Game.board.b[0].length)),
			Math.floor(VAR.H/(Game.board.fH*Game.board.b.length))
		));
		//
		Game.canvas.width = Math.round(VAR.scale*Game.board.fW*Game.board.b[0].length);
		Game.canvas.height = Math.round(VAR.scale*Game.board.fH*Game.board.b.length);
		Game.canvas.style[Modernizr.prefixed('transform')] = 'translate('+Math.round((VAR.W-Game.canvas.width)/2)+'px,'+Math.round((VAR.H-Game.canvas.height)/2)+'px)'
		//
		Game.ctx.imageSmoothingEnabled = false;
		Game.ctx.mozImageSmoothingEnabled = false;
		Game.ctx.oImageSmoothingEnabled = false;
		Game.ctx.webkitImageSmoothingEnabled = false;
	},
	animationLoop:function(time){
		requestAnimationFrame( Game.animationLoop );
		if(time-VAR.lastTime>=1000/VAR.fps){
			VAR.lastTime = time;
			//
			Game.ctx.clearRect(0,0,VAR.W, VAR.H);
			Game.board.draw();
			for(var o in Game.toDraw){
				Game.toDraw[o].draw();
			}
		}
	}
}