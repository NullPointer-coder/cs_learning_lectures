// functions for the "style" example in class 20
// Jon Beck

"use strict";

window.onload = function()
{
  document.getElementById("serif").onclick = fontClick;
  document.getElementById("sans-serif").onclick = fontClick;
  document.getElementById("monospace").onclick = fontClick;
};

function fontClick()
{
  let lyriclist = document.getElementsByClassName("lyricline");
  for (let i = 0; i < lyriclist.length; i++)
  {
    lyriclist[i].classList.remove("familynormal");
    lyriclist[i].classList.remove("familysans-serif");
    lyriclist[i].classList.remove("familymono");
    lyriclist[i].classList.add(this.value);
  }
}
