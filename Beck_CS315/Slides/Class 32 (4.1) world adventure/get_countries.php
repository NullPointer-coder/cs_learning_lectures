<?php
error_reporting(E_ALL);

if (!isset($_POST['cont']) ||
    !preg_match('/^[A-Za-z ]+$/', $_POST['cont']) ||
    !isset($_POST['lang']))
{
  exit();
}

require('dblogin.php');

$db = new PDO("mysql:host=$db_host;dbname=world;charset=utf8mb4",
              $db_user, $db_pass,
              array(PDO::ATTR_EMULATE_PREPARES => false,
                    PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));

$unsafe_lang_ids = json_decode($_POST['lang']);

$safe_lang_ids = [];

foreach ($unsafe_lang_ids as $id)
{
  if (preg_match('/^[0-9]+$/', $id))
  {
    $safe_lang_ids[] = $id;
  }
}

if (count($safe_lang_ids) == 0)
{
  exit();
}

$countrylist = [];

$query = 'select c.name
          from country as c
          join country_language as cl on c.code = cl.country_code
          where c.continent = :continent and
                cl.language_id = :lang and
                cl.official = 1';

$statement = $db->prepare($query);
$statement->bindValue(':continent', $_POST['cont']);

foreach ($safe_lang_ids as $id)
{
  $statement->bindValue(':lang', $id);
  $statement->execute();
  $result = $statement->fetchAll();
  foreach ($result as $row)
  {
    $countrylist[$row[0]] = 1;
  }
}

$countrylist = array_keys($countrylist);
sort($countrylist);
?>
<?= json_encode($countrylist); ?>
