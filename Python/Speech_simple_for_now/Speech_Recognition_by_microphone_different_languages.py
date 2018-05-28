import speech_recognition as sr

r = sr.Recognizer()

mic = sr.Microphone()

with mic as source:
    r.adjust_for_ambient_noise(source,duration=1)
    audio = r.listen(source)

recognized_sentence = r.recognize_google(audio,language='pl-pl')

print("My words: ",recognized_sentence)
