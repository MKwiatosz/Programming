Rock.count = 0;

Rock.all = 
{

}

function Rock(size,x,y)
{
	Rock.count++;
	this.id = Rock.count;
	Rock.all[this.id] = this;

	this.size = size!==undefined ? size : 2;
	this.x = x!==undefined ? x : (VAR.rand(0,1) ? VAR.rand(0,3)/10 : VAR.rand(7,10)/10)*VAR.W;
	this.y = y!==undefined ? y : (VAR.rand(0,1) ? VAR.rand(0,3)/10 : VAR.rand(7,10)/10)*VAR.W;

	this.r = 0.2;

	this.modX = 0.0005*VAR.rand(1,10)*(VAR.rand(0,1) ? 1 : -1);
	this.modY = 0.0005*VAR.rand(1,10)*(VAR.rand(0,1) ? 1 : -1);

	this.points = [];
	
	var a = 0;

	while(a<360)
	{
		a+=VAR.rand(30,45);

		this.points.push(
		{
			x:Math.sin(Math.PI/180*a)*this.r,
			y:-Math.cos(Math.PI/180*a)*this.r
		}
		);
	}
}

Rock.prototype.draw = function()
{
	Game.beginPath();

	for(var i=0; i<this.points.length; i++)
	{
		Game.ctx[i===0 ? 'moveTo' : 'lineTo'](this.points[i].x*VAR.d+this.x,this.points[i].y*VAR.d+this.y)
	}

	Game.ctx.closePtah();
	Game.ctx.stroke();
};

Rock.draw = function ()
{
	
}











