#include "math.cpp"

int main(){

    Matrix4 mat1 = Matrix4(-1,2,3,-4,5,-6,20,8,9.8,10,-11,12,13,14,-150.39,16);

    cout<<" entrada a00 = "<< to_string(mat1.a00)<< " entrada a01 = "<< to_string(mat1.a01)<< " entrada a02 = "<< to_string(mat1.a02)<<" entrada a02 = "<<to_string(mat1.a03)<<"\n"
                 << " entrada a10 = "<< to_string(mat1.a10)<< " entrada a11 = "<< to_string(mat1.a11)<< " entrada a12 = "<< to_string(mat1.a12)<<" entrada a12 = "<<to_string(mat1.a13)<<"\n"
                 << " entrada a20 = "<< to_string(mat1.a20)<< " entrada a21 = "<< to_string(mat1.a21)<< " entrada a22 = "<< to_string(mat1.a22)<<" entrada a22 = "<<to_string(mat1.a23)<<"\n"
                 << " entrada a20 = "<< to_string(mat1.a30)<< " entrada a21 = "<< to_string(mat1.a31)<< " entrada a22 = "<< to_string(mat1.a32)<<" entrada a22 = "<<to_string(mat1.a33)<<"\n";
    //0.0000001,0.0000001,0.0000001,0.0000001,
    Matrix4 mat2 = mat1.multiplyByScalar(2.5);



    cout<<"\n"<<"\n"<<"\n";

    Matrix4 mat3 = Matrix4::add(mat1,mat2);

    cout<<" entrada a00 = "<< to_string(mat2.a00)<< " entrada a01 = "<< to_string(mat2.a01)<< " entrada a02 = "<< to_string(mat2.a02)<<" entrada a03 = "<<to_string(mat2.a03)<<"\n"
        <<" entrada a10 = "<< to_string(mat2.a10)<< " entrada a11 = "<< to_string(mat2.a11)<< " entrada a12 = "<< to_string(mat2.a12)<<" entrada a13 = "<<to_string(mat2.a13)<<"\n"
        <<" entrada a20 = "<< to_string(mat2.a20)<< " entrada a21 = "<< to_string(mat2.a21)<< " entrada a22 = "<< to_string(mat2.a22)<<" entrada a23 = "<<to_string(mat2.a23)<<"\n"
        <<" entrada a30 = "<< to_string(mat2.a30)<< " entrada a31 = "<< to_string(mat2.a31)<< " entrada a32 = "<< to_string(mat2.a32)<<" entrada a33 = "<<to_string(mat2.a33)<<"\n";

    cout<<"las matrices son iguales?: "<< to_string(Matrix4::equalsWithE(mat1,mat3)) << "\n";




}