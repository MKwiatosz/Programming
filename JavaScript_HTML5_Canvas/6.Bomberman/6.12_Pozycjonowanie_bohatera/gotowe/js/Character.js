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
	// ponieważ klatka postaci jest szersza i wyższa niż pojedynczy element gry musimy to zrekompensować modyfikatorami
	this.modX = -2;
	this.modY = -9;
	//
	this.states = {};
	// 
	this.current_f = 0;
	//
	this.change_f_delay = 0;
	this.f_max_delay = 2;
}
Character.prototype.draw = function(){
	if(this.states[this.state].flip){
		Game.ctx.save();
		Game.ctx.scale(-1,1);
	}
	//
	Game.ctx.drawImage(
		Game.spr,
		this.states[this.state].sx+this.states[this.state].f[this.current_f]*this.fW,
		this.states[this.state].sy,
		this.fW,
		this.fH,
		// Pozycja wklejanego obrazka jest modyfikowana przez x i y postaci
		(this.states[this.state].flip ? (-this.fW-this.x-this.modX)*VAR.scale : (this.x+this.modX)*VAR.scale),
		(this.y+this.modY)*VAR.scale,
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
	this.state = 'down';
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
	// Dodaję pozycję x i y, ustawiam górny lewy róg planszy
	this.x = Game.board.fW;
	this.y = Game.board.fH;
}
//
Hero.prototype = new Character(true);
Hero.prototype.construktor = Hero;
//
Enemy.all = {};
function Enemy(){
	Character.call(this);
	//
	Enemy.all[this.id] = this;
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
Enemy.prototype = new Character(true);
Enemy.prototype.construktor = Enemy;


