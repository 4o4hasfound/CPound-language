# CPound

CPound is an interpreted language heavily inspired by [Dreamberd](https://github.com/TodePond/DreamBerd/tree/main?tab=readme-ov-file), possibly a successor of the popular language [C hashtag](https://en.wikipedia.org/wiki/C_Sharp_(programming_language))

<img src=res/CPound%20logo.png width="200">

## Interpreter usage

Usage: cpound [filename] ([log file]) (--debug) 
You should end your files with .cp, but CPound will interpret it as long as it's a text file  

## Types

CPound provides 4 basic types

+ int (underlying type: int64_t)
+ float (underlying type: double)
+ bool (underlying type: bool)
+ string (underlying type: wstring)

## Casting

String will automatically be converted into int or float if needed

## Devide by Zero

With simplicity in mind, CPound will gracefully returns 0

## Keywords

CPound's builtin keywords aren't case sensitive, so you can finaly capitalize any letter you want!

## Statement Terminator

In CPound, statement terminator includes exclamation marks and question marks  
They servers crucial purposes in certain position, be most of the time can be omitted

#### Exclamation mark

The amount of exclamation mark at the end of a varaible declaration determines its priority  
Declarations with higher priority can override ones with lowerpriority

```java
var var var int a = 1!
var var var int a = 2!! // Override!
var var var int a = 3!! // Didn't override!
```

#### Question mark

Adding one at the end of a statement will print debug info  
(Not yet implemented)

## Logical not

CPound uses semicolon as the logical not operator

```java
;false == true
```

## Variable declarations

```java
var var var int variable!
```

The above declaration includes

+ Declaration type (var var var)
+ Variable Type (int)
+ Identifier (variable)

The first component of the declaration type determine if it is editable

```java
var const const int a = 1! // Editable variable
a++! // OK
const const const int b = 1! // Non editable variable
b++! // Error
```

The second component of the declaration type determine if it is reassignable

```java
const var const int a = 1! // Reassignable variable
a = 2! // OK
const const const int b = 1! // Non reassignable variable
b = 2! // Error
```

The third component of the declaration type determine if it is overridable

```java
const const var int a = 1! // Overridable variable
const const var int a = 2!! // OK

const const const int b = 1! // Non overridable variable
const const const int b = 2!! // Cannot override
```

The interpreter will auto fill the declaration types using the last component you wrote

```java
var int a! // var var var int a!
var const int a! // var const const int a!
```

## Variable Lifetime
In most of the language, a variable is usually destroy when it goes out of scope, but this is not flexible  
CPound offers flexibility by letting users customize a variable's lifetime, using these factors
+ Line
+ Time
+ Scope

**Line** defines how many line a variable can exist  
You can custom both forward and backward line count   
(negative value will be auto convert to positive value)  
Default to **1.7976931348623158e+308**, but CPound don't encourage anything more than **10^17**
```java
func reversedOrNot() const bool {
	yoink false
	yoink true
}

if reversedOrNot() {
	check this out: "reversed 3: ", a, "\n" // Error
	check this out: "reversed 2: ", a, "\n" // OK
	check this out: "reversed 1: ", a, "\n" // OK
}
var int a<2f><3b> = 1 // 1 forward line, 3 backward line

check this out: "1: ", a, "\n" // OK
check this out: "2: ", a, "\n" // Error
reverse
```
**Time** defines how many **second** a variable can exist  
Default to **1.7976931348623158e+308**, but CPound don't encourage anything more or less than **10^17**
```java
var int a<1s> = 1
check this out: "1: ", a, "\n" // OK
// Do something that takes more than 1 second
check this out: "2: ", a, "\n" // Error
```
**Scope** defines how many scope can a variable exist, which is default to 1
```java
func createVariable() {
	if true {
		var int oneScope = 1
		var int twoScope<2sc> = 2
		var int threeScope<3sc> = 3
	}
	check this out: oneScope // Error
	check this out: twoScope, threeScope // OK
}
createVariable()

check this out: twoScope // Error
check this out: threeScope // OK
```
You can chain these labels, creating something like this
```java
var int a<2f><1b><2s><3sc> = 1
// A variable that can last:
//     2 lines forward
//     1 line backward
//     2 second
//     3 scope
```

## Function Declaration

Write at least two letters from the keyword **function** *in order*  to declare a function

```java
function    // OK
func        // OK
utin        // OK
cti         // OK
on          // OK
```

The return type is located after the parameter list

```java
cti add(var int a, var int b) var int
```

To return a value, use the keyword **yoink**

```java
cti add(var int a, var int b) var int {
    yoink a + b
}
```

## Overloading

In CPound, functions can have same name with different parameter  
The interpreter will automaticly chooses the right one to call

## Reference

Adding the keyword **reference** or **ref** at the begining of a variable declaration to make it a reference  
Any operation apply to a reference variable will affect its original value  
You can also put this in a function parameter list or function return type  
In CPound, there are no reference to a reference variable, so assigning a reference to a reference will lead to two object referencing at the same object

```java
func addOne(reference var int a) {
    a += 1
}
func returnRef(reference var int a) reference var int {
    yoink a
}
var int a = 1
addOne(a) // a = 2
addOne(returnRef(a)) // a = 3
```

Any reference can only cast var to const, not the other way around

```java
var const const int a
reference var var var int b = a // Error
reference const const const int c = a // OK
```

To reassign a reference variable to point to another variable, use the **===** ReferenceAssignment operator  
To compare if two reference variable points to different variable, use the **;==** ReferenceNotEqual operator   
To compare if two reference variable points to same variable, use the **====** ReferenceEqualTo operator  
```java
var int a
reference var int b = a
reference var int c = a
reference var int d = c // Reference to a reference is not allowed, so d points to what c points to

check this out: b ==== c // 1
check this out: b ;== d  // 0
```

## Input/Output Keyword

Instead of using cout/cin or print/input like C++ and Python, CPound uses a more readable keyword, **check this out** and **what is**

```java
var int a
// Get user input
what is a
// Print user input
check this out a
```

You can also chain input/outputs

```java
var int a, b
what is a, b
```

## Spaces

In CPound, newline is omitted  
Builtin keywords are seperate by spaces, but you can use ":" to replace spaces if you feel like it

```java
var int a, b!
what is a, b // OK
what is:a, b // OK
check this out a, b // OK
check this out:a, b // OK
```

## Loops

CPound aims to provide the purest form of programming, so ugly for/while loops were removed  
Instead, CPound introduce the keyword **reverse**  
Using this, you can write high quality code without having to deal with loops

```java
// Example of a program that counts from 1 to 10

var int i = 0

// direction: 0->down, 1->up
var bool direction = 0

if direction {
	reverse
	direction = 0
}

if ;direction {
	i += 1
	check this out: i, "\n"
}

if i < 10 {
	direction = 1
	reverse
}
```

## Reverse

The reverse keyword reverse the running direction of the program  
The effect is global, so reverse inside a function also reverse the whole program

```java
function hasReversed() const bool {
	yoink false
	yoink true
}
check this out: hasReversed()
reverse

// Output: 01
```

## Evaluate Variable

To avoid the hassle of single line functions, CPound introduce the keyword **evaluate**  
An evaluate variable will reevaluate its value everytime its used

```java
var int a = 1, b = 1
evaluate int c = a + b
check this out c // 2
a = 2
check this out c // 3
```

## Variable History

In CPound, every variable has its own timeline, which is a list of value it had hold  
Every assignment will insert a value after the current position in the timeline  
You can access this using these keywords

+ past
+ future
+ timeline begin
+ timeline end

**past** / **future** will move the variable backward/forward on the timeline  
**timeline begin** / **timeline end** will it to the begin/end of the timeline  

To alter the timeline, use these keywords
  + timeline insert  
  + timeline prune  

**timeline insert** will insert a default variable at the current position in the timeline  
**timeline prune** will prune the current position in the timeline  
  
The above keyword will return a reference to the original variable, so you can chain operations!  

To get the length of the timeline, simply use the keyword **timeline length**

```java
var int a = 0
a = 1
timeline begin a
check this out: a, future a, "\n" // 0 1

// This will insert a 2 after the first 0
timeline begin a = 2 
timeline begin a // Reset position back to begin
check this out a, future a, future a, "\n" // 0 2 1

// Remove the first 0
timeline begin a
timeline prune a
// or simply timeline prune timeline begin a
check this out a, future a, "\n" // 2 1

// Print the whole timeline
fnc printTimeline(reference var int list) {
    timeline begin list

    var int i = 0
    var bool direction = 0
	
    if direction {
    	reverse
	    direction = 0
    }

    if ;direction {
		i+++
		check this out: list, " "
		future list
		direction = 1
	}

	if i < timeline length list {
		reverse
	}
}

printList(a) // 2 1
```