window.onload = plackolego();

function plackolego()
{
	var pln = 1000;
	document.write("Wpłata: " +pln+" PLN <br/><br/>");

	//Przewalutowanie
	var usd=pln/4.00835701

	document.write("Saldo: " +usd+" USD <br/>");

		usd=Math.floor(usd*100)/100;
	document.write("Saldo: " +usd+" USD <br/><br/>");

	//Zakupy

	var zakupy= 23.99;
	document.write("Zakupy: " + zakupy+" USD <br/>");

	var prowizja= 0.02*zakupy;
	document.write("Prowizja: "+prowizja+" USD <br/>");

	prowizja=Math.ceil(prowizja*100)/100;
	document.write("Prowizja: "+prowizja+" USD <br/>");

	//Po zakupach

	usd=usd-zakupy-prowizja;
	document.write("Saldo: "+usd+" USD <br/><br/>");


	usd=225.99;
	usd=Math.trunc(usd);
	document.write("Saldo: "+usd+" USD <br/>");




}