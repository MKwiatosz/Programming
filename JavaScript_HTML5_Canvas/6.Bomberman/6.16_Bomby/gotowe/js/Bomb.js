// Ile jest bomb i ile ich może być
Bomb.count = 0;
Bomb.max_count = 2;
function Bomb(column,row){
	if(Bomb.max_count>Bomb.count && Game.board.b[row][column].sub_type!='bomb'){
		Bomb.count++;
		//
		// pozycja pierwszej klatki podłogi (najpierw będzie wysowana podłoga)
		this.sx = Board.elements.floor.sx;
		this.sy = Board.elements.floor.sy;
		// pozycja pierwszej klatki bomby
		this.bomb_sx = 126;
		this.bomb_sy = 16;
		// klatki animacji
		this.f = [0,0,1,1,2,2];
		this.current_f = 0;
		// typ (tak jak inne elementy na planszy)
		this.type = 'solid';
		this.sub_type = 'bomb';
		// W której kolumnie i rzędzie
		this.column = column;
		this.row = row;
		// Podmień obiekt w planszy
		Game.board.b[this.row][this.column] = this;
	}
}
Bomb.prototype.draw = function() {
	Game.ctx.drawImage(
		Game.spr,
		this.bomb_sx+this.f[this.current_f]*Game.board.fW,
		this.bomb_sy,
		Game.board.fW,
		Game.board.fH,
		this.column*Game.board.fW*VAR.scale,
		this.row*Game.board.fH*VAR.scale,
		Game.board.fW*VAR.scale,
		Game.board.fH*VAR.scale
	);
	this.current_f = this.current_f+1>=this.f.length ? 0 : this.current_f+1;
};