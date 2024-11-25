var persion = {
    name : "sam",
    hello: function(){
        console.log(this.name);
    }
};
persion.hello();

let x = 1;
let y = 2;
console.log(x++ + ++y);


console.log([1,2]+![])// "1,2false"

let a = [1];
let b = [2];
console.log(a+b) // "12"

console.log(3+4+"5"); //"75"

let x = 10 > 9 > 8;
console.log(x == true);  // false

y = 10;
var x = 1+y;
console.log(x);  // 10

function data(){
    let a = b = 5
}
data();
console.log(b); // 5

const arr1 = [1,2,3];
const str = "1,2,3";
console.log(str == arr1);

let newList = [1].push[2];
console.log(newList.push(3));

x++;
console.log(x);
var x = 21; // NaN

const x = [];
x[4] = 1;
x.forEach((i)=>{
    console.log("hi")
})  // one time - "hi"

console.log([] == []); // false  

const x = {name:"sai"};
const arr = ["name"];
x[arr] = "krishna";
console.log(x.name); //krishna


let x={
    flag:1,
    toString: function(){
        return this.flag++
    }
};
if(x==1 && x==2 && x==3){
    console.log("hello")
}


let arr = [1,2];
let rev = arr.reverse();
console.log(arr,rev);

const x = NaN;
const y = NaN;
console.log(x == y); // false

var x = 1;
let y = 1
{
    var x = 2;
    let y = 2;
}
console.log(x,y); // 2,1


let timer = setTimeout(()=>{
    console.log("hello")
},0)
clearTimeout(timer);// Nothing is printed b/c it clear the existing Task queue

if((false){
    var s = "sai";
})
console.log(a);// undefined



const data = {
    name:"sai",
    name:"krishna"
}
console.log(data.name) // krishna -  b/c last properties override the previous one

const a = [];
const b = false;
console.log(a == b); // True;

let x = "Learn";
console.log(x.substring(5,1)); // earn

(function(num){
    console.log(num*num)
})(false)// 0

const x= [1,2,3];
delete x[1];
console.log(x.length)// 3 b/c delete only replace with empty length is not change

let arr1 = [1,2,[3,4]];
let arr2 = [...arr1];
arr2[1] = 10;
arr2[2][0] = 100;
console.log(originalArray);

new Promise(()=>{
    console.log("d");
});
console.log("s");// ds