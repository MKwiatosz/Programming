import speech_recognition as sr
r = sr.Recognizer()

harvard = sr.AudioFile('jackhammer.wav')
with harvard as source:
    r.adjust_for_ambient_noise(source,duration=0.5)
    audio = r.record(source)


recognized_sentence=r.recognize_google(audio,show_all=True)

print('Sentence: ',recognized_sentence)


