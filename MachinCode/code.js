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



const arr1 = [1, [2, [3, [4, 5]]]];

const flat1 = arr.flat(1);
console.log(flat1);

const flat2 = arr.flat(2);
console.log(flat2);

const flat3 = arr.flat(3);
console.log(flat3);

const flatAll = arr.flat(Infinity);
console.log(flatAll);




function flatten(arr){
    return arr.reduce((acc,val)=>
    Array.isArray(val) ? acc.concat(flatten(val)) : acc.concat(val),[]);
}
const arr = [1, [2, [3, [4, 5]]]];
console.log(flatten(arr));




// Promise.all([...]) runs all promises in parallel.
// It waits until all have resolved, or rejects immediately if any fail.

async function findData(req,res){
    try{
       const [data,data1,data2] = await Promise.all([
           user.findAll(),
           employee.findAll(),
           salary.findAll()
           ]); 
           res.status(200).json({users:data,employee: data1, salaries:data2});
    }catch (err){
        console.log("error fetching data:",err);
        res.status(500).json({error: "Internal server error"});
    }
}

// Promise.allSettled() is used when you want to run multiple promises in parallel and handle the result of each, whether it succeeds or fails

async function findData(req, res) {
  try {
    const results = await Promise.allSettled([
      user.findAll(),
      employee.findAll(),
      salary.findAll()
    ]);

    const [userResult, employeeResult, salaryResult] = results;

    const response = {
      users: userResult.status === "fulfilled" ? userResult.value : null,
      employees: employeeResult.status === "fulfilled" ? employeeResult.value : null,
      salaries: salaryResult.status === "fulfilled" ? salaryResult.value : null,
      errors: []
    };

    if (userResult.status === "rejected") {
      response.errors.push({ type: "users", error: userResult.reason });
    }
    if (employeeResult.status === "rejected") {
      response.errors.push({ type: "employees", error: employeeResult.reason });
    }
    if (salaryResult.status === "rejected") {
      response.errors.push({ type: "salaries", error: salaryResult.reason });
    }

    res.status(200).json(response);
  } catch (err) {
    console.error("Unexpected error:", err);
    res.status(500).json({ error: "Unexpected server error" });
  }
}


// Promise.race() in JavaScript
// Promise.race() returns a promise that resolves or rejects as soon as the first promise in the iterable resolves or rejects — whichever happens first.

const p1 = new Promise(resolve => setTimeout(() => resolve("Result from p1"), 100));
const p2 = new Promise(resolve => setTimeout(() => resolve("Result from p2"), 200));

Promise.race([p1, p2]).then(result => {
  console.log(result); // "Result from p1"
});

















