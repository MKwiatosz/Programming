# Dependencies
import tweepy
from textblob import TextBlob
import csv

# Consumer keys to twitter
consumer_key = 'hlMP7rdxx8dd3BXKdy03Gb55v'
consumer_secret = 'irTGW16aT5SWnErb6G2ETuaA85M7MIxdrLc1B181OcTv1VtrEx'

# Acces tokens to twitter
acces_token = '1011299037826469892-Ur5ZNshcmxanLUfO2xoDoobXLWyLnz'
acces_token_secret = 'PZxlecb93ztHKByhTnzKuxCt0UwfIS5KX4ksM3vDX8z6z'

# Authorization to log in into twitter
auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(acces_token,acces_token_secret)

# API instance
api = tweepy.API(auth)

# Searching "word"
public_tweets = api.search('Love')

# Definied threshold to specified tweet
def get_label(analysis, threshold=0):
    if analysis.sentiment[0] > threshold:
        return 'Positive'
    elif analysis.sentiment[0] == 0:
        return 'Neutral'
    else:
        return 'Negative'

# Make csv file
csvFile = open('tweets.csv','w')
csvWriter = csv.writer(csvFile)

# Loop which is writing tweets into csv and defining what attitude have sentence
for tweet in public_tweets:
    analysis = TextBlob(tweet.text)
    csvWriter.writerow([tweet.created_at, tweet.text.encode('utf-8'), get_label(analysis)])
    print (tweet.created_at, tweet.text)
csvFile.close()
