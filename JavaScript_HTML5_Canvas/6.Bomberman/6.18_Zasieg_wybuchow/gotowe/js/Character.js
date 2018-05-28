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
	this.speed = 2;
	//
	this.fW = 21;
	this.fH = 24;
	//
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
	//
	if(this.state.slice(-2)=='go'){
		//
		if(this.state=='down_go'){
			this.y+=this.speed;
		}else if(this.state=='up_go'){
			this.y-=this.speed;
		}else if(this.state=='left_go'){
			this.x-=this.speed;
		}else if(this.state=='right_go'){
			this.x+=this.speed;
		}
		this.rowAndColumn();
	}
	//
	// rysuje pomocniczy kwadrat pod postacią (żebyśmy wiedzieli na którym polu stoi)
	// Game.ctx.fillStyle = 'rgba(255,0,0,0.3)'
	// Game.ctx.fillRect(this.column*Game.board.fW*VAR.scale, this.row*Game.board.fH*VAR.scale, Game.board.fW*VAR.scale, Game.board.fW*VAR.scale);
	// Game.ctx.fillRect(this.next_column*Game.board.fW*VAR.scale, this.next_row*Game.board.fH*VAR.scale, Game.board.fW*VAR.scale, Game.board.fW*VAR.scale);
	//
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
//
Character.prototype.rowAndColumn = function() {
	this.column = Math.round(this.x/Game.board.fW);
	this.row = Math.round(this.y/Game.board.fH);
	//
	if(this.state.slice(-3)=='_go'){
		if(this.state=='left_go' || this.state=='right_go'){
			this.next_column = this.state=='left_go' ? Math.floor(this.x/Game.board.fW) : Math.ceil(this.x/Game.board.fW);
			this.next_row = this.row;
		}else{
			this.next_row = this.state=='up_go' ? Math.floor(this.y/Game.board.fW) : Math.ceil(this.y/Game.board.fW);
			this.next_column = this.column;
		}
		//
		if(!(this.next_row==this.row && this.next_column==this.column) && Game.board.b[this.next_row][this.next_column].type!='empty'){
			this.state = this.state.slice(0,-3);
			this.current_f = 0;
			//
			if(this.next_row!=this.row){
				this.y = this.row*Game.board.fH;
			}else{
				this.x = this.column*Game.board.fW;
			}
		}else{
			if(this.next_row!=this.row){
				this.x = this.next_column*Game.board.fW;
			}else if(this.next_column!=this.column){
				this.y = this.next_row*Game.board.fH;
			}
		}
	}else{
		this.next_column = this.column;
		this.next_row = this.row;
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
	//
	this.x = Game.board.fW;
	this.y = Game.board.fH;
	//
	this.rowAndColumn();
	//
}
//
Hero.prototype = new Character(true);
Hero.prototype.construktor = Hero;
//
Hero.prototype.updateState = function(){
	// 
	if(Game.key_37){
		this.tmpstate = 'left_go';
	}else if(Game.key_38){
		this.tmpstate = 'up_go';
	}else if(Game.key_39){
		this.tmpstate = 'right_go';
	}else if(Game.key_40){
		this.tmpstate = 'down_go';
	}else if(this.state.slice(-2)=='go'){
		this.tmpstate = this.state.slice(0, this.state.indexOf('_go') );
	}
	if(this.tmpstate!=this.state){
		this.current_f = 0;
		this.state = this.tmpstate;
	}
}
//
//
Enemy.all = {};
// Musimy dodać możliwość podawania pozycji dodawanych potworów
function Enemy(x,y){
	Character.call(this);
	//
	Enemy.all[this.id] = this;
	this.state = 'down';
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
	// Przypisanie x i y oraz obliczenie kolumny i rzędu
	this.x = x;
	this.y = y;
	this.rowAndColumn();
	this.setDirection();
}
Enemy.prototype = new Character(true);
Enemy.prototype.construktor = Enemy;
// Aby rozszerzać metody stworzymy właściwość parent, która będzie wskazywała na metody obiektu, z którego dziedziczy Enemy
Enemy.prototype.parent = Character.prototype;
// W którą stronę ma teraz iść wróg.
// Funkcja odpali się na samym początku gry oraz za każdym razem, gdy wróg dojdzie do przeszkody
Enemy.prototype.setDirection = function(){
	// Należy sprawdzić 4 możliwości
	// Nowa tablica przechowuje pola, na które można wejść.
	// Jeśli jest stworzona wykorzystaj starą.
	this.canGo = this.canGo || [];
	this.canGo.length = 0;
	// Sprawdź sąsiadujące pole
	// 
	// Ta pętla przejdzie przez wszystkie 9 pól naokoło wroga
	for(var i=this.column-1; i<=this.column+1; i++){
		//
		for(var j=this.row-1; j<=this.row+1; j++){
			//
			if(!(i==this.column && j==this.row)){// Wyklucza pole, na którym stoi postać
				if(i==this.column || j==this.row){
					
					// jeśli pole jest puste dodaj jego pozycję do canGo
					if(Game.board.b[j][i].type=='empty'){
						this.canGo.push({x:i, y:j});
					}
				}
			}
		}
	}
	if(this.canGo.length>0){// jeśli są puste pola wylosuj jedno i ustaw odpowiedni stan
		this.tmp_pos = this.canGo[VAR.rand(0,this.canGo.length-1)];
		if(this.column<this.tmp_pos.x){
			this.state = 'right_go';
		}else if(this.column>this.tmp_pos.x){
			this.state = 'left_go';
		}else if(this.row<this.tmp_pos.y){
			this.state = 'down_go';
		}else if(this.row>this.tmp_pos.y){
			this.state = 'up_go';
		}
	}else if(this.state.slice(-2)=='go'){// jeśli nie ma gdzie iść, trzeba stać (jeśli jeszcze nie stoi)
		this.state = this.state.slice(0, this.state.indexOf('_go') );
	}
}
// Musimy rozszerzyć metodę rowAndColumn. Za każdym razem jak wróg zatrzyma się na ścianie zostanie wylosowany nowy kierunek. 
Enemy.prototype.rowAndColumn = function(){
	// Włąściwość „parent” przechowuje metody obiektu Character
	// Mogę wywołać nie zmienioną metodę Character i coś do niej dodać
	//
	// Najpierw zapiszę aktualny stan postaci
	this.prev_state = this.state;
	// Wywołuję niezmienioną metodę
	this.parent.rowAndColumn.call(this);
	// Jeśli stan się zmienił i nowy stan nie ma słowa go (a poprzedni miał), to trzeba wybrać nowy kierunek.
	if(this.prev_state!=this.state && this.state.slice(-2)!='go' && this.prev_state.slice(-2)=='go'){
		this.setDirection();
	}

}

