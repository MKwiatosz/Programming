//
Character.count = 0;
function Character(inheritance){
	//
	Character.count++;
	//
	this.id = 'char_'+Character.count;
	//
	if(!inheritance){
		Game.toDraw[this.id] = this;
	}
	//
	this.fW = 21;
	this.fH = 24;
	//
	// Te właściwości będą przechowywane w liście stanów każdej postaci
	// this.start_fx = 0;
	// this.start_fy = 0;
	// this.frames = [1,0,2,0];
	this.states = {};
	// 
	this.current_f = 0;
	//
	this.change_f_delay = 0;
	this.f_max_delay = 2;
}
Character.prototype.draw = function(){
	// Jeśli postać jest odbijana lustrzanie (poruszanie w lewo)
	if(this.states[this.state].flip){
		// Zapisz wszystkie ustawienia canvas
		Game.ctx.save();
		// Zmień skalę
		Game.ctx.scale(-1,1);
	}
	Game.ctx.drawImage(
		Game.spr,
		this.states[this.state].sx+this.states[this.state].f[this.current_f]*this.fW,// nie ma start_fx, tylko jest obiekt aktualnego stanu, który ma sx i sy oraz listę klatek
		this.states[this.state].sy,
		this.fW,
		this.fH,
		(this.states[this.state].flip ? -this.fW*VAR.scale : 0),// jeśli postać jest odbita lustrzanie jego pozycja musi zostać przesunięta o szerokość klatki i pomnożona przez -1
		0,
		this.fW*VAR.scale,
		this.fH*VAR.scale
	);
	// Jeśli postać jest odbijana lustrzanie (poruszanie w lewo)
	if(this.states[this.state].flip){
		// Powróć do ustawień sprzed zapisania
		Game.ctx.restore();
	}
	if(this.change_f_delay<this.f_max_delay){
		this.change_f_delay++;
	}else{
		this.change_f_delay = 0;
		// this frames zamieniło się na tablicę z odpowiedniego stanu
		this.current_f = this.current_f+1>=this.states[this.state].f.length ? 0 : this.current_f+1;
	}
};
// Obiekt typu Hero dziedziczy właściwości i metody od obiektu typu Character
function Hero(){
	Character.call(this);
	// lista wszystkich stanów
	this.state = 'right_go';
	this.states = {
		'down':{sx:0, sy:0, f:[0]},// sx = pozycja x pierwszej klatki, sy = pozycja y pierwszej klatki, lista klatek (jeśli postać stoi to potrzebna jest tylko jedna klatka)
		'down_go':{sx:0, sy:0, f:[1,0,2,0]},
		'up':{sx:0, sy:24, f:[0]},
		'up_go':{sx:0, sy:24, f:[1,0,2,0]},
		'left':{sx:63, sy:0, f:[0]},
		'left_go':{sx:63, sy:0, f:[1,0,2,0]},
		'right':{sx:63, sy:0, f:[0], flip:true}, // aby postać szła w prawo, musimy odbić lustrzanie wszystkie klatki ruchu w lewo
		'right_go':{sx:63, sy:0, f:[1,0,2,0], flip:true}, // zrobimy to dla każdego stanu w którym flip jest prawdziwe
		'ko':{sx:0, sy:48, f:[0,1,0,1,0,1,2,3,4,4,4]}
	}
}
// Dziedziczenie
Hero.prototype = new Character(true);
// Ręczne przypisanie prawidłowego konstruktora
Hero.prototype.construktor = Hero;

function Enemy()
{
	Character.call(this);
	this.state = 'up_go';
	this.states = {
		'down'    :{sx:0, sy:72, f:[0]},// sx = pozycja x pierwszej klatki, sy = pozycja y pierwszej klatki, lista klatek (jeśli postać stoi to potrzebna jest tylko jedna klatka)
		'down_go' :{sx:0, sy:72, f:[1,0,2,0]},
		'left'    :{sx:63, sy:24, f:[0]},
		'left_go' :{sx:63, sy:24, f:[1,0,2,0]},
		'up'      :{sx:63, sy:72, f:[0]},
		'up_go'   :{sx:63, sy:72, f:[1,0,2,0]},
		'right'   :{sx:63, sy:24, f:[0], flip:true}, // aby postać szła w prawo, musimy odbić lustrzanie wszystkie klatki ruchu w lewo
		'right_go':{sx:63, sy:24, f:[1,0,2,0], flip:true}, // zrobimy to dla każdego stanu w którym flip jest prawdziwe
		'ko'      :{sx:0, sy:96, f:[0,1,2,3,4,5]}
	}
}

	// Dziedziczenie
	Enemy.prototype = new Character(true);
	// Ręczne przypisanie prawidłowego konstruktora
	Enemy.prototype.construktor = Enemy;