<?php
error_reporting(E_ALL);

if (!isset( $_GET['cont']) || !preg_match('/^[A-Za-z ]+$/', $_GET['cont']))
{
  exit();
}

require('dblogin.php');

$db = new PDO("mysql:host=$db_host;dbname=world;charset=utf8mb4",
              $db_user, $db_pass,
              array(PDO::ATTR_EMULATE_PREPARES => false,
                    PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));

$statement = $db->prepare
  ('select distinct lang.id, lang.name
    from language as lang join country_language as cl on lang.id = cl.language_id
    join country as c on c.code = cl.country_code
    where c.continent = :continent and cl.official = 1
    order by lang.name');

$statement->bindValue(':continent', $_GET['cont']);
$statement->execute();
$languages = $statement->fetchAll();

$return = [];
foreach ($languages as $row)
{
  $return[] = array($row['id'], $row['name']);
}
?>
<?= json_encode($return); ?>
