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
    const result = await Employee.deleteOne({ _id: data._id });
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



