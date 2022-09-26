// Jon Beck
// Use JS to retrieve data in JSON format and use it

"use strict";

let xhr = null; // a global variable to prevent race
const $ = (id) => document.getElementById(id);

window.onload = function ()
{
  $("wordsearch").onkeyup = select_words;
  $("choosebutton").onclick = report_choice;
};

function select_words()
{
  if (xhr)
  {
    xhr.abort();
    xhr = null;
  }

  const wordsearch = $("wordsearch").value;
  if (wordsearch.length === 0 )
  {
    $("search_results").innerHTML = "";
    $("results-sec").classList.remove("visible");
    $("results-sec").classList.add("hidden");
  }
  else
  {
    xhr = new XMLHttpRequest();
    const url = `get_words_json.php?search=${wordsearch}`;

    xhr.open("GET", url, true);
    xhr.onload = function ()
    {
      const results = JSON.parse(xhr.responseText);
      let word_list_HTML = "";
      results.forEach(function (wordpart)
      {
        const pair = wordpart.split("_");
        word_list_HTML +=
`  <div>
     <input type="radio" value="${wordpart}" name="wordradio"
            id="${wordpart}" />
   </div>
   <div><label for="${wordpart}">${pair[0]}</label></div>
   <div>${pair[1]}</div>
`;
      });

      $("search_results").innerHTML = word_list_HTML;
      $("results-sec").classList.remove("hidden");
      $("results-sec").classList.add("visible");
    };
    xhr.send();
  }
}
function report_choice()
{
  $("search-sec").classList.add("hidden");
  $("choose-sec").classList.add("hidden");
  $("results-sec").classList.remove("hidden");
  $("results-sec").classList.add("visible");
  $("report-sec").classList.remove("visible");
  $("report-sec").classList.add("visible");

  const buttons = document.getElementsByName("wordradio");
  if (buttons === null)
  {
    $("report-sec").innerHTML = "<p>No word was selected</p>";
    return true;
  }

  let i = 0;
  let found = false;
  while (i < buttons.length && !found)
  {
    if (buttons[i].checked)
    {
      found = true;
    }
    else
    {
      i++;
    }
  }

  if (found)
  {
    const wordpart = buttons[i].value.split("_");
    $("word").innerHTML = wordpart[0];
    $("part").innerHTML = wordpart[1];
  }
  else
  {
    $("report-sec").innerHTML = "<p>No word was selected</p>";
  }
}
