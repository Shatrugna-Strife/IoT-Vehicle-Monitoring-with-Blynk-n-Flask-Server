from flask import Flask,render_template,url_for,request,redirect, make_response
# from urllib2 import Request, urlopen
import requests
import random
import json
from time import time
from random import random
from flask import Flask, render_template, make_response
app = Flask(__name__)


@app.route('/', methods=["GET", "POST"])
def main():
    return render_template('index.html')


@app.route('/data', methods=["GET", "POST"])
def data():
    
    responsetemp = requests.get("http://blynk-cloud.com/W31w5bm8hS5NdwOUlTfa_In0DcHlW0jI/get/V5")
    responseacc = requests.get("http://blynk-cloud.com/W31w5bm8hS5NdwOUlTfa_In0DcHlW0jI/get/V1")
    temp = float(responsetemp.json()[0])
    # print(temp)
    acc = float(responseacc.json()[0])
    data = [time() * 1000, temp, acc]
    # print(data)

    response = make_response(json.dumps(data))

    response.content_type = 'application/json'

    return response


if __name__ == "__main__":
    app.run(debug=True, host = '0.0.0.0')
    #app.run(debug = True)