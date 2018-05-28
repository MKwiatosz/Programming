// Projekt planszy można przechowywać na kilka sposobów.
// Może to być tablica tablic (zagnieżdżone tablice), łańcuch znaków
// Jednak przechowywanie jej jako tablicę łańcuchów znaków bardzo ułatwia projektowanie.

Board.templates = [
	// Każdy pojedynczy wzór to tablica z jedenastoma łańcuchami znaków. Każdy łańcuch ma 15 znaków.
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
// Lista elementów z których jest budowana plansza
Board.elements = {
	// każdy obiekt ma podobne dane jak stany w postaciach
	'floor':{sx:174, sy:16, type:'empty'},
	'W':{sx:190, sy:16, type:'solid'},
	'X':{sx:206, sy:16, type:'solid'},
	'box':{sx:126, sy:0, type:'soft'}
};
function Board(){

}


