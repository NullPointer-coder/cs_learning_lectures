// functions for the "style" example in class 20
// Jon Beck

"use strict";

const $ = id => document.getElementById(id);

window.onload = function ()
{
  $("serif").onclick = fontClick;
  $("sans-serif").onclick = fontClick;
  $("monospace").onclick = fontClick;
};

function fontClick()
{
  const lyriclist = document.getElementsByClassName("lyricline");
  for (let i = 0; i < lyriclist.length; i++)
  {
    lyriclist[i].classList.remove("familynormal");
    lyriclist[i].classList.remove("familysans-serif");
    lyriclist[i].classList.remove("familymono");
    lyriclist[i].classList.add(this.value);
  }
}
