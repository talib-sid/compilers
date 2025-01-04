# Lecture 1: Representing Programs

**Date:** 12th December, 2024

## Table of Contents
1. [Introduction](#introduction)
2. [Key Concepts](#key-concepts)
3. [Examples](#examples)
4. [Summary](#summary)
5. [References](#references)

## Introduction
- Difference between Concrete Syntax and Abstract Syntax (Trees).
- Why the need for ASTs?
- ASTs are used to represent the structure of a program, in a similar way as to which the programmer had originally written it as
-  It's also good to make Compilers and Interpreters which recursively traverse the AST Nodes to figure out the structure of the program.
- Although, in the AST representation like the below
```c
if (x < y)
{
  print("less");
}
else
{
  return 0;
}
```
![image](/imgs/img1.png)

Here we can see that, although if we process each node recursively and with a well defined grammar and language semantics, we will be able to extract a high level understanding of what is going on in this program 

But one major drawback of using AST representation is that each node here is that children of each node means different things in different contexts.

For example, the children of the `if` node are the condition and the block of statements that are to be executed if the condition is true. But the children of the `else` node are the block of statements that are to be executed if the condition is false.\
\
 So, the children of the `if` and `else` nodes mean different things in different contexts. \
This is a major drawback of using ASTs to represent programs.

![image](/imgs/img2.png)

## Key Concepts
- **Concept 1:** [Description]
- **Concept 2:** [Description]
- **Concept 3:** [Description]

## Examples
[Include any relevant examples discussed during the lecture.]

## Summary
[Summarize the key points covered in the lecture.]

## References