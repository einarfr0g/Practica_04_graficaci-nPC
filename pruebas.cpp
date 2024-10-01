#include "math.cpp"

int main(){
    Matrix3 mat1 = Matrix3(1.142,78.089,3.1416,2.44,1342.1342,0.123,7.5,-15,-3.1426);
    cout<<"La matriz1 entrada a00 = "<< to_string(mat1.a00) << " entrada a01 = "<< to_string(mat1.a01)<< " entrada a02 = "<< to_string(mat1.a02)<<"\n"
    << " entrada a10 = "<< to_string(mat1.a10)<< " entrada a11 = "<< to_string(mat1.a11)<< " entrada a12 = "<< to_string(mat1.a12)<<"\n"
    << " entrada a20 = "<< to_string(mat1.a20)<< " entrada a21 = "<< to_string(mat1.a21) << " entrada a22 = "<< to_string(mat1.a22)<<"\n";

    Matrix3 mat2 = Matrix3(1,2,3,4,5,6,7,8,9);

    cout<<"La matriz2 entrada a00 = "<< to_string(mat2.a00) << " entrada a01 = "<< to_string(mat2.a01)<< " entrada a02 = "<< to_string(mat2.a02)<<"\n"
    << " entrada a10 = "<< to_string(mat2.a10)<< " entrada a11 = "<< to_string(mat2.a11)<< " entrada a12 = "<< to_string(mat2.a12)<<"\n"
    << " entrada a20 = "<< to_string(mat2.a20)<< " entrada a21 = "<< to_string(mat2.a21) << " entrada a22 = "<< to_string(mat2.a22)<<"\n";

    cout<<"El determinante de la matriz es: "<<to_string(mat1.determinant())<<"\n";

    //Matrix3 mat3 = mat1.adjoint(); 

    //cout<<"La matriz3 entrada a00 = "<< to_string(mat3.a00) << " entrada a01 = "<< to_string(mat3.a01)<< " entrada a02 = "<< to_string(mat3.a02)<<"\n"
    //<< " entrada a10 = "<< to_string(mat3.a10)<< " entrada a11 = "<< to_string(mat3.a11)<< " entrada a12 = "<< to_string(mat3.a12)<<"\n"
    //<< " entrada a20 = "<< to_string(mat3.a20)<< " entrada a21 = "<< to_string(mat3.a21) << " entrada a22 = "<< to_string(mat3.a22)<<"\n";

}