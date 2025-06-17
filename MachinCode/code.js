///////////////////////////Q-1////////////////

class Counter {
    constructor(initialValue) {
      this.value = initialValue;
    }
  
    increment() {
      return ++this.value;
    }
  
    decrement() {
      return --this.value;
    }
  }
  
  // Example usage:
  var counter = new Counter(5);
  
  console.log(counter.increment()); // 6
  console.log(counter.increment()); // 7
  console.log(counter.decrement()); // 6
  console.log(counter.decrement()); // 5


//////////////////////////// Q-2 ///////////////////

function commonele(arr1,arr2){
    
    return arr1.filter(value=> arr2.includes(value));
}
var arr1 = [1, 2, 3, 4, 5];
var arr2 = [6, 7, 3, 8, 5];
const result = commonele(arr1,arr2);
console.log(result);

// // Output: [3, 5]


///////////////////////////////////////// Q-3 ///////////////////////



function mergeAndSortArrays(arr1, arr2) {
    return [...arr1, ...arr2].sort((a, b) => a - b);
  }

// Merging and sorting two arrays
console.log(mergeAndSortArrays([3, 1, 4], [6, 2, 5])); // [1, 2, 3, 4, 5, 6]




//////////////////////// Q-4 /////////////////////////////////


function unionOfArrays(arr1, arr2) {
    return [...new Set([...arr1, ...arr2])].sort((a, b) => a - b);
  }

// Union of two arrays
console.log(unionOfArrays([3, 1, 4, 3], [6, 2, 5, 1])); // [1, 2, 3, 4, 5, 6]


///////////////////////// Q-5 /////////////////////////////////

const express = require("express");
const app = express();

app.use(express.json());


app.get("/",async (req,res)=>{
    const data  = req.body;
    const result = await employee.find(data);
    res.send(result);
})

app.post("/post",async (req,res)=>{
    const data = new employee(req.body);
    await data.save();
    res.send("Data saved successfully");
})

app.put("/put",async (req,res)=>{
    const data = req.body;
    const result = await Employee.findOneAndUpdate({ _id: data._id }, data, {
      new: true,
      upsert: true, // Create if it doesn't exist
    });
    res.json(result);
})

app.patch("/patch",async (req,res)=>{
    const data = req.body;
    const result = await Employee.findOneAndUpdate({ _id: data._id }, data, {
      new: true,
      upsert: true, // Create if it doesn't exist
    });
    res.json(result);
})

app.delete("/delete",async (req,res)=>{
    const data = req.body;
    await Employee.deleteOne({ _id: data._id });
    res.send("Data deleted successfully");
})

app.listen(3000,()=>{
    console.log(`server is running at port : 3000`)
});

/////////////////////// Q-5  /////////////////////////

function findUniqueElement(arr) {
    return arr.reduce((acc, num) => acc ^ num, 0);
  }
  
  // Example usage:
  console.log(findUniqueElement([4, 1, 2, 1, 2])); // Output: 4

//   a ^ a = 0 (XOR of the same number cancels out)
//   a ^ 0 = a
//   So only the unique number remains.

var reverseWords = function(s) {
  return s.split( ' ')
  .map(word=>word.split('').reverse().join(''))
  .join(' ');
};
console.log(reverseWords("Let's take LeetCode contest"));


// Output: "s'teL ekat edoCteeL tsetnoc"



// Small letter which is not duplicated

let result3 = [...str].filter( ch => ch >= 'a' && ch <= 'z' && str.indexOf(ch) === str.lastIndexOf(ch));
console.log(result3);

// Output: [ 'c', 'd' ]


// Given a string , remove all the duplicate elements from a string

function removeDuplicates(str) {
  return [...new Set(str)].join('');
}
 
// Example
console.log(removeDuplicates('aabbccdde')); // Output: 'abcde'

//////////////////////////////////
function removeDuplicates(str) {
  let result = '';
  for (let char of str) {
    if (!result.includes(char)) {
      result += char;
    }
  }
  return result;
}

// Example
console.log(removeDuplicates('aabbccdde')); // Output: 'abcde'



// Writing a program to find the closest palindrome time (hh:mm format) in js

function isPalindrome(time)
{
    return time === time.split('').reverse().join('');
}
function closestPalindromeTime(time){
    // time.split(':') → turns "12:34" into ['12', '34']
    // .map(Number) → converts both parts to numbers: [12, 34]
    // Assigns to h (hours) and m (minutes)
    let[h,m] = time.split(":").map(Number);
    
    while(true){
        // A loop that keeps checking every minute until a palindrome time is found.
        
       // Converts h and m to strings with leading 0s if needed (e.g. 9 → "09")
       // Joins into "HH:MM" format
        let timeStr = `${h.toString().padStart(2,'0')}:${m.toString().padStart(2,'0')}`;
        
        
        if(isPalindrome(timeStr.replace(':',''))){
            return timeStr;
        }
        // Adds one minute
        // If minutes reach 60 → reset minutes to 0 and increment hour
        // If hour reaches 24 → wrap around to 0 using % 24
        m++;
        if(m === 60){
            m = 0;
            h = (h+1) % 24;
        }
    }
}
console.log(closestPalindromeTime("12:34"));
console.log(closestPalindromeTime("23:59"));

