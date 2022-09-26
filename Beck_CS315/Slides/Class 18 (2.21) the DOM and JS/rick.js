"use strict";

window.onload = function ()
{
  document.getElementById("serif").onclick = fontClick;
  document.getElementById("sans-serif").onclick = fontClick;
  document.getElementById("monospace").onclick = fontClick;
  document.getElementById("bold").onclick = boldClick;
  document.getElementById("italic").onclick = italicClick;
};

function fontClick()
{
  document.getElementById("lyrics").style.fontFamily = this.id;
}

function italicClick()
{
  const lyrics = document.getElementById("lyrics");
  if (this.checked)
  {
    lyrics.style.fontStyle = "italic";
  }
  else
  {
    lyrics.style.fontStyle = "normal";
  }
}

function boldClick()
{
  const lyrics = document.getElementById("lyrics");
  if (this.checked)
  {
    lyrics.style.fontWeight = "bold";
  }
  else
  {
    lyrics.style.fontWeight = "normal";
  }
}
