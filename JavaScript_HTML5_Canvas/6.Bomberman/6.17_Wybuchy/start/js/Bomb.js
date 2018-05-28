// Ile jest bomb i ile ich może być
Bomb.count = 0;
Bomb.max_count = 2;
Bomb.elements =
{
	'bomb'         : {sx:126,sy:16,f:[0,0,1,1,2,2]},
	'center'       : {sx:126,sy:64,f:[0,0,1,1,2,2,3,3,2,2,1,1,0,0]},
	'up_bum'       : {sx:126,sy:96,f:[0,0,1,1,2,2,3,3,2,2,1,1,0,0]},
	'down_bum'     : {sx:126,sy:96,f:[0,0,1,1,2,2,3,3,2,2,1,1,0,0]},
	'right_bum'    : {sx:126,sy:48,f:[0,0,1,1,2,2,3,3,2,2,1,1,0,0]},
	'left_bum'     : {sx:126,sy:48,f:[0,0,1,1,2,2,3,3,2,2,1,1,0,0]},
	'up_bum_end'   : {sx:126,sy:80,f:[0,0,1,1,2,2,3,3,2,2,1,1,0,0]},
	'down_bum_end' : {sx:126,sy:48,f:[0,0,1,1,2,2,3,3,2,2,1,1,0,0],flip:true},
	'left_bum_end' : {sx:126,sy:32,f:[0,0,1,1,2,2,3,3,2,2,1,1,0,0]},
	'right_bum_end': {sx:126,sy:32,f:[0,0,1,1,2,2,3,3,2,2,1,1,0,0],flip:true},
}
function Bomb(column,row,bum_type){
	if((Bomb.max_count>Bomb.count && Game.board.b[row][column].sub_type!='bomb') || bum_type){
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
		this.data = !bum_type ? Bomb.elements.bomb : Bomb.elements[bum_type];
		// W której kolumnie i rzędzie
		this.column = column;
		this.row = row;
		//
		this.timer = 30;
		//
		this.range = 2;
		// Podmień obiekt w planszy
		Game.board.b[this.row][this.column] = this;
	}
}
Bomb.prototype.draw = function() {
	if (this.timer>0)
	{
		this.target_x = this.column*Game.board.fW*VAR.scale;
		this.target_y = this.row*Game.board.fH*VAR.scale;

		if (this.data.flip)
		{
			Game.ctx.save();
			if (this.bum_type=='down_bum_end')
			{
				Game.ctx.scale(1,-1);
				this.target_y = this.target_y*-1-(Game.board.fH*VAR.scale);
			}
			else
			{
				Game.ctx.scale(-1,1);
				this.target_x = this.target_x*-1-(Game.board.fW*VAR.scale)	
			}
		}

		Game.ctx.drawImage(
			Game.spr,
			this.data.sx+this.data.f[this.current_f]*Game.board.fW,
			this.data.sy,
			Game.board.fW,
			Game.board.fH,
			this.target_x,
			this.target_y,
			Game.board.fW*VAR.scale,
			Game.board.fH*VAR.scale
		);
		this.current_f = this.current_f+1>=this.data.f.length ? 0 : this.current_f+1;
		this.timer--;
	}
	else if (this.type == 'solid')
	{
		Bomb.count--;
		this.type = 'empty';
		this.current_f = 0;
		this.data = Bomb.elements.center;
		this.timer = this.data.f.length;
	}
	else
	{
		Game.board.b[this.row][this.column] = Board.elements.floor;
	}
};