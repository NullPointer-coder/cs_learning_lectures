/* Jon Beck */

"use strict";

const $ = (id) => document.getElementById(id);

window.onload = function ()
{
  $("new-word").onchange = check_new;
  $("new-word").onkeyup = normalize_word;
  $("part").onchange = check_new;
  $("new-defn").onchange = check_new;
  $("new-submit").onclick = add_new_word;
  get_words();
};

function normalize_word()
{
  const re = /[A-Za-z]/;
  var result = "";
  $("new-word").value.split("").forEach(function(char)
  {
    if (re.test(char))
    {
      result += char.toLowerCase();
    }
  });
  $("new-word").value = result;
}

function check_new()
{
  normalize_word();
  const wordpart = $("new-word").value + $("part").value;
  let duplicate = false;
  const wordpartdivs =
    Array.from(document.getElementsByClassName("wordpart"));

  wordpartdivs.forEach(function (element)
  {
    const thiswordpart = element.textContent;
    if (thiswordpart === wordpart)
    {
      duplicate = true;
    }
  });

  if (duplicate)
  {
    alert("Duplicate detected");
    $("new-word").focus();
    return false;
  }

  if ($("new-word").value.length > 0 &&
      $("part").value.length > 0 &&
      $("new-defn").value.length > 0)
  {
    $("new-submit").disabled = false;
  }
  else
  {
    $("new-submit").disabled = true;
  }
  return true;
}

function get_words()
{
  const xhr = new XMLHttpRequest();

  xhr.open("GET", "get_words.php", true);
  xhr.onload = function ()
  {
    const results = JSON.parse(xhr.responseText);
    let word_list_HTML = "";
    results.forEach(function(element)
    {
      word_list_HTML +=
`  <div class="word">${element[0]}</div>
   <div class="part">${element[1]}</div>
   <div class="defn">${element[2]}</div>
   <div class="wordpart" hidden>${element[0]}${element[1]}</div>
`;
    });

    $("words-grid").innerHTML = word_list_HTML;
  };
  xhr.send();
  $("new-word").focus();
}

function add_new_word()
{
  if (check_new())
  {
    const xhr = new XMLHttpRequest();
    const data_array =
      [$("new-word").value, $("part").value, $("new-defn").value];
    const payload = encodeURIComponent(JSON.stringify(data_array));
    const json_string = `payload=${payload}`;

    xhr.open("POST", "put_word.php");
    xhr.setRequestHeader
     ("Content-Type", "application/x-www-form-urlencoded;charset=utf-8");
    xhr.send(json_string);
    xhr.onload = get_words;
    $("new-word").value = "";
    $("part").value = "";
    $("new-defn").value = "";
    $("new-submit").disabled = true;
  }
}
