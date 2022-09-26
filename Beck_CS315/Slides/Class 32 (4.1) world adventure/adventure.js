/**
  Jon Beck
  functions to support world adventure
*/

"use strict";

let xhr = null;

const $ = (id) => document.getElementById(id);

/**
  * register callbacks
*/
window.onload = function()
{
  $("continent_select").onchange = get_languages;
  $("get_countries_button").onclick = get_countries;
  $("lang_select").onchange = check_language_selection;
  $("again_button").onclick = reset;
  get_continents();
};

/**
  * enable the get_countries_button when one or more lanugages is selected
  * disable the button if no languages are selected
*/
function check_language_selection()
{
  const checked = document.querySelectorAll("#lang_select option:checked");
  $("get_countries_button").disabled = (checked.length === 0);
}

/**
  * use ajax + json to fetch a list of all continents from the database
  * populate the continent select list with the results
*/
function get_continents()
{
  if (xhr)
  {
    xhr.abort();
    xhr = null;
  }

  xhr = new XMLHttpRequest();
  xhr.open("GET", "get_continents.php", true);

  xhr.onload = function()
  {
    let options = "";
    JSON.parse(xhr.responseText).forEach((element) =>
    {
      options += `<option value="${element}">${element}</option>` + "\n";
    });
    $("continent_select").innerHTML = options;
  };
  xhr.send();
}

/**
  * use ajax + json to fetch languages that match a continent
  * populate the language select control with the results
*/
function get_languages()
{
  const continent = this.value;
  $("lang_select").innerHTML = "";
  $("selected_continent").textContent = continent;

  if (xhr)
  {
    xhr.abort();
    xhr = null;
  }

  xhr = new XMLHttpRequest();
  xhr.open("GET", `get_languages.php?cont=${continent}`, true);

  xhr.onload = function()
  {
    JSON.parse(xhr.responseText).forEach((element) =>
    {
      const newoption = document.createElement("option");
      newoption.value = element[0];
      newoption.innerText = element[1];
      $("lang_select").appendChild(newoption);
    });

    show($("langdiv"));
    show($("submitdiv"));
    $("get_countries_button").disabled = true;
  };
  xhr.send();
}

/**
  * use ajax + json to fetch a list of countries that match languages
  * on a continent
  * populate the country list with the results
*/
function get_countries()
{
  if (xhr)
  {
    xhr.abort();
    xhr = null;
  }

  $("get_countries_button").disabled = true;
  $("lang_select").disabled = true;
  $("continent_select").disabled = true;

  let languages = [];

  Array.from($("lang_select").options).forEach((option) =>
  {
    option.selected && languages.push(option.value);
  });
  languages = JSON.stringify(languages);

  xhr = new XMLHttpRequest();
  xhr.open("POST", "get_countries.php", true);

  xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
  const continent = $("selected_continent").textContent;
  const postparams = `lang=${languages}&cont=${continent}`;

  xhr.onload = function()
  {
    JSON.parse(xhr.responseText).forEach((country) =>
    {
      let newli = document.createElement("li");
      newli.value = country;
      newli.innerText = country;
      $("countrylist").appendChild(newli);
    });

    show($("countriesdiv"));
  };
  xhr.send(postparams);
}

/**
  * reset the web page to the starting state, clearing out previous
  * selections and hiding appropriate elements
*/
function reset()
{
  hide($("langdiv"));
  hide($("submitdiv"));
  hide($("countriesdiv"));
  $("get_countries_button").disabled = true;
  $("lang_select").innerHTML = "";
  $("countrylist").innerHTML = "";
  $("continent_select").disabled = false;
  $("lang_select").disabled = false;
  $("selected_continent").innerText = "";
  get_continents();
}

/**
  * hide an element
  * @param element the element to be hidden
*/
function hide(element)
{
  element.classList.remove("visible");
  element.classList.add("hidden");
}

/**
  * make an element visible
  * @param element the element to be made visible
*/
function show(element)
{
  element.classList.remove("hidden");
  element.classList.add("visible");
}
