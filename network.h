#ifndef network.h
#define network.h
#define inputLayer 2
#define hiddenLayer 3
#define outputLayer 1
void initialize_weights_and_biases();
void feedforward(float input[]);
void backpropagate(float input[], float target[], float learningRate);
void train(float inputs[][inputLayer], float targets[][outputLayer], int numSamples, int epochs, float learningRate);
void test(float input[]);
#endif
