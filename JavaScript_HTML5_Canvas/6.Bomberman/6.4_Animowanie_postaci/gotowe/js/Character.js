// Stała do liczenia postaci
Character.count = 0;
function Character(){
	// Rośnie ilość postaci
	Character.count++;
	// Przypisanie id
	this.id = 'char_'+Character.count;
	// Wrzucenie aktualnie tworzonej instancji do obiektu toDraw.
	Game.toDraw[this.id] = this;
	// Wielkość klatki w sprite sheet (zarówno bomberman i kurczak mają ten sam rozmiar klatki).
	this.fW = 21;
	this.fH = 24;
	// Początkowy x i y pierwszej klatki animacji w Sprite sheet
	this.start_fx = 0;
	this.start_fy = 0;
	// Kolejność klatek
	// Zakładamy, że klatki do jednej animacji są zawsze ustawione poziomo. Musimy tylko wiedzieć w jakiej kolejności je wyświetlać
	// W tablicy przechowuję indeks klatek
	this.frames = [1,0,2,0];
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
	Game.ctx.drawImage(
		Game.spr,
		this.start_fx+this.frames[this.current_f]*this.fW,//dodajemy kolejne pozycje klatek
		this.start_fy,
		this.fW,
		this.fH,
		0,
		0,
		this.fW*VAR.scale,
		this.fH*VAR.scale
	);
	// Nie zawsze przechodzimy do następnej klatki animacji
	if(this.change_f_delay<this.f_max_delay){
		this.change_f_delay++;
	}else{
		this.change_f_delay = 0;
		this.current_f = this.current_f+1>=this.frames.length ? 0 : this.current_f+1;
	}
};
