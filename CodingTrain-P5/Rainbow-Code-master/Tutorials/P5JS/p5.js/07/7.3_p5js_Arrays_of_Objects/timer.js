var counter =0;

function TimeIt (counter){
	if(counter>0){
		counter--;
	}else{
		console.log("Ring!Ring!Ring!")
	}
}

setInterval(TimeIt,1000);
