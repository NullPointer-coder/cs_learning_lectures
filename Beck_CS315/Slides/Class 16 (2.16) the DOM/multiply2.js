"use strict";
window.onload = attach_event_handlers;

// attach the page's event handlers
function attach_event_handlers()
{
  let compute_button = document.getElementById('compute_button');
  compute_button.onclick = multiply;
}

// Multiplies two numbers
function multiply()
{
  let multiplicand = document.getElementById('multiplicand').value;
  let multiplier = document.getElementById('multiplier').value;
  let product = multiplicand * multiplier;

  let answerspan = document.getElementById('answerspan');
  answerspan.innerHTML = product;
}
