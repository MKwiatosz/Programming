Board.templates = 
[
	
	[
		'wwwwwwwwwwwwwww',
		'w             w',
		'w x x x x x x w',
		'w             w',
		'w x x x x x x w',
		'w             w',
		'w x x x x x x w',
		'w             w',
		'w x x x x x x w',
		'w             w',
		'wwwwwwwwwwwwwww'
	],
	[
		'wwwwwwwwwwwwwww',
		'w         x   w',
		'w x x x x x x w',
		'w   x         w',
		'w x x x x x x w',
		'w       x     w',
		'wxx x x x xxx w',
		'w x           w',
		'w x x x x x x w',
		'w   x     x   w',
		'wwwwwwwwwwwwwww'
	],
	[
		'wwwwwwwwwwwwwww',
		'w    x    x   w',
		'w x x xxx x x w',
		'w             w',
		'w xxx xx x x  w',
		'w   x x       w',
		'w  x x x x  xxw',
		'w x           w',
		'w x x x x x x w',
		'w   x  x   x  w',
		'wwwwwwwwwwwwwww'
	],

	[
		'wwwwwwwwwwwwwww',
		'w      x   x  w',
		'w x x  x x x  w',
		'w   x         w',
		'w x   x x  x  w',
		'w x      x    w',
		'w  x  x x xx  w',
		'w             w',
		'w x  x xxx x  w',
		'w   x    x    w',
		'wwwwwwwwwwwwwww'
	],

	[
		'wwwwwwwwwwwwwww',
		'w         x   w',
		'w x  x x x  x w',
		'w   x         w',
		'w x  x x x xx w',
		'w       x     w',
		'wxx xx x xxx  w',
		'w x           w',
		'w x x x  x x  w',
		'w   x     x   w',
		'wwwwwwwwwwwwwww'
	],

	[
		'wwwwwwwwwwwwwww',
		'w             w',
		'w x x x   x x w',
		'w   x         w',
		'w x x x x x x w',
		'w       x     w',
		'wxxxx x x xxx w',
		'w x           w',
		'w   x x x   x w',
		'w         x   w',
		'wwwwwwwwwwwwwww'
	]

];

Board.elements = {
	// każdy obiekt ma podobne dane jak stany w postaciach
	'floor':{sx:174, sy:16, type:'empty'},
	'w'    :{sx:190, sy:16, type:'solid'},
	'x'    :{sx:206, sy:16, type:'solid'},
	'box'  :{sx:126, sy:0, type:'soft'}
};
function Board(){
	// Zamieniam łańcuchy znaków na tablice obiektów
	this.b = this.parse(Board.templates[VAR.rand(0,Board.templates.length-1)]);
	// wielkość elementów
	this.fW = 16;
	this.fH = 16;
}

Board.prototype.draw = function() {
	// Rysujemy po kolei każdy rząd (czyli każdy łańcuch znaków w tablicy z wzorem planszy)
	for(var i=0; i<this.b.length; i++){
		// druga pętla sprawdza każdy znak aktualnego łańcucha znaków
		for(var j=0; j<this.b[i].length; j++){
			// Rysowanie obrazka
			Game.ctx.drawImage(
				Game.spr,
				this.b[i][j].sx,// Dostaję się do elementu w zagnieżdżonej tablicy
				this.b[i][j].sy,// Dostaję się do elementu w zagnieżdżonej tablicy
				this.fW,
				this.fH,
				j*this.fW*VAR.scale,// Znaki w łańcuchach znaków rysują rzędy, więc j to pozycja elementu w poziomie. Mnożę ją przez szerokość elementu i skalę gry
				i*this.fH*VAR.scale,// To samo dla y, tylko w pionie liczy się „i” bo to indeks całego rzędu (łańcucha znaków).
				this.fW*VAR.scale,//szerokość wklejanego elementu
				this.fH*VAR.scale// wysokość wklejanego elementu
			);
		}
	}
};

Board.prototype.parse = function(arr){
	var new_arr = [];
	for(var i=0; i<arr.length; i++){
		// dodaję nową tablicę, która reprezentuje nowy rząd
		new_arr.push([]);
		// druga pętla sprawdza każdy znak aktualnego łańcucha znaków
		for(var j=0; j<arr[i].length; j++){
			// Zamiast łańcucha znaków przechowuję obiekty z informacją o danym polu
			new_arr[i].push(Board.elements[arr[i].charAt(j)==' ' ? 'floor' : arr[i].charAt(j)]);
		}
	}
	return new_arr;
}



