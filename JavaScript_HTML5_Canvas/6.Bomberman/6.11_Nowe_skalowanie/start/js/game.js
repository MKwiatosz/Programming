// Inicjuję grę dopiero po załadowaniu całej strony
window.onload = function(){
	// Najpierw muszę załadować obrazek (tutaj mógłby pojawić się preloader, aby gracz wiedział, że są ładowane niezbędne pliki).
	Game.spr = new Image();
	// Dopiero po załadowaniu obrazka zostanie zainicjalizowana gra
	Game.spr.onload = Game.init;
	Game.spr.src = 'bombe.png';
}
// Obiekt, w którym będą przechowywane „podręczne” wartości
VAR = {
	fps:16,// animacja w Bombermenie nie była tak płynna jak we współczesnych grach
	W:0,// szerokość okna
	H:0,// wysokość okna
	scale:4,// elementy gry będą wklejane w odpowiedniej skali
	//
	lastTime:0,
	rand:function(min,max){
		return Math.floor(Math.random()*(max-min+1))+min;
	},
	// Metoda shuffle bazuje na algorytmie wymyślonym przez Ronalda Fisher'a and Franka Yates'a
	// Więcej tutaj: https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
	shuffle:function(arr){
		var counter = arr.length; // licznik, wartość początkowa to ilość elementów w tablicy
		var tmp; // będzie chwilowo przechowywał przestawiany element z tablicy
		var index; // losowany index przestawianego elementu
		// Pętla while będzie się odtwarzała do momentu aż counter będzie równy zero
		while(counter>0){
			// counter maleje o jeden
			counter--;
			// Losowy indeks z zakresu od 0 do counter (counter za każdym razem maleje)
			index = Math.floor(Math.random() * counter);
			// 
			// Zamienianie elementów
			// weź element z pozycji counter
			tmp = arr[counter];
			// w pozycję counter wstaw element z pozycji wylosowanej index
			arr[counter] = arr[index];
			arr[index] = tmp;
		}
		// zwróć potasowaną tablicę
		return arr;
	}
}
// Obiekt zawierający bazowe funckje związane z grą.
// Game nie ma konstruktora, jest jedynie obiektem grupującym funkcje.
//

Game = {
	toDraw:{},// tym razem stworzymy jeden obiekt, w którym będą przechowywane elementy do narysowania w każdej klatce
	// init zostanie odpalone raz po załadowaniu strony.
	init:function(){
		// Tworzę canvas
		Game.canvas = document.createElement('canvas');
		// Przypisuję kontekst 2D do zmiennej ctx, która jest właściwością obiektu Game
		Game.ctx = Game.canvas.getContext('2d');
		Game.board = new Board();
		// odpalam metodę obiektu Game
		Game.layout();
		// metoda layout odpali się przy każdej zmianie wielkości okna
		window.addEventListener('resize', Game.layout, false);
		// Canvas zostaje dodany do DOM
		document.body.appendChild(Game.canvas);
		// Tworzymy nową planszę

		// rozpoczęcie pętli gry
		Game.animationLoop();
	},
	// Ta metoda będzie odpalana przy każdej zmianie wielkości okna
	layout:function(ev){
		// Dla łatwiejszego pisania wielkość okna zostaje przypisana do właściwości W i H obiektu VAR
		VAR.W = window.innerWidth;
		VAR.H = window.innerHeight;
		// Chwilowo do canvas przypiszemy wielkość okna
		VAR.scale = Math.max(1, Math.min(
			Math.floor(VAR.W/(Game.board.fW*Game.board.b[0].length)),
			Math.floor(VAR.H/(Game.board.fH*Game.board.b.length))
		));
		// Szerokość canvas to ilość modułów pomnożona przez szerokość modułu i przez skalę
		Game.canvas.width = Math.round(VAR.scale*Game.board.fW*Game.board.b[0].length);
		// Analogicznie wysokość
		Game.canvas.height = Math.round(VAR.scale*Game.board.fH*Game.board.b.length);

		Game.canvas.style[Modernizr.prefixed('transform')] = 'translate('+Math.round((VAR.W-Game.canvas.width)/2)+'px,'+Math.round((VAR.W-Game.canvas.height)/2)+'px)';
		// Nie chcę blurowania (trzeba updatować za każdym razem gdy zmieni się rozmiar canvas)
		Game.ctx.imageSmoothingEnabled = false;
		Game.ctx.mozImageSmoothingEnabled = false;
		Game.ctx.oImageSmoothingEnabled = false;
		Game.ctx.webkitImageSmoothingEnabled = false;
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
			// Rysowanie planszy
			Game.board.draw();
			// Dla wszystkich obiektów znajdujących się w toDraw wywołaj ich metodę draw()
			for(var o in Game.toDraw){
				Game.toDraw[o].draw();
			}
		}
	}
}