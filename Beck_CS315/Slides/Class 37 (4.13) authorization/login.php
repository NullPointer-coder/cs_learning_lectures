<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');
session_start();

require 'dblogin.php';

$db = new PDO("mysql:host=$db_host;dbname=jbeck;charset=utf8mb4",
              $db_user, $db_pass,
              array(PDO::ATTR_EMULATE_PREPARES => false,
                    PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));

$error_msg = '';
$already_logged_in = false;

if (!(isset($_SESSION['username'])))
{
  if (isset($_POST['submit']))
  {
    if (isset($_POST['username']) &&
        preg_match('|^\w+$|', $_POST['username']) &&
        isset($_POST['password']) &&
        preg_match('|^\S+$|', $_POST['password']))
    {
      $sql = 'select username, password, displayname
              from user
              where username = :username';
      $statement = $db->prepare($sql);
      $statement->bindValue(':username', $_POST['username']);
      $statement->execute();
      $result = $statement->fetchAll(PDO::FETCH_ASSOC);

      if (count($result) == 1)
      {
        if (password_verify($_POST['password'], $result[0]['password']))
        {
          $_SESSION['username'] = $result[0]['username'];
          $_SESSION['displayname'] = $result[0]['displayname'];
          header('Location: home.php');
          exit();
        }
        else
        {
          $error_msg = 'Username-password pair is invalid';
        }
      }
      else
      {
        $error_msg = 'Username-password pair is invalid';
      }
    }
    else
    {
      $error_msg = 'You must enter a valid username-password pair';
    }
  }
}
else
{
  $already_logged_in = true;
}
?>
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

    <?php if ($already_logged_in): ?>
      <p>
        You are already logged in as <?= $_SESSION['displayname'] ?>
      </p>

      <p>
        <a href="home.php"><button type="button">OK</button></a>
      </p>

    <?php else:

      if (!empty($error_msg)): ?>
        <p id="error"><?= $error_msg ?></p>
      <?php endif; ?>
        <form action="login.php" method="post">
          <fieldset><legend>Log In</legend>
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
              <button type="submit" name="submit">Log In</button>
              &nbsp; &nbsp;
              <button type="button"><a href="home.php">Back Home</a></button>
            </p>
          </fieldset>
        </form>
      <?php endif; ?>
    </section>
  </body>
</html>
