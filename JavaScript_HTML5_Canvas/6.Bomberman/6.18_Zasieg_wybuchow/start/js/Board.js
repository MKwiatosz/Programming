Board.templates = [
	[
		'WWWWWWWWWWWWWWW',
		'W             W',
		'W X X X X X X W',
		'W             W',
		'W X X X X X X W',
		'W             W',
		'W X X X X X X W',
		'W             W',
		'W X X X X X X W',
		'W             W',
		'WWWWWWWWWWWWWWW'
	],
	[
		'WWWWWWWWWWWWWWW',
		'W             W',
		'W X X XXX X X W',
		'W             W',
		'W X X X X X X W',
		'W X   X X   X W',
		'W X X X X X X W',
		'W             W',
		'W X X XXX X X W',
		'W             W',
		'WWWWWWWWWWWWWWW'
	]
];
Board.elements = {
	'floor':{sx:174, sy:16, type:'empty'},
	'W':{sx:190, sy:16, type:'solid'},
	'X':{sx:206, sy:16, type:'solid'},
	'box':{sx:126, sy:0, type:'soft'}
};
function Board(){
	//
	this.parse(Board.templates[VAR.rand(0,Board.templates.length-1)]);
	// Dodawanie 30 skrzynek
	for(var i=0; i<30; i++){
		this.addCrate();
	}
	// 
	this.fW = 16;
	this.fH = 16;
}
Board.prototype.addCrate = function(){
	var pos = this.getEmptySpace();
	if(pos){
		this.b[pos.y][pos.x] = Board.elements.box;
	}
}
Board.prototype.getEmptySpace = function(){
	// zwraca null jeśli tablica jest pusta lub pierwszy element z tablicy (jednocześnie go usuwając)
	return this.emptySpaces.length>0 ? this.emptySpaces.shift() : null;
}
Board.prototype.draw = function() {
	// 
	for(var i=0; i<this.b.length; i++){
		// 
		for(var j=0; j<this.b[i].length; j++){
			//
			Game.ctx.drawImage(
				Game.spr,
				this.b[i][j].sx,
				this.b[i][j].sy,
				this.fW,
				this.fH,
				j*this.fW*VAR.scale,
				i*this.fH*VAR.scale,
				this.fW*VAR.scale,
				this.fH*VAR.scale
			);
			// Jeśli to pole to bomba to narysuj bombę
			if(this.b[i][j].sub_type == 'bomb'){
				this.b[i][j].draw();
			}
		}
	}
};
Board.prototype.parse = function(arr){
	this.b = [];
	// Przy okazji do tablicy emptySpaces wstawię wszystkie puste miejsca
	this.emptySpaces = [];
	//
	for(var i=0; i<arr.length; i++){
		this.b.push([]);
		for(var j=0; j<arr[i].length; j++){
			this.b[i].push(Board.elements[arr[i].charAt(j)==' ' ? 'floor' : arr[i].charAt(j)]);
			// Jeśli miejsce jest puste i nie jest to podłoga w lewym górnym rogu (wykluczam trzypozycje) wstaw nowy obiekt z pozycją x i y do tablicy z pustymi miejscami
			if(this.b[i][j].type=='empty' && !(i==1 && j==1) && !(i==2 && j==1) && !(i==1 && j==2)){
				this.emptySpaces.push({x:j, y:i});
			}
		}
	}
	// potasuj puste miejsca (zobacz definicję metody w obiekcie VAR)
	VAR.shuffle(this.emptySpaces);
}


