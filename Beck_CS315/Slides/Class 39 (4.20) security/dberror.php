<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');
?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <link rel="stylesheet" href="db.css" />
    <meta name="author" content="Jon Beck" />
    <title>Database Connection</title>
  </head>

  <body>

<?php

$db = new PDO('mysql:host=localhost;dbname=imdb;charset=utf8mb4',
              'dbuser', 'misspelledpassword',
              array(PDO::ATTR_EMULATE_PREPARES => false,
                    PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));

$year = 2000;

$query = 'select name, format(rank, 2) as frank
          from movie
          where year = :year
          order by name asc';
$statement = $db->prepare($query);
$statement->bindValue(':year', $year);
$statement->execute();
$result = $statement->fetchAll();
?>
    <h1>Movies Made in <?= $year ?></h1>
  </body>
</html>
