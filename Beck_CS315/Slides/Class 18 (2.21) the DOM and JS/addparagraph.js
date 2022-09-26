// functions for the addparagraph page in class 20
// Jon Beck

"use strict";

window.onload = function ()
{
  document.getElementById("add").onclick = addParagraph;
};

function addParagraph()
{
  const colors = ["red", "orange", "black", "green", "blue",
                "indigo", "violet"];
  const newpara = document.createElement("p");
  const color = colors[Math.floor(Math.random() * colors.length)];
  newpara.innerHTML = "This paragraph is " + color;
  newpara.classList.add(color);
  document.getElementById("paragrapharea").appendChild(newpara);
}
