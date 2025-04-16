#ifndef NETWORK_H
#define NETWORK_H
#define INPUT_LAYER 2
#define HIDDEN_LAYER 3
#define OUTPUT_LAYER 1

void initialize_weights_and_biases();
void feedforward(float input[]);
void backpropagate(float input[], float target[], float learning_rate);
void train(float inputs[][INPUT_LAYER], float targets[][OUTPUT_LAYER], int num_samples, int epochs, float learning_rate);
void test(float input[]);

#endif
