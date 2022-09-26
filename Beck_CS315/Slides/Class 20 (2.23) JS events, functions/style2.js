// functions for the "style" example in class 20
// Jon Beck

"use strict";

const $ = (id) => document.getElementById(id);

window.onload = function ()
{
  $("serif").onclick = fontClick;
  $("sans-serif").onclick = fontClick;
  $("monospace").onclick = fontClick;
};

function fontClick()
{
  document.getElementsByClassName("lyricline").forEach(function (item)
  {
    item.classList.remove("familynormal");
    item.classList.remove("familysans-serif");
    item.classList.remove("familymono");
    item.classList.add(this.value);
  });
}
