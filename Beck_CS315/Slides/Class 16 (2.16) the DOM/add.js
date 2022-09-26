"use strict";
window.onload = attach_event_handlers;

// attach the page's event handlers
function attach_event_handlers()
{
  let compute_button = document.getElementById('compute_button');
  compute_button.onclick = compute;
}

// Add two numbers
function compute()
{
  let addend1 = document.getElementById('addend1').value;
  let addend2 = document.getElementById('addend2').value;
  let sum = addend1 + addend2;

  let answerspan = document.getElementById('answerspan');
  answerspan.innerHTML = sum;
}
