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
		// Dodanie nasłuchiwaczy
		window.addEventListener('keydown', Game.onKey, false);
		window.addEventListener('keyup', Game.onKey, false);
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
	onKey:function(ev){
		// reaguj tylko jeśli zostały wciśnięte strzałka w lewo, do góry, w prawo, w dół lub spacja
		if((ev.keyCode>=37 && ev.keyCode<=40) || ev.keyCode==32){
			// Jeśli guzik został wciśnięty i jednocześnie nie był on wciśnięty wcześniej (w obiekcie Game zapisujemy jaki guzik jest wciśnięty, zabezpieczamy się w ten sposób przed systemowym auto-powtarzaniem wciskania guzika)
			// Zamiast notacji kropkowej (np.: Game.key_39) stosuję nawiasy kwadratowe, dzięki temu nie muszę pisać długiej ifki i sprawdzać po kolei każdej możliwości
			if(ev.type=='keydown' && !Game['key_'+ev.keyCode]){
				Game['key_'+ev.keyCode] = true;
				// Jeśli została wciśnięta strzałka wyłącz wszystki inne strzałki (postać może iść na raz tylko w jedną stronę)
				if(ev.keyCode>=37 && ev.keyCode<=40){
					for(var i=37; i<=40; i++){
						if(i!=ev.keyCode){
							Game['key_'+i] = false;
						}
					}
				}
				// Aktualizuj stan
				Game.hero.updateState();
			}else if(ev.type=='keyup'){// w przypadku gdy guzik został zwolniony przypisz odpowiedniej właściwości obiektu Game false
				Game['key_'+ev.keyCode] = false;
				// Aktualizuj stan
				Game.hero.updateState();
			}
		}
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