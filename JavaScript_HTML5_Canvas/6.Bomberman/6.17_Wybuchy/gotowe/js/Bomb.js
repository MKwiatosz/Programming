Bomb.count = 0;
Bomb.max_count = 2;
Bomb.elements = {
	'bomb':      {sx:126, sy:16, f:[0,0,1,1,2,2]},
	'center_bum':{sx:126, sy:64, f:[0,0,1,1,2,2,3,3,2,2,1,1,0,0]},
	'up_bum':    {sx:126, sy:96, f:[0,0,1,1,2,2,3,3,2,2,1,1,0,0]},
	'down_bum':    {sx:126, sy:96, f:[0,0,1,1,2,2,3,3,2,2,1,1,0,0]},
	'left_bum':  {sx:126, sy:48, f:[0,0,1,1,2,2,3,3,2,2,1,1,0,0]},
	'right_bum':  {sx:126, sy:48, f:[0,0,1,1,2,2,3,3,2,2,1,1,0,0]},
	'up_bum_end':    {sx:126, sy:80, f:[0,0,1,1,2,2,3,3,2,2,1,1,0,0]},
	'down_bum_end':    {sx:126, sy:80, f:[0,0,1,1,2,2,3,3,2,2,1,1,0,0], flip:true},
	'left_bum_end':  {sx:126, sy:32, f:[0,0,1,1,2,2,3,3,2,2,1,1,0,0]},
	'right_bum_end':  {sx:126, sy:32, f:[0,0,1,1,2,2,3,3,2,2,1,1,0,0], flip:true}
};
function Bomb(column,row, bum_type){// Trzeba dodać możliwość definiowania sub type
	if((Bomb.max_count>Bomb.count && Game.board.b[row][column].sub_type!='bomb') || bum_type){
		if(!bum_type){
			Bomb.count++;
		}
		//
		this.sx = Board.elements.floor.sx;
		this.sy = Board.elements.floor.sy;
		//

		// Przeniesione do tablicy ze wszystkimi elementami
		// this.bomb_sx = 126;
		// this.bomb_sy = 16;
		// this.f = [0,0,1,1,2,2];
		//
		this.current_f = 0;
		//
		this.type = bum_type ? 'empty' : 'solid';
		this.sub_type = 'bomb';
		this.data = Bomb.elements[bum_type || this.sub_type];
		// 

		//
		this.column = column;
		this.row = row;
		//
		// jaki jest zasięg bomby (ile pól pokryje wybuch)
		this.range = 2;
		// ile klatek do wybuchu (jeśli podany został typ policz ilość klatek danego typu)
		this.timer = 30;

		//
		Game.board.b[this.row][this.column] = this;
	}
}
Bomb.prototype.draw = function() {
	// jeśli timer jest większy niż zero rysuj bombę (lub wybuch)
	if(this.timer>0){
		// Ustalam z góry gdzie wklejona będzie dana bomba
		this.target_x = this.column*Game.board.fW*VAR.scale;
		this.target_y = this.row*Game.board.fH*VAR.scale;
		// Jeśli trzeba odbić wybuch lustrzanie
		if(this.data.flip){
			// Zapisz aktualne ustawienia contextu 2D
			Game.ctx.save();
			// Inne odbicie lustrzane dla końcówki wybuchu w dół i w górę
			// Z uwzględnieniem modyfikacj przesunięcia
			if(this.bum_type=='down_bum_end'){
				Game.ctx.scale(1,-1);
				this.target_y = this.target_y*-1-(Game.board.fH*VAR.scale);
			}else{
				Game.ctx.scale(-1,1);
				this.target_x = this.target_x*-1-(Game.board.fW*VAR.scale);
			}
		}
		Game.ctx.drawImage(
			Game.spr,
			this.data.sx+this.data.f[this.current_f]*Game.board.fW,
			this.data.sy,
			Game.board.fW,
			Game.board.fH,
			this.target_x,// wstawione już obliczone wartości
			this.target_y,// wstawione już obliczone wartości
			Game.board.fW*VAR.scale,
			Game.board.fH*VAR.scale
		);
		if(this.data.flip){
			Game.ctx.restore();
		}
		this.current_f = this.current_f+1>=this.data.f.length ? 0 : this.current_f+1;
		this.timer--;
	}else if(this.type=='solid'){// jeśli timer jest równy zero i typ obiektu równa się 'solid' (czyli jest bombą)
		// Zmniejsz aktualną ilość bomb
		if(!this.bum_type){
			Bomb.count--
		}
		this.type = 'empty';// zmień typ na pusty
		this.data = Bomb.elements['center_bum'];// przypisz dane środkowego wybuchu
		this.current_f = 0;// ustaw klatkę na zero
		this.timer = this.data.f.length;//zwiększ timer o ilość klatek w animacji wybuchu
	}else{// Jeśli skończył się animować wybuch wyłącz bombę
		Game.board.b[this.row][this.column] = Board.elements.floor;
		
	}
};