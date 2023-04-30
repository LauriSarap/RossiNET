# XOR Problem
This is my attempt to solve the XOR problem with a neural network created in C++ without any external libraries.
The neural network has one hidden layer with two neurons.

## What is the XOR problem?
XOR problem (exclusive or) is a problem where the output is true only if one of the inputs is true. XOR problem can only be solved
with at least two neurons and its solution is non-linear.
```
0 and 0 outputs 0
```
```
0 and 1 outputs 1
```
```
1 and 0 outputs 1
```
```
1 and 1 outputs 0
```
## Solution
The solution is a neural network with one hidden layer with two neurons. The neural network is trained with backpropagation and
gradient descent. The activation function is sigmoid function. Delta values are found with Sigmoid's derivative.

## Usage
* Clone the repository.
* Compile and run the program.
* Use the commands below to interact with the program:
* n: Initialize a new neural network with random weights and biases.
* t: Train the neural network using the XOR problem's input-output pairs. You can change learning rate and epochs in the code.
* u: Use the trained neural network to predict the outputs for all possible XOR inputs.
* i: Display the current weights and biases of the neural network.