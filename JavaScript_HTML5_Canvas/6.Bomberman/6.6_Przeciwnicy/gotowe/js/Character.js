// Dla zachowania czytelności pozostawiłem tylko komentarze przy zmienach
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
	this.states = {};
	// 
	this.current_f = 0;
	//
	this.change_f_delay = 0;
	this.f_max_delay = 2;
}
Character.prototype.draw = function(){
	//
	if(this.states[this.state].flip){
		Game.ctx.save();
		Game.ctx.scale(-1,1);
	}
	//
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
	//
	if(this.states[this.state].flip){
		Game.ctx.restore();
	}
	//
	if(this.change_f_delay<this.f_max_delay){
		this.change_f_delay++;
	}else{
		this.change_f_delay = 0;
		this.current_f = this.current_f+1>=this.states[this.state].f.length ? 0 : this.current_f+1;
	}
};
function Hero(){
	Character.call(this);
	this.state = 'right_go';
	this.states = {
		'down':{sx:0, sy:0, f:[0]},
		'down_go':{sx:0, sy:0, f:[1,0,2,0]},
		'up':{sx:0, sy:24, f:[0]},
		'up_go':{sx:0, sy:24, f:[1,0,2,0]},
		'left':{sx:63, sy:0, f:[0]},
		'left_go':{sx:63, sy:0, f:[1,0,2,0]},
		'right':{sx:63, sy:0, f:[0], flip:true},
		'right_go':{sx:63, sy:0, f:[1,0,2,0], flip:true},
		'ko':{sx:0, sy:48, f:[0,1,0,1,0,1,2,3,4,4,4]}
	}
}
Hero.prototype = new Character(true);
Hero.prototype.construktor = Hero;
//
//
// Właściwość all obiektu Enemy będzie przechowywać wszystkich wrogów
Enemy.all = {};
// Obiekt typu Enemy dzedziczy od obiektu typu Character
function Enemy(){
	// Dziedziczenie właściwości
	Character.call(this);
	//
	// Dodanie tworzonej instancji do obiektu all
	Enemy.all[this.id] = this;
	// Definicja stanów
	this.state = 'down_go';
	this.states = {
		'down':{sx:0, sy:72, f:[0]},
		'down_go':{sx:0, sy:72, f:[1,0,2,0]},
		'up':{sx:63, sy:72, f:[0]},
		'up_go':{sx:63, sy:72, f:[1,0,2,0]},
		'left':{sx:63, sy:24, f:[0]},
		'left_go':{sx:63, sy:24, f:[1,0,2,0]},
		'right':{sx:63, sy:24, f:[0], flip:true},
		'right_go':{sx:63, sy:24, f:[1,0,2,0], flip:true},
		'ko':{sx:0, sy:96, f:[0,0,1,2,3,4,5]}
	}
}
// Dziedziczenie
Enemy.prototype = new Character(true);
Enemy.prototype.construktor = Enemy;

