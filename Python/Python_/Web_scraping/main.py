'''
Dependencies
'''
from requests import get
from requests.exceptions import RequestException
from contextlib import closing
from bs4 import BeautifulSoup
from mathematicians import simple_get
import re

'''
Using SIMPLE_GET function (fun is defined in the mathematicians file) 
It's geting the HTML syntax of given site
'''
raw_html = simple_get('https://onet.pl')
print(len(raw_html))

html = BeautifulSoup(raw_html, 'html.parser')
klas = html.find("div", {'class':"boxContent"})


for i, li in enumerate(klas.select('li')):
    new = re.sub(r'[\ \n]{2,}', '', li.text)
    new = new.replace('TYLKO W ONECIE', '')
    print(i,new)
