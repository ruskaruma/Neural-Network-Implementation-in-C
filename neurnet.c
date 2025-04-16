#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"neurnet.h"

float weights1[inputLayer][hiddenLayer];
float weights2[hiddenLayer][outputLayer];
float bias1[hiddenLayer];
float bias2[outputLayer];
float activations1[hiddenLayer];
float activations2[outputLayer];
float sigmoid(float x)
{
    return 1.0/(1.0+exp(-x));
}

float sigmoid_derivative(float x)
{
    return x*(1-x);
}
void initialize_weights_and_biases()
{
    //this function initialises weights and biases randomly
    for(int i=0;i<inputLayer;i++)
    {
        for(int j=0;j<hiddenLayer;j++)
        {
            weights1[i][j]=((float)rand()/RAND_MAX)*2-1; //for random values between -1 and 1
        }
    }
    for(int i=0;i<hiddenLayer;i++)
    {
        for (int j=0;j<outputLayer;j++)
        {
            weights2[i][j]=((float)rand()/RAND_MAX)*2-1;//for random values between -1 and 1
        }
    }
    for(int i=0;i<hiddenLayer;i++)
    {
        bias1[i]=((float)rand()/RAND_MAX)*2-1;
    }
    for (int i=0;i<outputLayer;i++)
    {
        bias2[i]=((float)rand()/RAND_MAX)*2-1;
    }
}
void feedforward(float input[]) {
    //loop for input to hidden layer
    for (int i=0;i<hiddenLayer;i++) {
        activations1[i]=0;
        for(int j=0;j<inputLayer; j++)
        {
            activations1[i]+=input[j]*weights1[j][i];
        }
        activations1[i]+=bias1[i];
        activations1[i]=sigmoid(activations1[i]);
    }
    //loop for hidden to ouyput layer
    for(int i=0;i<outputLayer;i++)
    {
        activations2[i]=0;
        for(int j=0;j<hiddenLayer;j++)
        {
            activations2[i]+=activations1[j]*weights2[j][i];
        }
        activations2[i]+=bias2[i];
        activations2[i]=sigmoid(activations2[i]);
    }
}
void backpropagate(float input[], float target[], float learningRate)
{
    float output_errors[outputLayer];
    for (int i=0;i<outputLayer;i++)
    {
        output_errors[i]=target[i]-activations2[i];
    }
    float hidden_errors[hiddenLayer];
    for (int i=0;i< hiddenLayer; i++) {
        hidden_errors[i]=0;
        for (int j=0;j<outputLayer;j++)
        {
            hidden_errors[i]+=output_errors[j]*weights2[i][j]*sigmoid_derivative(activations1[i]);
        }
    }

    // updating weights and biases
    for(int i=0;i<hiddenLayer;i++){
        for (int j=0;j<outputLayer;j++)
        {
            weights2[i][j]+=learningRate*output_errors[j]*activations1[i];
        }
    }
    for(int i=0;i<outputLayer;i++){
        bias2[i]+=learningRate*output_errors[i];
    }
    for(int i=0;i<inputLayer;i++)
    {
        for(int j=0;j<hiddenLayer;j++) {
            weights1[i][j]+=learningRate*hidden_errors[j]*input[i];
        }
    }
    for(int i=0;i<hiddenLayer;i++){
        bias1[i]+=learningRate*hidden_errors[i];
    }
}
void train(float inputs[][inputLayer], float targets[][outputLayer], int num_samples, int epochs, float learningRate)
{
    for(int epoch=0;epoch<epochs;epoch++)
    {
        for(int i=0;i<num_samples;i++)
        {
            feedforward(inputs[i]);
            backpropagate(inputs[i],targets[i],learningRate);
        }
        printf("Epoch %d completed\n",epoch);
    }
}
void test(float input[])
{
    feedforward(input);
    for(int i=0;i<outputLayer;i++)
    {
        printf("Output:%f\n",activations2[i]);
    }
}
