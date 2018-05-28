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
	// Dodaję prędkość w pikselach na klatkę z jaką poruszają się wszystkie postaci
	this.speed = 2;
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

Character.prototype.rowAndColumn = function ()
{
	this.row = Math.round((this.y/Game.board.fH))
	this.column = Math.round(this.x/Game.board.fW)
	if (this.state.slice(-2)=='go')
	{
		if (this.state=='left_go' || this.state == 'right_go')
		{
			this.next_row = this.row;
			this.next_column = this.state=='left_go' ? Math.floor(this.x/Game.board.fW) :  Math.ceil(this.x/Game.board.fW)
		}
		else 
		{
			this.next_column = this.column;
			this.next_row = this.state=='up_go' ? Math.floor(this.y/Game.board.fH) :  Math.ceil(this.y/Game.board.fH)
		}
				if(!(this.next_row==this.row && this.next_column==this.column) && Game.board.b[this.next_row][this.next_column].type!='empty'){
			// Jeśli nie
			this.state = this.state.slice(0,-3);// Ustaw nowy stan usuwając „go”
			this.current_f = 0;// Ustaw pierwszą klatkę animacji
			// Ustaw postać na kwadracie, z którego wchodziła na nowe pole
			if(this.next_row!=this.row){
				this.y = this.row*Game.board.fH;
			}else{
				this.x = this.column*Game.board.fW;
			}
		}else{// jeśli może skoryguj pozycję tak aby postać była wyśrodkowana wewnątrz rzędu lub columny (w zależności czy idzie do góry czy w dół)
			if(this.next_row!=this.row){
				this.x = this.next_column*Game.board.fW;
			}else if(this.next_column!=this.column){
				this.y = this.next_row*Game.board.fH;
			}
		}
	}else{// jeśli postać stoi w miejscu jego następne pole jest takie jak aktualne
		this.next_column = this.column;
		this.next_row = this.row;
	}
};

Character.prototype.draw = function(){
	// jeśli ostatnie dwie litery nazwy stanu to słow go, to znaczy, że postać się przemieszcza
	if(this.state.slice(-3)=='_go'){
		// Kierunek jest zawarty w nazwie stanu
		if(this.state=='down_go'){
			this.y+=this.speed
		}else if(this.state=='up_go'){
			this.y-=this.speed
		}else if(this.state=='left_go'){
			this.x-=this.speed
		}else if(this.state=='right_go'){
			this.x+=this.speed
		}
			this.rowAndColumn();
	}	


		Game.ctx.fillRect(
		this.next_column*Game.board.fW*VAR.scale, 
		this.next_row*Game.board.fH*VAR.scale,
		Game.board.fW*VAR.scale,
		Game.board.fH*VAR.scale
		)

	Game.ctx.fillRect(
		this.column*Game.board.fW*VAR.scale, 
		this.row*Game.board.fH*VAR.scale,
		Game.board.fW*VAR.scale,
		Game.board.fH*VAR.scale
		)

	//
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
Hero.prototype.updateState = function(){
	this.tmpstate = this.state;
	// Jaki będzie stan przy aktualnie wciśniętych guzikach
	if(Game.key_37){
		this.tmpstate = 'left_go';// Używam tmpstate, żeby na końcu sprawdzić czy stan się zmienił
	}else if(Game.key_38){
		this.tmpstate = 'up_go';
	}else if(Game.key_39){
		this.tmpstate = 'right_go';
	}else if(Game.key_40){
		this.tmpstate = 'down_go';
	}else if(this.state.slice(-2)=='go'){// jeśli nic nie jest wciśnięte, ale aktualny stan ma końcówkę „go” ustaw stan bez „go”
		this.tmpstate = this.state.slice(0, this.state.indexOf('_go') );
	}
	// Jeśli stan się zmienił przypisz nowy styl i ustaw pierwszą klatkę jako bieżącą klatkę animacji
	if(this.tmpstate!=this.state){
		this.current_f = 0;
		this.state = this.tmpstate;
	}
}
//
//
Enemy.all = {};
function Enemy(){
	Character.call(this);
	//
	Enemy.all[this.id] = this;
	this.state = 'down_go';
	this.states = {
		'down':{sx:0, sy:72, f:[0]},
		'down_go':{sx:0, sy:72, f:[0,1,0,2]},
		'up':{sx:63, sy:72, f:[0]},
		'up_go':{sx:63, sy:72, f:[0,1,0,2]},
		'left':{sx:63, sy:24, f:[0]},
		'left_go':{sx:63, sy:24, f:[0,1,0,2]},
		'right':{sx:63, sy:24, f:[0], flip:true},
		'right_go':{sx:63, sy:24, f:[0,1,0,2], flip:true},
		'ko':{sx:0, sy:96, f:[0,0,1,2,3,4,5]}
	}
}
Enemy.prototype = new Character(true);
Enemy.prototype.construktor = Enemy;


