const phone = '7885025909';

function printFormat(num) {
  let frequencyMap = {};

  // Calculate the frequency of each digit
  for (let digit of num) {
    frequencyMap[digit] = (frequencyMap[digit] || 0) + 1;
  }

  // Print each digit and its frequency
  for (let digit in frequencyMap) {
    console.log(`${digit} ${frequencyMap[digit]}`);
  }
}

printFormat(phone);


// -------------------------------Part 2----------------------
function printFormat(num) {
  let size = 10;
  let freq = new Array(size).fill(0);

  // Calculate the frequency of each digit
  for (let i = 0; i < num.length; i++) {
    freq[num[i].charCodeAt(0) - '0'.charCodeAt(0)]++;
  }

  // Print the digits and their frequencies only once
  let printed = new Set();
  for (let i = 0; i < num.length; i++) {
    let digit = num[i];
    if (!printed.has(digit)) {
      console.log(digit + ' ' + freq[digit.charCodeAt(0) - '0'.charCodeAt(0)]);
      printed.add(digit);
    }
  }
}
printFormat(phone);



//  OutPut  : -----
// 7 2
// 8 3
// 5 1
// 0 1
// 2 1
// 9 2