// Inicjuję grę dopiero po załadowaniu całej strony
window.onload = function(){
	Game.spr = new Image();
	Game.spr.onload = Game.init;
	Game.spr.src = 'bombe.png';
}
// Obiekt, w którym będą przechowywane „podręczne” wartości
VAR = {
	fps:15,// animacja w Bombermenie nie była tak płynna jak we współczesnych grach
	W:0,// szerokość okna
	H:0,// wysokość okna
	scale:4,// elementy gry będą wklejane w odpowiedniej skali
	//
	lastTime:0,
	rand:function(min,max){
		return Math.floor(Math.random()*(max-min+1))+min;
	}
}
// Obiekt zawierający bazowe funckje związane z grą.
// Game nie ma konstruktora, jest jedynie obiektem grupującym funkcje.
Game = {
	// init zostanie odpalone raz po załadowaniu strony.
	init:function(){
		// Tworzę canvas
		Game.canvas = document.createElement('canvas');
		// Przypisuję kontekst 2D do zmiennej ctx, która jest właściwością obiektu Game
		Game.ctx = Game.canvas.getContext('2d');
		// odpalam metodę obiektu Game
		Game.layout();
		// metoda layout odpali się przy każdej zmianie wielkości okna
		window.addEventListener('resize', Game.layout, false);
		// Canvas zostaje dodany do DOM
		document.body.appendChild(Game.canvas);

		Game.toDraw = {};

		Game.hero = new Character();
		// rozpoczęcie pętli gry
		Game.animationLoop();
	},
	// Ta metoda będzie odpalana przy każdej zmianie wielkości okna
	layout:function(ev){
		// Dla łatwiejszego pisania wielkość okna zostaje przypisana do właściwości W i H obiektu VAR
		VAR.W = window.innerWidth;
		VAR.H = window.innerHeight;
		// Chwilowo do canvas przypiszemy wielkość okna
		Game.canvas.width = VAR.W;
		Game.canvas.height = VAR.H;

		Game.ctx.imageSmoothingEnabled = false;
	},
	// Funkcja, która odpala się 60 razy na sekundę
	animationLoop:function(time){
		requestAnimationFrame( Game.animationLoop );
		// ograniczenie do ilości klatek zdefiniowanych w właściwości obiektu VAR (nie więcej niż VAR.fps)
		if(time-VAR.lastTime>=1000/VAR.fps){
			VAR.lastTime = time;
			//
			// oczyszczenie canvas
			Game.ctx.clearRect(0,0,VAR.W, VAR.H);
			for(var o in Game.toDraw)
			{
				Game.toDraw[o].draw();
			}
		}
	}
}