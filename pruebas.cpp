#include "math.cpp"

int main(){

    Matrix4 mat1 = Matrix4(1,2,3,4,5,6,7,8,9,10,-11,12,13,14,15,16);

    cout<<" entrada a00 = "<< to_string(mat1.a00)<< " entrada a01 = "<< to_string(mat1.a01)<< " entrada a02 = "<< to_string(mat1.a02)<<" entrada a02 = "<<to_string(mat1.a03)<<"\n"
                 << " entrada a10 = "<< to_string(mat1.a10)<< " entrada a11 = "<< to_string(mat1.a11)<< " entrada a12 = "<< to_string(mat1.a12)<<" entrada a12 = "<<to_string(mat1.a13)<<"\n"
                 << " entrada a20 = "<< to_string(mat1.a20)<< " entrada a21 = "<< to_string(mat1.a21)<< " entrada a22 = "<< to_string(mat1.a22)<<" entrada a22 = "<<to_string(mat1.a23)<<"\n"
                 << " entrada a20 = "<< to_string(mat1.a30)<< " entrada a21 = "<< to_string(mat1.a31)<< " entrada a22 = "<< to_string(mat1.a32)<<" entrada a22 = "<<to_string(mat1.a33)<<"\n";
    
    Matrix4 mat2 = Matrix4(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16);

    cout<<"\n"<<"\n"<<"\n";

    Matrix4 mat3 = mat1.adjoint();

    cout<<" entrada a00 = "<< to_string(mat3.a00)<< " entrada a01 = "<< to_string(mat3.a01)<< " entrada a02 = "<< to_string(mat3.a02)<<" entrada a02 = "<<to_string(mat3.a03)<<"\n"
        <<" entrada a10 = "<< to_string(mat3.a10)<< " entrada a11 = "<< to_string(mat3.a11)<< " entrada a12 = "<< to_string(mat3.a12)<<" entrada a12 = "<<to_string(mat3.a13)<<"\n"
        <<" entrada a20 = "<< to_string(mat3.a20)<< " entrada a21 = "<< to_string(mat3.a21)<< " entrada a22 = "<< to_string(mat3.a22)<<" entrada a22 = "<<to_string(mat3.a23)<<"\n"
        <<" entrada a20 = "<< to_string(mat3.a30)<< " entrada a21 = "<< to_string(mat3.a31)<< " entrada a22 = "<< to_string(mat3.a32)<<" entrada a22 = "<<to_string(mat3.a33)<<"\n";




}