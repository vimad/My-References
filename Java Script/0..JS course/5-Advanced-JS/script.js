// Function constructor
/*
var john = {
    name: 'john',
    yearOfBirth: 1985,
    job: 'teacher'
};

var Person = function(name,yearOfBirth,job){
    this.name = name;
    this.yearOfBirth = yearOfBirth;
    this.job = job; 
};

Person.prototype.calculateAge = function(){
    console.log(2017-this.yearOfBirth);
};

Person.prototype.lastName = 'smith';

var john = new Person('john',1985,'teacher');
var jane = new Person('jane',1975,'designer');
var mark = new Person('mark',1965,'retired');
john.calculateAge();
jane.calculateAge();
mark.calculateAge();
console.log(john.lastName);
console.log(jane.lastName);
console.log(mark.lastName);
*/








//Object.create
/*
var personProto = {
    calculateAge: function(){
        console.log(2018 - this.yearOfBirth);
    }
};

var john = Object.create(personProto);
john.name = 'john';
john.yearOfBirth = 1985;
john.job = 'teacher';

var jane = Object.create(personProto,{
    name: {value: 'jane'},
    yearOfBirth: {value: 1975},
    job: {value:'teacher'}
});
*/







// Primitives and objects
/*
//primitives
var a = 23;
var b = a;
a = 46;
console.log(a);
console.log(b);


//objects
var obj1 ={
    name: 'john',
    age:26
};
obj2 = obj1;
obj1.age = 30;
console.log(obj1.age);
console.log(obj2.age);

//Functions
var age = 23;
var obj = {
    name:'vinod',
    city:'makandura'
};

function change(a,b){
    a = 30;
    b.city = 'colombo';
}

change(age,obj);

console.log(age);
console.log(obj.city);
*/






// passsing functions as arguments
/*
var years = [1994,1985,1978,1998,2000];

function arrCalc(arr,fn){
    var arrRet = [];
    for(var i=0;i<arr.length;i++){
        arrRet.push(fn(arr[i]));
    }
    return arrRet;
}

function calAge(el){
    return 2018 - el;
}

var result = arrCalc(years,calAge);
console.log(result);
*/




// returning functions from functions
/*
function intProb(job){
    if(job === 'designer'){
        return function(name){
            console.log(name+' hey designer');
        }
    }
    else if(job ==='teacher'){
        return function(name){
            console.log(name + ' hey teacher');
        }
    }else{
        return function(name){
            console.log(name+ ' go man');
        }
    }
}

var desProb = intProb('designer');
var techProb = intProb('teacher');

desProb('vinod');
techProb('tishan');
intProb('teacher')('rob');
*/





// Imeadiately invoked function expressions
/*
function game(){
    var score = Math.random()*10;
    console.log(score>=5);
}
game();
//console.log(score);

(function(){
    var score = Math.random()*10;
    console.log(score>=5);
})();

(function(goodluck){
    var score = Math.random()*10;
    console.log(score>=5-goodluck);
})(5);
*/





//Closures
/*
function retirement(retirementAge){
    var a = ' years left for retirement';
    
    return function(yearOfBirth){
        var age = 2018 - yearOfBirth;  
        console.log((retirementAge-age)+a);
    };
}

var retirementSL = retirement(65);
retirementSL(1994);
retirement(65)(1994);
*/





// bind, call and apply
/*
var john = {
    name: 'john',
    age: 26,
    job: 'teacher',
    presentation: function(style,timeOfDay){
        if(style === 'formal'){
            console.log('hi gentlements and good '+timeOfDay+' i am '+this.name+' of age '+this.age+' '+this.job);
        }else if(style === 'friendly'){
            console.log('hi guys and good '+timeOfDay+' i am '+this.name+' of age '+this.age+' '+this.job);
        }else{
            
        }
    }
};

var vinod = {
    name: 'vinod',
    age: 24,
    job: 'nothing'
};

//john.presentation('formal','morning');

//john.presentation.call(vinod,'friendly','evening');

//john.presentation.apply(vinod,['friendly','morning']);

var johnFriendly = john.presentation.bind(john,'friendly');

johnFriendly('morning');
johnFriendly('evening');

var years = [1994,1985,1978,1998,2000];
function arrCalc(arr,fn){
    var arrRet = [];
    for(var i=0;i<arr.length;i++){
        arrRet.push(fn(arr[i]));
    }
    return arrRet;
}

function calAge(el){
    return 2018 - el;
}

function isFullAge(limit,el){
    return el>=limit;
}

var ages = arrCalc(years,calAge);
var fullJapan = arrCalc(ages,isFullAge.bind(this,20));
console.log(ages);
console.log(fullJapan);
*/

//coding challenge - quizzzzzzzzzz

(function(){
    var question = function(quiz,ansewrs,ans){
        this.quize = quiz;
        this.answers = ansewrs;
        this.ans = ans;
    };

    question.prototype.printer = function(){
            console.log(this.quize);
            for(var i=0;i<this.answers.length;i++){
                console.log(i+' '+this.answers[i]);
            }
        };

    question.prototype.checkAnswer = function(givenans){
        if(givenans == this.ans){
            console.log('success');
        }else{
            console.log('fail');
        }
    }

    prob1 = 'who am i?'
    answers1 = ['a','b','c'];
    ans = 0;
    q1 = new question(prob1,answers1,ans);

    prob1 = 'who am you?'
    answers1 = ['a','b','c'];
    ans = 1;
    q2 = new question(prob1,answers1,ans);

    prob1 = 'what is this?'
    answers1 = ['a','b','c'];
    ans = 2;
    q3 = new question(prob1,answers1,ans);


    arr = [q1,q2,q3];
    ranNumber = Math.floor(Math.random()*3);

    var ask = arr[ranNumber];
    ask.printer();

    var givenans = parseInt(prompt('Give the correct answer'));
    ask.checkAnswer(givenans);
})();












































