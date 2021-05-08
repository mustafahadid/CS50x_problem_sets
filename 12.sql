SELECT title from people JOIN
stars on people.id = stars.person_id
JOIN movies on stars.movie_id = movies.id  JOIN
ratings on movies.id= ratings.movie_id WHERE name = 'Johnny Depp' Or name like '%Helena Bonham%'  GROUP by title HAVING COUNT (*) > 1