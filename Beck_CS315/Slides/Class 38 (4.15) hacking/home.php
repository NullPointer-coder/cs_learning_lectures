<?php

error_reporting(E_ALL);
ini_set('display_errors', '1');

session_start();

$loggedin = isset($_SESSION['username']);

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

    <aside>
      <?php if ($loggedin): ?>
        <p>
          Hello<br />
          <?= $_SESSION['displayname'] ?>
        </p>
        <p>
          <button type="button">
            <a href="logout.php">Logout</a>
          </button>
        </p>
      <?php else: ?>
        <p>
          <button type="button">
            <a href="login.php">Login</a>
          </button><br />
          <button type="button">
            <a href="signup.php">Sign Up</a>
          </button>
        </p>
      <?php endif; ?>
    </aside>

    <section>
      <h2>
        <?php if ($loggedin): ?>
          Manage Our Public Data<br />
          (links are fake)
        <?php else: ?>
          Here is Our Public Data
        <?php endif; ?>
      </h2>

      <?php $data = array('Foo', 'Bar', 'Bim', 'Bam'); ?>
      <ul>
        <?php foreach ($data as $item): ?>
          <li>
            <?php if ($loggedin): ?>
              <a href="<?= $item ?>.php"><?= $item ?></a>
            <?php else: ?>
              <?= $item ?>
            <?php endif; ?>
          </li>
        <?php endforeach; ?>
      </ul>

    </section>
  </body>
</html>
