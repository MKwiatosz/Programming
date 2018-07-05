import tweepy
from textblob import TextBlob

consumer_key = 'hlMP7rdxx8dd3BXKdy03Gb55v'
consumer_secret = 'irTGW16aT5SWnErb6G2ETuaA85M7MIxdrLc1B181OcTv1VtrEx'

acces_token = '1011299037826469892-Ur5ZNshcmxanLUfO2xoDoobXLWyLnz'
acces_token_secret = 'PZxlecb93ztHKByhTnzKuxCt0UwfIS5KX4ksM3vDX8z6z'

auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(acces_token,acces_token_secret)

api = tweepy.API(auth)

public_tweets = api.search('Trump')

for tweet in public_tweets:
    print(tweet.text)
    analysis = TextBlob(tweet.text)
    print(analysis.sentiment)
