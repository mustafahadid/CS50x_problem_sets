SELECT title, rating from movies join ratings on movies.id = ratings.movie_id WHERE year =2010 ORDER by rating DESC
