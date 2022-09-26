// functions for the "style" example in class 20
// Jon Beck

"use strict";
const $ = (id) => document.getElementById(id);

window.onload = function ()
{
  $("text1").onkeypress = function () {$("text2").value = "";};
  $("text2").onkeypress = function () {$("text1").value = "";};
};
