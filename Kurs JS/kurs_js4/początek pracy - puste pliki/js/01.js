
window.onload=mnozenie();

function mnozenie()
{
	document.write(0.1*5); document.write("<br/>");
	document.write(0.15*3); document.write("<br/>");
	document.write(0.1+0.2); document.write("<br/>");

	if(0.1+0.2 == 0.3) document.write("true <br/>");
	else document.write("false <br/>");


				//Sposob 1
	var x;

	x=Math.round((0.1+0.2)*10) /10;
	document.write(x+"<br/>");	

	x=Math.round((0.15*3)*100) /100;
	document.write(x+"<br/>");


				//Sposob 2

	x=0.15*3;
	x=x.toFixed(2);
	document.write(x+"<br/><br/>");

	x=1.005;

		//Sposob1
	x=Math.round(x*100)/100;
	document.write(x+"<br/>");

		//Sposob2
	x=1.005;	
	x=x.toFixed(3);
	document.write(x+"<br/>");

	
				//Sposob3

	Number.prototype.round = function(miejsc)
	{
		return + (Math.round(this+"e+"+miejsc) + "e-" + miejsc);	
	}

	x=1.005;	
	x=x.round(2);
	document.write(x+"<br/>");

				//Sposob4


					
}

