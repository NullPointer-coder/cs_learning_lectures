// functions for the "style" example in class 20
// Jon Beck

"use strict";

function $(id)
{
  return document.getElementById(id);
}

window.onload = function ()
{
  $("text1").onkeypress = clear2;
  $("text2").onkeypress = clear1;
};

function clear2()
{
  $("text2").value = "";
}

function clear1()
{
  $("text1").value = "";
}
