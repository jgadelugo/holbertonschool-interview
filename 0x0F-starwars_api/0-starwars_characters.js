#!/usr/bin/node

const request = require('request');
const argv = process.argv;
const url = 'https://swapi-api.hbtn.io/api/films/' + argv[2];

function getJson (theUrl) {
  const options = {
    url: theUrl,
    method: 'GET',
    headers: {
      Accept: 'application/json',
      'Accept-Charset': 'utf-8'
    }
  };
  request(options, async function (err, res, body) {
    if (err) {
      console.log(err);
    } else {
      const json = JSON.parse(body);
      // const status = res.statusCode;
      // console.log(json);
      const characters = json.characters;
      for (const char of characters) {
        await new Promise((resolve, reject) => {
          request(char, function (err, func, bod) {
            if (err) return console.error(err);
            console.log(JSON.parse(bod).name);
            resolve();
          });
        });
      }
      return json;
    }
  });
}
getJson(url);
