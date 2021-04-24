#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

float sigmoid(float value){
    return (1/(1+exp(-1*value)));
}

float leakyReLU(float value){
    return max((float)0.001*value, value);
}

//A function pointer is of the type <return type>(*<function pointer name>)(<parameter types>)

//Applies the passed function to each value in the input (values) vector and stores it in the passed result (res) vector
void forEach(const vector<float>& values, int n, float(*func)(float), vector<float>& res){
    for(int i=0; i<n ; i++){
        res[i] = func(values[i]);
    }
}

int main(){
    int n = 10;
    vector<float> values(n), sigmoid_res(n), leakyReLU_res(n);
    for(int i=0; i<n; i++){
        values[i]= (rand()%11) - 5; // generate random integers in range -5 to 5
    }
    forEach(values, n, sigmoid, sigmoid_res);       // pointwise calculation of leakyReLU and sigmoid
    forEach(values, n, leakyReLU, leakyReLU_res);   // by passing functions using function pointers

    //Print the original vector values and the computed values
    cout<<endl<<"Input Vector     : ";
    for(float val: values) printf("%+3.3f  ", val);

    cout<<endl<<"Sigmoid Values   : ";
    for(float val: sigmoid_res) printf("%+3.3f  ", val);

    cout<<endl<<"LeakyReLU Values : ";
    for(float val: leakyReLU_res) printf("%+3.3f  ", val);
    cout<<endl;
    
}