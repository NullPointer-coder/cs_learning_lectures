<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');

$error_msg = '';
$already_logged_in = false;
$hash = '$2y$10$tchOFY8.cxdHnA1L8S1.WeOqz1KpxPW69pP6j/PtxdcrPOP7Rg4ta';

if (!(isset($_COOKIE['username']) && isset($_COOKIE['fullname'])))
{
  if (isset($_POST['submit']))
  {
    if (isset($_POST['username']) &&
        preg_match('|^\w+$|', $_POST['username']) &&
        isset($_POST['password']) &&
        preg_match('|^\S+$|', $_POST['password']))
    {
      if ($_POST['username'] == 'jbeck' &&
          password_verify($_POST['password'], $hash))
      {
        setcookie('username', 'jbeck');
        setcookie('fullname', 'Jon Beck');
        header('Location: home.php');
        exit;
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
    <meta name="author" content="Jon Beck" />
    <link rel="stylesheet" href="login.css" />
    <title>Login Cookie Demo</title>
  </head>

  <body>
    <header><h1>ACME Corp</h1></header>

    <section>
    <?php if ($already_logged_in): ?>
      <p>
        You are already logged in as <?= $_COOKIE['fullname'] ?>
      </p>

      <p>
        <a href="home.php">OK</a>
      </p>

    <?php else:

      if (!empty($error_msg)): ?>
        <p id="error"><?= $error_msg ?></p>
      <?php endif; ?>
        <form action="login.php" method="post">
          <fieldset>
            <legend>Log In</legend>
              <label for="username">Username: </label>
              <input type="text" pattern="\w+" required autofocus
                     name="username" id="username"
                     placeholder="letters, digits, underscore" />

              <label for="password">Password: </label>
              <input type="password" name="password" id="password"
                     placeholder="minimum length 5" pattern="\S{5,}"
                     required />

              <span>&nbsp;</span>
              <button type="submit" name="submit">Log In</button>
          </fieldset>
        </form>
        <p>(Username is jbeck; password is myPass)</p>
      <?php endif; ?>
    </section>
  </body>
</html>
