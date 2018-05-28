// Stała do liczenia postaci
Character.count = 0;
function Character(inheritance){
	// Rośnie ilość postaci
	Character.count++;
	// Przypisanie id
	this.id = 'char_'+Character.count;
	if (!inheritance)
	{
	// Wrzucenie aktualnie tworzonej instancji do obiektu toDraw.
	Game.toDraw[this.id] = this;
	}
	// Wielkość klatki w sprite sheet (zarówno bomberman i kurczak mają ten sam rozmiar klatki).
	this.fW = 21;
	this.fH = 24;
	// Początkowy x i y pierwszej klatki animacji w Sprite sheet
	// this.start_x = 0;
	// this.start_y = 0;
	// // Kolejność klatek
	// // Zakładamy, że klatki do jednej animacji są zawsze ustawione poziomo. Musimy tylko wiedzieć w jakiej kolejności je wyświetlać
	// // W tablicy przechowuję indeks klatek
	// this.frames = [1,0,2,0];
	// Aktualny numer klatki
	this.current_f = 0;
	// Klatki zmieniają się z opóźnieniem
	this.change_f_delay = 0;
	this.f_max_delay = 2;
}
Character.prototype.draw = function(){
	// Przypominam co należy podać do drawImage:
	// 1. obrazek z którego ma coś zostać przeniesione do canvas (czyli nasz Sprite sheet)
	// 2. pozycja x prostokąta, który będzie wycinał fragment źródłowego obrazka (pozycja klatki na Sprite sheet)
	// 3. pozycja y prostokąta, który będzie wycinał fragment źródłowego obrazka (pozycja klatki na Sprite sheet)
	// 4. szerokość prostokąta, który będzie wycinał fragment źródłowego obrazka (wielkość klatki na Sprite sheet)
	// 5. wysokość prostokąta, który będzie wycinał fragment źródłowego obrazka (pozycja klatki na Sprite sheet)
	// 6. pozycja x gdzie w canvas ma zostać wklejony obrazek
	// 7. pozycja y gdzie w canvas ma zostać wklejony obrazek
	// 8. szerokość wklejanego obrazka (nie chcę ultra małych obrazków, dlatego mnożę je przez aktualną skalę gry)
	// 9. wysokość wklejanego obrazka
	if (this.states[this.state].flip)
	{
		Game.ctx.save();
		Game.ctx.scale(-1,1);

	}

	Game.ctx.drawImage(
		Game.spr,
		this.states[this.state].sx+this.states[this.state].f[this.current_f]*this.fW,//dodajemy kolejne pozycje klatek
		this.states[this.state].sy,
		this.fW,
		this.fH,
		this.states[this.state].flip ? -this.fW*VAR.scale : 0,
		0,
		this.fW*VAR.scale,
		this.fH*VAR.scale
	);

	if (this.states[this.state].flip)
	{
		Game.ctx.restore();
	}

	if(this.change_f_delay<this.f_max_delay){
		this.change_f_delay++;
	}else{
		this.change_f_delay = 0;
		this.current_f = this.current_f+1>=this.states[this.state].f.length ? 0 : this.current_f+1;
	}
};

function Hero()
{
	Character.call(this);
	this.state = 'right_go';
	this.states = 
	{
		'down':{sx: 0, sy:0, f:[0]},
		'down_go':{sx: 0, sy:0, f:[1,0,2,0]},
		'left':{sx: 63, sy:0, f:[0]},
		'left_go':{sx: 63, sy:0, f:[1,0,2,0]},
		'up':{sx: 0, sy:24, f:[0]},
		'up_go':{sx: 0, sy:24, f:[1,0,2,0]},
		'right':{sx: 63, sy:0, f:[0],flip:true},
		'right_go':{sx: 63, sy:0, f:[1,0,2,0],flip:true},
		'ko':{sx: 0, sy:48, f:[0,1,0,1,0,1,2,3,4]}
	}
}
Hero.prototype = new Character(true);
Hero.prototype.constructor = Hero;