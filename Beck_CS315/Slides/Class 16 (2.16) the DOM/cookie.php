<?php
if (isset($_COOKIE['fred']) && preg_match('/^\d+$/', $_COOKIE['fred']))
{
  $fredvalue = $_COOKIE['fred'];
  $fredvalue++;
}
else
{
  $fredvalue = 0;
}

if (isset($_POST['set']))
{
  setcookie('fred', $fredvalue);
}
elseif (isset($_POST['reset']))
{
  setcookie('fred', 0);
}
elseif (isset($_POST['delete']))
{
  setcookie('fred', -1, time() - 3600);
}
?>
<!DOCTYPE html>
<html lang="en">
  <head>
    <title>Cookie Example</title>
    <meta charset="utf8" />
    <link rel="stylesheet" href="cookie.css" />
  </head>
  <body>
    <header><h1>Cookie Example</h1></header>

    <section>
      <?php if (isset($_COOKIE['fred'])): ?>
        <p id="display">The Fred Cookie is <?= $_COOKIE['fred'] ?></p>
      <?php else: ?>
        <p id="display">There is No Fred Cookie</p>
      <?php endif; ?>

      <form action="cookie.php" method="post">
        <p>
          <button type="submit" name="nochange">Visit the Page</button>
        </p>
        <p>
          (display but do not alter cookie)
        </p>

        <p>
          <button type="submit" name="set">Visit the Page</button>
        </p>
        <p>
          (increment cookie or clear it to 0 if it does not exist)
        </p>

        <p>
          <button type="submit" name="reset">Reset the Cookie</button>
        </p>
        <p>
          (clear cookie value to 0)
        </p>

        <p>
          <button type="submit" name="delete">Delete the Cookie</button>
        </p>

        <p>
          (remove it from the server)
        </p>
      </form>
    </section>
  </body>
</html>
