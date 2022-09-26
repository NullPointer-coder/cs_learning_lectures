"use strict";

/* this function returns a string */
function titleCase(arg)
{
  let result = "";

  arg.forEach((item) =>
  {
    result += item.charAt(0).toUpperCase() +
              item.substr(1).toLowerCase() + " ";

  });
  return result.substr(0, result.length - 1);
}

/* this function returns an array of strings */
function titleCaseArray(arg)
{
  const result = [];

  arg.forEach((item) =>
  {
    result.push(item.charAt(0).toUpperCase() +
                item.substr(1).toLowerCase());

  });
  return result;
}

const array = ["the", "DALLAS", "cowBoys"];
let answer = titleCase(array);
console.log(answer);

answer = titleCaseArray(array);
answer.forEach((item) => {console.log(item)});
