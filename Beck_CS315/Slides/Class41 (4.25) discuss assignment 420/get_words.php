<?php

/**
 * Jon Beck
 * select words that match search criteria from the db
 */

error_reporting(E_ALL);
$regex = '/^[a-z]+$/';

$return = [];

if (isset($_GET) && isset($_GET['prefix']) &&
    preg_match($regex, $_GET['prefix']))
{
  require('dblogin.php');
  $db = new PDO("mysql:host=$db_host;dbname=jbeck;charset=utf8mb4",
                $db_user, $db_pass,
                array(PDO::ATTR_EMULATE_PREPARES => false,
                      PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));

  $query = $db->prepare('select w.id, w.word, p.part, w.definition
                         from word as w
                         join part as p on w.part_id = p.id
                         where w.word regexp :prefix
                         order by word, part');
  $query->bindValue(':prefix', '^' . $_GET['prefix'] . '.*');
  $query->execute();
  $result = $query->fetchAll(PDO::FETCH_ASSOC);
  foreach ($result as $row)
  {
    $return[] = [$row['id'], $row['word'], $row['part'],
                 htmlentities($row['definition'])];
  }
}
?>
<?= json_encode($return) . PHP_EOL ?>
