// Jon Beck
// Simple AJAX request

"use strict";

const $ = (id) => document.getElementById(id);

window.onload = function()
{
  $("load-xhr").onclick = load_with_xhr;
  $("load-promise").onclick = load_with_promise;
  $("clear").onclick = () => {$("poembox").innerHTML = "Watch here";};

  $("redbutton").onclick = function ()
  {
    $("colorme").classList.remove("blue");
    $("colorme").classList.add("red");
  };

  $("bluebutton").onclick = function ()
  {
    $("colorme").classList.remove("red");
    $("colorme").classList.add("blue");
  };
};

function load_with_xhr()
{
  const xhr = new XMLHttpRequest();

  xhr.open("GET", "roses.txt");
  xhr.onload = function ()
  {
    $("poembox").innerHTML = xhr.responseText;
  };
  xhr.send(null);
}

function load_with_promise()
{
  fetch("roses.txt")
    .then((payload)  =>  payload.text())
    .then(function (response) {$("poembox").innerHTML = response;});
}
