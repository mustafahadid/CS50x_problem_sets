SELECT name FROM people WHERE people.id
IN
( SELECT person_id FROM stars JOIN movies ON movies.id = stars.movie_id
WHERE movie_id IN
( SELECT movie_id FROM movies JOIN stars ON stars.movie_id = movies.id JOIN people ON
 people.id = stars.person_id WHERE people.id IN (
SELECT id FROM people WHERE people.name = "Kevin Bacon" AND people.birth = 1958 )))
EXCEPT
SELECT name FROM people WHERE people.name = "Kevin Bacon" AND people.birth = 1958