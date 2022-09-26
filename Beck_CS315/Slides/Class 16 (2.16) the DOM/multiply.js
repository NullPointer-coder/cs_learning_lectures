// Multiplies two numbers
function compute()
{
    var input1 = document.getElementById( 'num1' ).value;
    var input2 = document.getElementById( 'num2' ).value;
    var answerspan = document.getElementById( 'answer' );

    var result = input1 * input2;
    answerspan.innerHTML = result;
}
