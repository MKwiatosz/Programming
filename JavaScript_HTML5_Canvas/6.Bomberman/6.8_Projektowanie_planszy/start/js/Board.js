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
		'w xxx xx x x x w',
		'w   x x        w',
		'w  x x x x xx w',
		'w x           w',
		'w x x x x x x w',
		'w   x  x   x   w',
		'wwwwwwwwwwwwwww'
	],

	[
		'wwwwwwwwwwwwwww',
		'w      x   x   w',
		'w x x  x x x w',
		'w   x          w',
		'w x   x x  x w',
		'w x      x      w',
		'w  x  x x xx w',
		'w              w',
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
	],

]

Board.elements =
{
	'floor': {sx:174,sy:16,type:'empty'}
	'W'    : {sx:190,sy:16,type:'solid'}
	'X'    : {sx:206,sy:16,type:'solid'}
	'box'  : {sx:126,sy:16,type:'soft'}
}

function Board()
{
	this.fW = 16;
	this.fH = 16;

	this.b = this.parse(Board.templates[VAR.rand(0,Board.templates.length-1)])	
}

Board.prototype.parse = function(arr)
{
	var new_array = [];
	for(var i=0;i<arr.length;i++)
	{
		new_array.push([]);
		for(var j=0; j<arr[i].length; i++)
		{
			new_array[i].push(Board.elements[arr[i].charAt(j)==' ' ? 'floor' : arr[i].charAt(j)]);
		}
	}
	return new_array;
}