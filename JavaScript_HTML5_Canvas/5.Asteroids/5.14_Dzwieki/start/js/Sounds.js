// Dźwięki to ciężka sprawa w HTML5. Na szczęście od jakiegoś czasu jest w JS dostępne Audio API, które pozwala na dużo więcej niż zwykły tag audio.
// Plugin howler.js nieprawdopodobnie ułatwia problem.
// Dlatego nie będziemy głębiej wchodzić w temat tylko użyjemy to co trzeba i już.
// Jeśli jednak masz ochotę poczytać coś więcej to poniżej kilka linków:
// http://goldfirestudios.com/blog/104/howler.js-Modern-Web-Audio-Javascript-Library
// https://developer.mozilla.org/en-US/docs/Web_Audio_API
// https://developer.mozilla.org/en-US/docs/Web/HTML/Element/audio
// 

Sound =
{
	active: false,
	init: function()
	{
		Sound.fx = new Howl(
		{
			urls:['audio/asteroids.'+(Modernizr.audio.m4a ? 'm4a' : 'ogg')],
			sprite: 
			{
				bum1:[0,1100],
				bum2:[1125,1000],
				laser:[2150,290],
				win:[2475,575],
				thrust:[3100,290]
			},
			onload: Sound.loaded
			});
	},
	loaded:function()
	{
		Sound.active = true;
	},
	play:function(s)
	{
		if (Sound.active)
		{
			Sound.fx.play(s);
		}
	}
};
