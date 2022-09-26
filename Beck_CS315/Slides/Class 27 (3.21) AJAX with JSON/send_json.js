// Jon Beck
// Use JS to send data in JSON format to server

"use strict";

const $ = (id) => document.getElementById(id);

window.onload = function ()
{
  $("send-array").onclick = send_array_JSON;
  $("send-object").onclick = send_object_JSON;
};

function send_object_JSON()
{ 
  const xhr = new XMLHttpRequest();
  const url = "receive_json.php";
  const data_object =
  {
    "name": "Fred Flintstone",
    "address": "123 Rocky Way",
    "city": "Bedrock"
  };
  const json_string = `payload=${JSON.stringify(data_object)}`;

  xhr.open("POST", url);
  xhr.setRequestHeader
    ("Content-Type", "application/x-www-form-urlencoded;charset=utf-8");
  xhr.send(json_string);
}

function send_array_JSON()
{ 
  const xhr = new XMLHttpRequest();
  const url = "receive_json.php";
  const data_array = ["apple", "banana", "cabbage", "dates", "eggplant"];
  const json_string = `payload=${JSON.stringify(data_array)}`;

  xhr.open("POST", url);
  xhr.setRequestHeader
    ("Content-Type", "application/x-www-form-urlencoded;charset=utf-8");
  xhr.send(json_string);
}
