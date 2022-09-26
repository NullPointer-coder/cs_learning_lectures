// functions for the tip page
// Jon Beck

"use strict";

window.onload = function ()
{
  document.getElementById("fifteenpct").onclick = compute_tip;
  document.getElementById("eighteenpct").onclick = compute_tip;
  document.getElementById("twentypct").onclick = compute_tip;
};

function compute_tip()
{
  const subtotal = Number(document.getElementById("subtotal").value );
  const tip_pct = parseInt(this.innerHTML);
  const tip = subtotal * tip_pct / 100.0;
  const total = subtotal + tip;
  document.getElementById("tip").value = '$' + tip.toFixed(2);
  document.getElementById("total").value = '$' + total.toFixed(2);
}
