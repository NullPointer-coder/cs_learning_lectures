<?php

error_reporting(E_ALL);

require('dblogin.php');
$db = new PDO("mysql:host=$db_host;dbname=world;charset=utf8mb4",
              $db_user, $db_pass,
              array(PDO::ATTR_EMULATE_PREPARES => false,
                    PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));

$statement = $db->prepare('select distinct continent
                           from country
                           order by continent');

$statement->execute();
$continents = $statement->fetchAll();

$result = [];

foreach ($continents as $row)
{
  $result[] = $row['continent'];
}
?>
<?= json_encode($result); ?>
