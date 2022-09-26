<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');
session_start();

if (isset($_SESSION['username'])) : ?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <link rel="stylesheet" href="session.css" />
    <title>Auth Demo</title>
  </head>

  <body>
    <header>
      <h1>
        ACME Website
      </h1>
    </header>

    <section>
      <p>
        You are already logged in as <?= $_SESSION['displayname'] ?>
      </p>

      <p>
        <a href="home.php"><button type="button">OK</button></a>
      </p>
    </section>
  </body>
</html>
<?php
exit;
endif;

require('dblogin.php');
$db = new PDO("mysql:host=$db_host;dbname=jbeck;charset=utf8mb4",
              $db_user, $db_pass,
              array(PDO::ATTR_EMULATE_PREPARES => false,
                    PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));

$error_msg = '';

if (isset($_POST['submit']))
{
  if (isset($_POST['username']) &&
      preg_match('|^\w+$|', $_POST['username']) &&
      isset($_POST['password']) &&
      preg_match('|^\S+$|', $_POST['password']) &&
      isset($_POST['displayname']) &&
      preg_match('|^[A-Za-z0-9 ]+$|', $_POST['displayname']))
  {
    $sql = 'select username from user where username = :username';
    $statement = $db->prepare($sql);
    $statement->bindValue(':username', $_POST['username']);
    $statement->execute();
    $result = $statement->fetchAll(PDO::FETCH_ASSOC);

    if (count($result) > 0)
    {
      $error_msg = 'That username is already in use';
    }
    else
    {
      $sql = 'insert into user (username, password, displayname)
              values (:username, :password, :displayname)';
      $statement = $db->prepare($sql);
      $statement->bindValue(':username', $_POST['username']);
      $statement->bindValue(
        ':password',
        password_hash($_POST['password'], PASSWORD_DEFAULT));
      $statement->bindValue(':displayname', $_POST['displayname']);
      $statement->execute();
      $_SESSION['username'] = $_POST['username'];
      $_SESSION['displayname'] = $_POST['displayname'];
    }
  }
}

if (!isset($_SESSION['username'])): ?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8" />
    <link rel="stylesheet" href="session.css" />
    <title>Session Demo</title>
  </head>

  <body>
    <header>
      <h1>
        ACME Website
      </h1>
    </header>

    <section>
      <?php if ($error_msg !== '') : ?>
        <p id="error"><?= $error_msg ?></p>
      <?php endif; ?>
      <form action="signup.php" method="post">
        <fieldset><legend>Sign Up</legend>
          <p>
            <label for="username">Username: </label>
            <input type="text" pattern="\w+" required autofocus
                   name="username" id="username"
                   placeholder="letters, digits, underscore" />
          </p>

          <p>
            <label for="password">Password: </label>
            <input type="password" required name="password"
                   placeholder="minimum length 5" pattern="[^ ]{5,}"
                   id="password" />
          </p>

          <p>
            <label for="displayname">Display Name: </label>
            <input type="text" required name="displayname"
                   placeholder="letters, digits, spaces"
                   pattern="[A-Za-z0-9 ]+" id="displayname" />
          </p>

          <p>
            <button type="submit" name="submit">Sign Up</button>
            &nbsp; &nbsp;
            <a href="home.php"><button type="button">Back Home</button></a>
          </p>
        </fieldset>
      </form>
    </section>
  </body>
</html>
<?php else :
header('Location: home.php');
endif; ?>
