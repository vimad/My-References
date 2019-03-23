//console.log("Hello world");
//
//var name = prompt("What the fucking name???");
//console.log(name);
//
//alert("braaaaaaaaaaaaaaa");

//switch
var age = 23;
switch(age){
    case 23:
        console.log(age);
        break;
    default:
        console.log("switcher");
}

//array
var vin = [1,2,3,4];
console.log(vin);
vin.push(5);
console.log(vin);
vin.unshift(0);
console.log(vin);
vin.pop();
console.log(vin);
vin.shift();
console.log(vin);
console.log(vin.indexOf(4));

//object
var vin = {
  name: 'vinod',
    age: 23,
    stud:'yes',
    printer: function(a){
        console.log("obj func");
    }
};

var x = 'name';
console.log(vin[x]);

var a = new Object();
a.name = 'kkska';
a.age = 12;
console.log(a);