#include <iostream>

float **Multiplicar(float **, float **, int, int, int, int);
void mostrarMatriz(float **, int, int);
void fillMatrix(float**, int);
float **Cauchy1(int,int);
float **Cauchy2(int,int);

int main(int argc, char **argv){
    int N = atoi(argv[1]);
    std::cout.precision(16);
    std::cout.setf(std::ios::scientific);
    
    float **CauchyM1 = Cauchy1(5,3);
    float **CauchyM2 = Cauchy2(3,4);
    
    std::cout<<"Matriz de Cauchy 1:"<<std::endl;
    mostrarMatriz(CauchyM1, 5, 3);
    std::cout<<"Matriz de Cauchy 2:"<<std::endl;
    mostrarMatriz(CauchyM2, 3, 4);
    std::cout<<"Producto de matrices:"<<std::endl;
    float **Product = Multiplicar(CauchyM1, CauchyM2, 5, 3, 3, 4);
    mostrarMatriz(Product, 5, 4);
    
    //Delete cauchy matrix
    for(int i=0;i<5;i++){
        delete[] CauchyM1[i];
        delete[] Product[i];
    }
    for(int i=0;i<3;i++){
        delete[] CauchyM2[i];
    }
    delete[] CauchyM1;
    delete[] Product;
    delete[] CauchyM2;
    //-------------------
    
    std::cout<<"Parte 2. Test Nilpotent"<<std::endl;
    float **M = new float*[N];
    for(int i=0;i<N;i++){
        M[i] = new float[N];
    }
    
    fillMatrix(M,N);
    std::cout<<"\n";
    std::cout<<"Matriz rellenada:"<<"\n";
    mostrarMatriz(M,N,N);
    std::cout<<"\n";
    std::cout<<"Se potencia la matriz anterior a la k"<<std::endl;
    float **Mmult = Multiplicar(M,M,N,N,N,N);
    std::cout<<"k="<<2<<"\n";
    mostrarMatriz(Mmult,N,N);
    for(int i=3;i<10;i++){
        std::cout<<"k="<<i<<"\n";
        Mmult = Multiplicar(Mmult,M,N,N,N,N);
        mostrarMatriz(Mmult,N,N);
    }
    
    
    //Delete matrix
    for(int i=0;i<N;i++){
        delete[] Mmult[i];
        delete[] M[i];
    }
    delete[] Mmult;
    delete[] M;
    return 0;
}


float **Multiplicar(float **MatrizA, float **MatrizB, int filasA, int filasB, int colA, int colB){
    
    float **resp = new float*[filasA];
    for(int i=0;i<filasA;i++){
        resp[i] = new float[colB];
    }
    
    for(int i=0;i<filasA;i++){
        for(int j=0;j<colB;j++){
            for(int k=0;k<filasB;k++){
                *(*(resp+i)+j) += *(*(MatrizA+i)+k) * *(*(MatrizB+k)+j);
            }
        }
    }
    
    return resp;
}

void fillMatrix(float** Matrix, int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if( j== N-1){
                if(i==0){
                    *(*(Matrix+i)+j)=1-N;
                }
                else{
                    *(*(Matrix+i)+j)=-N;
                }
            }
            else if(i==0){
                *(*(Matrix+i)+j)=2;
            }
            else if(i==(j+1)){
                *(*(Matrix+i)+j)=N+2;
            }
            else{
                *(*(Matrix+i)+j)=1;
            }
        }
    }
}

void mostrarMatriz(float **Matriz, int filas, int col){
    for(int i=0;i<filas;i++){
        for(int j=0;j<col;j++){
            std::cout<<*(*(Matriz+i)+j)<<"\t";
            
        }
        std::cout<<std::endl;
    }
}


float **Cauchy1(int n, int m){
    float **Matrix = new float*[n];
    for(int i=0;i<n;i++){
        Matrix[i] = new float[m];
        for(int j=0;j<m;j++){
            *(*(Matrix+i)+j) = 1/(i + j + 1.0);
        }
    }
    return Matrix;
}

float **Cauchy2(int n, int m){
    float **Matrix = new float*[n];
    for(int i=0;i<n;i++){
        Matrix[i] = new float[m];
        for(int j=0;j<m;j++){
            *(*(Matrix+i)+j) = 1/(2*i + j + 1.0);
        }
    }
    return Matrix;
}