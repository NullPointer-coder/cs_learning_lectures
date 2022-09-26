"use strict";
window.onload = attachEventHandlers;

// attach the page's event handlers
function attachEventHandlers()
{
  let computeButton = document.getElementById('compute_button');
  computeButton.onclick = multiply;
}

// Multiplies two numbers
function multiply()
{
  let input1 = document.getElementById('numx').value;
  let input2 = document.getElementById('num2').value;
  let result = input1 * input2;

  let answer = document.getElementById('answer');
  answer.innerHTML = result;
}
