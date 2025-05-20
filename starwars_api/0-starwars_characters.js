#!/usr/bin/node

const request = require('request');
const movieId = process.argv[2];

if (!movieId) {
  console.log('Usage: ./0-starwars_characters.js <Movie_ID>');
  process.exit(1);
}

const apiUrl = `https://swapi-api.alx-tools.com/api/films/${movieId}`;

request(apiUrl, (error, response, body) => {
  if (error) return console.error(error);

  const film = JSON.parse(body);
  const characters = film.characters;

  const printCharacter = (index) => {
    if (index === characters.length) return;

    request(characters[index], (err, res, charBody) => {
      if (err) return console.error(err);

      const character = JSON.parse(charBody);
      console.log(character.name);
      printCharacter(index + 1);
    });
  };

  printCharacter(0);
});
